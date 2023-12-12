//10.Să se calculeze media aritmetică a elementelor dintr-o coadă.
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *l;
int n;

nod* inserare(int info, nod *l)
{
    nod *aux1;
    if(l==NULL)
    {
        l=new nod;
        l->info=info;
        l->next=NULL;
        return l;
    }
    else
        {
            aux1=new nod;
            aux1->info=info;
            nod *aux2;
            aux2=l;
            while(l->next!=NULL)
                l=l->next;
            l->next=aux1;
            aux1->next=NULL;
            return aux2;
        }
}

nod* stergere(nod *l)
{
    nod *aux1, *aux2;
    if(l!=NULL)
    {
        aux1=l;
        aux2=l->next;
        cout<<"\n voi sterge nodul care contine "<<aux1->info<<endl;
        delete aux1;
        return aux2;
    }
    else
    {
        cout<<"\n coada este goala. Nu mai am ce sa sterg "<<endl;
        return NULL;
    }
}

void creare_coada()
{
    nod *a;
    int info;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>info;
        l=inserare(info,l);
    }
}

void afisare_coada(nod *a)
{
    a=l;
    if(a==NULL)
        cout<<"coada este vida";
    else
    {
        cout<<"\nelementele cozii sunt: ";
        while(a)
        {
            cout<<a->info<<" ";
            a=a->next;
        }
    }
}

void ma(nod *a)
{
    int i=0,s=0;
    a=l;
    {
        while(a)
        {
            i++;
            s=s+a->info;
            a=a->next;
        }
    }
    cout<<"media aritmetica este: ";
    cout<<(float) s/i;
}

int main()
{
    creare_coada();
    l=inserare(100,l);
    l=inserare(2,l);
    l=inserare(5,l);
    l=inserare(3,l);
    l=inserare(7,l);
    afisare_coada(l);
    cout<<endl;
    ma(l);
    return 0;
}
