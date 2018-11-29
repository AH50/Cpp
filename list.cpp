#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class lista;

class element
{
    friend istream & operator>>(istream &s1, lista &o1);
    friend ostream & operator<<(ostream &s1, lista &o1);
    friend class lista;
    element *next;
    int data;
public:
    element()
    {
        data = 0;
        next=NULL;
    }

};

class lista
{
    friend istream & operator>>(istream &s1, lista &o1);
    friend ostream & operator<<(ostream &s1, lista &o1);
    friend class element;
    element *head;
public:
    lista()
    {
        head=NULL;
    }
    ~lista()
    {
        element *n;
        while(head!=NULL)
        {
            n=head;
            head=head->next;
            delete n;
        }
    }
    lista &operator = (const lista &o1)
    {
        element *tmp;
        this->head=NULL;
        tmp = new element;
        this->head=tmp;
        element *tmp2  = o1.head;
        tmp->data=tmp2->data;
        while(tmp2->next!=NULL)
        {
            element *nowy=new element;
            nowy->data=tmp2->next->data;
            tmp->next=nowy;
            tmp2=tmp2->next;
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return *this;
    }
    bool operator == (lista &o1)
    {
        int a=0;
        element *tmpA=new element;
        element *tmpB=new element;
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
    bool operator != (lista &o1)
    {
        int a=0;
        element *tmpA=new element;
        element *tmpB=new element;
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
    bool operator > (lista &o1)
    {
        element *tmpA=new element;
        element *tmpB=new element;
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
    bool operator < (lista &o1)
    {
        element *tmpA=new element;
        element *tmpB=new element;
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
    lista &operator + (lista &p1)
    {
        if(p1.head==NULL)
        {
            return *this;
        }

        if(this->head==NULL)
        {
            return p1;
        }
        lista *wynik;
        wynik->head=NULL;
        wynik = new lista;

        element *tmpAB;
        tmpAB=this->head;
        element *nowyAB=new element;
        wynik->head=nowyAB;
        nowyAB->data=this->head->data;

        while(tmpAB->next!=NULL)//lecimy po liscie A
        {
            element *nowy = new element;
            nowy->data=tmpAB->next->data;
            nowyAB->next=nowy;
            tmpAB=tmpAB->next;
            nowyAB=nowyAB->next;

        }

        element *nowy = new element;
        tmpAB=p1.head;
        nowy->data=tmpAB->data;
        nowyAB->next=nowy;
        nowyAB=nowyAB->next;


        while(tmpAB->next!=NULL)//lecimy po liscie B
        {
            element *nowy = new element;
            nowy->data=tmpAB->next->data;
            nowyAB->next=nowy;
            tmpAB=tmpAB->next;
            nowyAB=nowyAB->next;

        }

        nowyAB->next=NULL;
        return *wynik;
    }

};
istream & operator >> (istream &s1, lista &o1)
{
    element *nowy;
    nowy = new element;
    nowy->next=NULL;
    s1>>nowy->data;
    if(o1.head==NULL)
    {
        o1.head=nowy;
    }
    else
    {
        element *n=o1.head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=nowy;
    }
    return s1;

}
ostream & operator <<(ostream &s1, lista &o1)
{
    if(o1.head!=NULL)
    {
        element *n=o1.head;
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
    }
    return s1;
}

int main()
{
    lista a,b,c;
    /*
    lista a,b,c;
    cin>>b>>b>>b;
    c=a+b;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cin>>b>>b>>b;
    cout<<"c: "<<c<<endl;
    cin>>c>>c>>c;
    cout<<"c: "<<c<<endl;
    cout<<"b: "<<b<<endl;
    */
    cin>>a>>a>>a;
    cin>>b>>b>>b;
    c=a+b;
    cout<<c;

    /*
    a<b;
    a>b;
    a==b;
    a!=b;
    c=a+b;
    cout<<c;
    */
    return 0;
}
