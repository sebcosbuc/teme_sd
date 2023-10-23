/* - elementele din lista care au ultima cifra egala cu 3;
   - suma elementelor mai mari ca 100 din lista ;
   - sa se actualizeze lista ridicand la patrat fiecare element;
   - sa se afiseze elementele patrate perfecte din lista;
   - sa se afiseze elementele intr-un interval [a,b], a si b citite de la tastatura.*/
#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *first, *last;

void creare_lista()
{
    node *aux;
    int n;
    cout<<"numarul de elemente ale listei = ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(first==NULL)
        {
            first=new node;
            cin>>first->data;
            first->next=NULL;
            last=first;
        }
        else
        {
            aux=new node;
            cin>>aux->data;
            aux->next=NULL;
            last->next=aux;
            last=aux;
        }
    }
}

void afisare_lista()
{
    node *a;
    a=first;
    if(a==NULL)
    {
        cout<<"lista vida ";
    }
    else
    {
        cout<<"elementele listei sunt: ";
        while(a)
        {
            cout<<a->data<<" ";
            a=a->next;
        }
    }
    cout<<endl;
}

void afisare_elemente_cu_ultima_cifra_3()
{
    node *a;
    a=first;
    cout<<"elementele cu ultima cifra egala cu 3 sunt: ";
    while (a)
    {
        if (a->data%10==3)
        {
            cout<<a->data<<" ";
        }
        a=a->next;
    }
    cout<<endl;
}

void suma_elementelor_mai_mari_ca_100()
{
    int s=0;
    node *a;
    a=first;
    cout<<"suma elementelor mai mari ca 100: ";
    while (a)
    {
        if (a->data>100)
        {
            s=s+a->data;
        }
        a=a->next;
    }
    cout<<s;
    cout<<endl;
}

void lista_la_patrat()
{
    node *a;
    a=first;
    cout<<"elementele listei ridicate la patrat sunt: ";
    while (a)
    {
        cout<<a->data*a->data<<" ";
        a=a->next;
    }
    cout<<endl;
}

bool patrat(int n)
{
    if((int)sqrt(n)==(float)sqrt(n))
        return true;
    else
        return false;
}

void elementele_patrate_perfecte()
{
    node *a;
    a=first;
    cout<<"elementele patrate perfecte sunt: ";
    while (a)
    {
        if(patrat(a->data))
            cout<<a->data<<" ";
        a=a->next;
    }
    cout<<endl;
}

void elementele_din_interval()
{
    node *x;
    x=first;
    int a,b;
    cout<<"intervalul a,b este: "<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"elementele din intervalul ["<<a<<","<<b<<"] "<<"sunt: ";
    
}

int main()
{
    creare_lista();
    afisare_lista();
    afisare_elemente_cu_ultima_cifra_3();
    suma_elementelor_mai_mari_ca_100();
    lista_la_patrat();
    elementele_patrate_perfecte();
    elementele_din_interval();
    return 0;
}
