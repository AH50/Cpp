#include <iostream>

using std::string;
using std::endl;
using std::cout;

template <class Key,class Value>
class mapa;

template <class Key,class Value>
class element
{
    friend class mapa<Key,Value>;
    Key pierwszy;
    Value drugi;
    element<Key,Value> *next;
};

template <class Key,class Value>
class mapa
{
    element<Key,Value> *first;
public:
    mapa()
    {
        first=NULL;
    }
    ~mapa()
    {
        element<Key,Value>* tmp = first;
        element<Key,Value>* del;
        while (tmp != NULL)
            {
            del = tmp;
            tmp = tmp->next;
            delete del;
            }
        first = NULL;
}
    class iterator
    {
        friend class mapa<Key,Value>;
        element<Key,Value> *wsk;
    public:
        iterator()
        {
            wsk=NULL;
        }
        bool operator!=(const iterator &o1)
        {
            if(wsk!=o1.wsk)return 1;
            return 0;
        }
        iterator & operator ++ (int)
        {
            wsk=wsk->next;
            return *this;
        }
        element<Key,Value> * operator->(void)
        {
            return wsk;
        }

    };
    iterator begin(void)
    {
        iterator it;
        it.wsk=first;
        return it;
    }
    iterator end(void)
    {
        iterator it;
        it.wsk=NULL;
        return it;
    }
    Value & operator[](const Key &o1)
    {
        element<Key,Value> *w, *wp, *wn;
        for(w=first,wp=0;w!=0 && w->pierwszy<=o1;w=w->next)
        {
            if(w->pierwszy==o1)return w->drugi;
            wp=w;
        }
        wn=new element<Key,Value>;
        wn->pierwszy=o1;
        if(wp==0)
        {
            first = wn;
            wn->next=w;
        }
        else {
            wn->next=wp->next;
            wp->next = wn;
        }
        return wn->drugi;
    }
    void wypisz()
    {
        for(mapa<Key,Value>::iterator i=begin();i!=end();i++)
        {
            cout<<i->pierwszy<<" "<<i->drugi<<endl;
        }
    }
};

int main()
{
    mapa<int,string> map1;
    map1[2]="hello";
    map1[1]="word";
    map1[3]="!!!";
    map1.wypisz();
    return 0;
}
