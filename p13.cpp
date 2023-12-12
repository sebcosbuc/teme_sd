//13. Să determine lungimea unei cozi și să se afle dacă valoarea se regăsește ca element în coadă.
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

void nr_elemente(nod *a)
{
    int i=0;
    a=l;
        while(a)
        {
            i++;
            a=a->next;
        }
        cout<<"coada contine "<<i<<" elemente ";
        cout<<endl;
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
    nr_elemente(l);
    return 0;
}
