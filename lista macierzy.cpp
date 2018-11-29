#include<iostream>
#include "macierze.cpp"

using namespace std;
template <class T>
class lista;

template <class T>
class element;

template<class T>
istream & operator >> (istream &s1, lista<T> &o1)
{
    element<T> *nowy;
    nowy = new element<T>;
    nowy->next=NULL;
    s1>>nowy->data;

    if(o1.head==NULL)
    {
        o1.head=nowy;
    }
    else
    {
        element<T> *nowy2=o1.head;
        while(nowy2->next!=NULL)
        {
            nowy2=nowy2->next;
        }
        nowy2->next=nowy;
    }
    return s1;

}
template <class T>
ostream & operator << (ostream &s1, lista<T> &o1)
{
    if(o1.head!=NULL)
    {
        element<T> *n=o1.head;
        while(n!=NULL)
        {
            cout<<n->data;
            n=n->next;
        }
    }
    return s1;
}

template <class T>
class element
{
    friend class lista<T>;
    friend istream & operator>> <T>(istream &s1, lista<T> &o1);
    friend ostream & operator<< <T>(ostream &s1, lista<T> &o1);
    T data;
    element <T>*next;

public:
    element()
    {
        next=NULL;
    }

};

template <class T>
class lista
{
    friend istream & operator>> <T>(istream &s1, lista<T> &o1);
    friend ostream & operator<< <T>(ostream &s1, lista<T> &o1);
    friend class element<T>;

    element <T> *head;

public:
    lista()
    {
        head=NULL;
    }
    lista(lista<T> &o1)
    {
        if(o1.head!=NULL)
        {
            element<T> *nowy;
            nowy=new element<T>;
            nowy->data=o1.head->data;
            nowy->next=NULL;
            head=nowy;
            element<T> *tmp=o1.head;
            element<T> *tmp2=head;
            while(tmp->next!=NULL)
            {
                element<T> *nowy=new element<T>;
                nowy->data=tmp->next->data;
                tmp2->next=nowy;
                tmp=tmp->next;
                tmp2=tmp2->next;
            }
            tmp2->next=NULL;
        }

    }
    ~lista()
    {
        element<T> *tmp;
        while(head!=NULL)
        {
            tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    lista &operator = (const lista<T> &o1)
    {
        if(this==&o1)return *this;
        element<T> *n;
        while(this->head!=NULL)
        {
            n=this->head;
            this->head=this->head->next;
            delete n;
        }

        element<T> *tmp;
        this->head=NULL;
        tmp = new element<T>;
        this->head=tmp;
        element<T> *tmp2  = o1.head;
        tmp->data=tmp2->data;
        while(tmp2->next!=NULL)
        {
            element<T> *nowy=new element<T>;
            nowy->data=tmp2->next->data;
            tmp->next=nowy;
            tmp2=tmp2->next;
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return *this;
    }
    lista <T> operator + (lista<T> &p1)
    {
        if(p1.head==NULL)
        {
            return *this;
        }

        if(this->head==NULL)
        {
            return p1;
        }

        lista<T> *wynik1,*wynik2;
        wynik1=new lista<T>;
        wynik2=new lista<T>;
        *wynik1=*this;
        *wynik2=p1;
        element<T> *tmp=wynik1->head;
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=wynik2->head;
        return *wynik1;
    }
    bool operator == (lista<T> &o1)
    {
        int a=0;
        element<T> *tmpA=new element<T>;
        element<T> *tmpB=new element<T>;
        tmpA=this->head;
        tmpB=o1.head;
        if((this->head==NULL && o1.head!=NULL) || (this->head!=NULL && o1.head==NULL) )
        {
            return false;
        }
        else
        {
            while(tmpA!=NULL && tmpB!=NULL)
            {
                if(tmpA->data!=tmpB->data)
                {
                    a=a+1;
                }
                tmpB=tmpB->next;
                tmpA=tmpA->next;
            }
            if(tmpA==NULL && tmpB!=NULL || tmpA!=NULL && tmpB==NULL)
            {
                a=a+1;
            }
        }

        if(a==0) return true;
        else return false;

    }
    bool operator != (lista<T> &o1)
    {
        int a=0;
        element<T> *tmpA=new element<T>;
        element<T> *tmpB=new element<T>;
        tmpA=this->head;
        tmpB=o1.head;
        if((this->head==NULL && o1.head!=NULL) || (this->head!=NULL && o1.head==NULL) )
        {
            return false;
        }
        else
        {
            while(tmpA!=NULL && tmpB!=NULL)
            {
                if(tmpA->data!=tmpB->data)
                {
                    a=a+1;
                }
                tmpB=tmpB->next;
                tmpA=tmpA->next;
            }
            if(tmpA==NULL && tmpB!=NULL || tmpA!=NULL && tmpB==NULL)
            {
                a=a+1;
            }
        }

        if(a==0)return true;
        else return false;

    }
    bool operator > (lista<T> &o1)
    {
        element<T> *tmpA=new element<T>;
        element<T> *tmpB=new element<T>;
        tmpA=this->head;
        tmpB=o1.head;
        while(tmpA->next!=NULL && tmpB->next!=NULL)
        {
            tmpB=tmpB->next;
            tmpA=tmpA->next;
        }
        if(tmpA->next!=NULL && tmpB->next==NULL || tmpA->next==NULL && tmpB->next==NULL)
        {
            return true;
        }
        else return false;

    }
    bool operator < (lista<T> &o1)
    {
        element<T> *tmpA=new element<T>;
        element<T> *tmpB=new element<T>;
        tmpA=this->head;
        tmpB=o1.head;
        while(tmpA->next!=NULL && tmpB->next!=NULL)
        {
            tmpB=tmpB->next;
            tmpA=tmpA->next;
        }
        if(tmpA->next!=NULL && tmpB->next==NULL || tmpA->next==NULL && tmpB->next==NULL)
        {
            return false;
        }
        else return true;

    }
};



int main()
{
   /* lista <string> a,b,c;
    cin>>a>>a;
    cin>>b;
    c=a+b;
    cout<<c;
    */
    macierze d,e,f;
    cin>>d;
    cin>>e;
    f=d+e;
    cout<<f;
    macierze g(d);
    cout<<g;
    return 0;
}
