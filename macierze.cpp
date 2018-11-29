#include<iostream>

using namespace std;

template <class T>
class para
{
public:
    T x,y;

    para <T> & operator = (para<T> & o1)
    {
        x=o1.x;
        y=o1.y;
        return *this;
    }
    para <T> & operator + (para<T> &o1)
    {
        para <T> *wynik;
        wynik=new para <T>;
        wynik->x=o1.x+this->x;
        wynik->y=o1.y+this->y;
        return *wynik;
    }
};

template <class T>
istream & operator>>(istream &s, para<T> & o1)
{
    s>>o1.x>>o1.y;
    return s;
}

template <class T>
ostream & operator<<(ostream &s, para<T> & o1)
{
    s<<"1:\n"<<o1.x<<"\n2:\n"<<o1.y<<endl;
    return s;
}

class macierze
{
    friend istream & operator>>(istream &s1, macierze &o1);
    friend ostream & operator<<(ostream &s1, macierze &o1);

    double *ws;
    int wymiar;
public:
    macierze()
    {
        ws = NULL;
        wymiar = 0;
    }
    macierze(int wym)
    {
        wymiar = wym;
        this->ws = new double [wymiar*wymiar];
        for(int i=0; i<wymiar*wymiar; i++)
        {
            this->ws[i]=0;
        }
    }
    macierze(macierze &o1)
    {
        ws = new double [o1.wymiar * o1.wymiar];
        wymiar = o1.wymiar;
        for(int i=0; i<o1.wymiar*o1.wymiar; i++)
        {
            ws[i]=o1.ws[i];
        }
    }
    ~macierze()
    {
        if(ws!=NULL)
        {
            delete [] ws;
            ws = NULL;
        }
    }
    macierze &operator = (const macierze &o1)
    {
        if (this==&o1)return *this;

        delete[] this->ws;
        this->ws=new double[o1.wymiar*o1.wymiar];
        this->wymiar=o1.wymiar;
        for(int i=0; i<o1.wymiar*o1.wymiar; i++)
        {
            this->ws[i]=o1.ws[i];
        }
        return *this;
    }
    macierze operator + (macierze &p2)
    {

        if(p2.wymiar!=this->wymiar)
        {
            cout<<"blad";
            return p2;
        }
        else
        {
            macierze wynik;
            wynik.wymiar=p2.wymiar;
            wynik.ws=new double[wynik.wymiar*wynik.wymiar];

            for(int i=0; i<p2.wymiar*p2.wymiar; i++)
            {
                wynik.ws[i]=this->ws[i] + p2.ws[i];
            }

            return wynik;
        }
    }
    macierze operator - (macierze &p3)
    {
        if(p3.wymiar!=this->wymiar)
        {
            cout<<"blad";
            return p3;
        }
        else
        {
            macierze wynik;
            wynik.wymiar=p3.wymiar;
            wynik.ws=new double[wynik.wymiar*wynik.wymiar];

            for(int i=0; i<p3.wymiar*p3.wymiar; i++)
            {
                wynik.ws[i]=this->ws[i] - p3.ws[i];
            }

            return wynik;
        }
    }
    bool operator == (macierze &p4)
    {
        int pom;
        for(int i=0; i<p4.wymiar*p4.wymiar; i++)
        {
            if (this->ws[i] != p4.ws[i])
            {
                pom++;
            }
        }
        if (pom==0)return true;
        else return false;
    }
    bool operator != (macierze &p5)
    {
        int pom;
        for(int i=0; i<p5.wymiar*p5.wymiar; i++)
        {
            if (this->ws[i] != p5.ws[i])
            {
                pom++;
            }
        }
        if (pom==0)return true;
        else return false;
    }
    bool operator < (macierze &p6)
    {
        double pom1,pom2;
        for(int i=0; i<p6.wymiar*p6.wymiar; i++)
        {
            pom1=pom1+p6.ws[i];
            pom2=pom2+this->ws[i];
        }
        if (pom1>pom2)return true;
        else return false;
    }
    bool operator > (macierze &p7)
    {
        double pom1,pom2;
        for(int i=0; i<p7.wymiar*p7.wymiar; i++)
        {
            pom1=pom1+p7.ws[i];
            pom2=pom2+this->ws[i];
        }
        if (pom1<pom2)return true;
        else return false;
    }
    macierze operator * (const macierze &p8)
    {

        macierze wynik;

        wynik.wymiar = p8.wymiar;
        wynik.ws = new double[wynik.wymiar * wynik.wymiar];

        int suma, a;

        for(int x=0; x < this->wymiar*this->wymiar; x+=this->wymiar)
        {
            for(int y=0; y < this->wymiar; y++)
            {
                suma = 0;
                a = y;
                for(int z=x; z < this->wymiar+x; z++)
                {
                    suma += this->ws[z]*p8.ws[a];
                    a+=this->wymiar;
                }
                wynik.ws[x+y] = suma;
            }
        }
        return wynik;
    }
};

istream & operator>>(istream &s1, macierze &o1)
{
    if(o1.ws!=NULL)
    {
        delete [] o1.ws;
        o1.ws = NULL;
    }
    s1>>o1.wymiar;
    if(o1.wymiar<1)
    {
        o1.wymiar = 0;
    }
    o1.ws = new double [o1.wymiar * o1.wymiar];
    for(int i=0; i<o1.wymiar*o1.wymiar; i++)
    {
        s1>>o1.ws[i];
    }
    return s1;
}
ostream & operator<<(ostream &s1, macierze &o1)
{
    if(o1.ws!=NULL)
    {
        for(int i=0; i<o1.wymiar*o1.wymiar; i++)
        {
            if(i%o1.wymiar==0 && i!=0)s1<<endl;
            s1<<o1.ws[i];
        }
    }
    s1<<endl;
    return s1;
}
/*
int main()
{
    para <int> a,b,c;
    cin>>a>>b;
    c=a+b;
    cout<<c;


    para <macierze> d,e,f;
    cin>>e>>f;
    d=e+f;
    cout<<d;

    return 0;
}
*/
