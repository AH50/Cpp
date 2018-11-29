#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


/*class  klasa1{
        public:
        int a,b;
        double c;
        int fun(int z){ return z*c;};
};*/

class  czas{
        int godz,min,sek;
        public:
        void zapamietaj_czas(int godzina,int minuta, int sekunda)
        {
                godz=godzina;
                min=minuta;
                sek=sekunda;
        };
        void zapamietaj_czas(char *cz)
        {
                sscanf(cz,"%d:%d:%d",&godz,&min,&sek);
        };
        void zwroc_czas(int &g,int &m,int &s)
        {
                g=godz;
                m=min;
                s=sek;
        };
        void zwroc_czas(char *cz)
        {
                sprintf(cz,"%d:%d:%d",godz,min,sek);
        };
};

int main()
{
        int zm,a,b,c;
        char text[10];

        /*class klasa1 a1;
        a1.c=5;
        zm=a1.fun(3);
        cout<<zm<<endl;*/

        class czas o1;
        o1.zapamietaj_czas(12,15,19);

        o1.zwroc_czas(a,b,c);
        cout<<a<<":"<<b<<":"<<c<<endl;

        o1.zapamietaj_czas((char*)"15:15:15");
        o1.zwroc_czas(text);
        cout<<text<<endl;
return 0;
}
