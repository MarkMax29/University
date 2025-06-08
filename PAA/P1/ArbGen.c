#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
// Implementarea INDICATOR CATRE PARINTE //

typedef int TipCheie;//e un alias care practic iti poate inlocui tipul cheii in orice moment doar cu o simpla linie de cod
// va stii ca e tip int TipCheie; 

typedef struct {
    TipCheie cheie;
    int parinte;
}Nod;

typedef struct {
    Nod noduri[MAX];
    int nr_noduri;
}Arbore;


//initializare 

Arbore init()
{
    Arbore a;
    a.nr_noduri=0;
    return a;
}

//inserare nod

void inserare(Arbore *a,TipCheie val, int index_parinte)
{
    if(a->nr_noduri>=MAX)
    {
        printf("depasim size-ul maxim\n");
        return;
    }

    a->noduri[a->nr_noduri].cheie=val;
    a->noduri[a->nr_noduri].parinte=index_parinte;
    a->nr_noduri++;
}

void preordine(Arbore *a,int index)
{
    printf("%d ",a->noduri[index].cheie);
    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].parinte==index)
        {
            preordine(a,i);
        }
    }
}

void inordine(Arbore *a,int index)
{
    int copii[MAX],nr=0;

    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].parinte==index)// daca nodul i il are ca parinte pe nodul cu indexul index , atunci e copil si il memorez in vectorul de copii
        {
             copii[nr]=i;
             nr++;
        }

    }
    //daca are copii ,iau pe primul copil(care e cel din stanga)
    if(nr>0)
        inordine(a,copii[0]);
    
    // daca nu am atunci afisez radacina
    printf("%d ",a->noduri[index].cheie);
    
    //dupa ce am terminat de afisat ma introc la apelul de dinainte si ma uit daca nodul a avut frati si apelez iar recursiv (deci practic in dreapta)
    for(int i=1;i<nr;i++)
        inordine(a,copii[i]);
}

void postordine(Arbore *a,int index)
{
    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].parinte==index)
            postordine(a,i);
    }
    printf("%d ",a->noduri[index].cheie);
}

int findNode(Arbore *a,Nod nod)
{
    int cautat=-2;
    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].cheie==nod.cheie && a->noduri[i].parinte==nod.parinte)
        {
            cautat=a->noduri[i].cheie;
            return i;
            break;
        }
    }
    return cautat;
}


void stergNodindex(Arbore *a,int index_nod_desters)
{
    int parinte_nod=a->noduri[index_nod_desters].parinte;

    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].parinte==index_nod_desters)
            a->noduri[i].parinte=parinte_nod;
    }

    for(int i=index_nod_desters; i< a->nr_noduri-1; i++)
    {
        a->noduri[i]=a->noduri[i+1];
    }
    a->nr_noduri--;


    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].parinte > index_nod_desters)
            a->noduri[i].parinte--;
        else if(a->noduri[i].parinte==index_nod_desters)
            a->noduri[i].parinte=parinte_nod;

    }
}

void stersNodcheie(Arbore *a,Nod key)
{
    int cautat=findNode(a,key);
    if(cautat<0)
    {
        printf("Nu exista nodul cautat de sters!\n");
        return;
    }
    else
    {
        stergNodindex(a,cautat);
        printf("S-A REUSIT STERGEREA NODULUI %d !\n",key.cheie);
    }

}

void stersParintesiSubarbore(Arbore *a,Nod key)
{
    int cautat=findNode(a,key);
    if(cautat<0)
    {
        printf("Nu se gaseste nodul de sters\n");
    }
    else
    {
        int de_sters[MAX],n=0;
        de_sters[n]=cautat;
        n++;

        for(int i=0;i<n;i++)
        {
            int current=de_sters[i]; int n;
            for(int j=0;j<a->nr_noduri;j++)
            {
                if(a->noduri[j].parinte==current)
                {
                    de_sters[n]=j;
                    n++;
                }
            }
        }

        int nou_n=0;
        for(int i=0;i<a->nr_noduri;i++)
        {
            int sterge=0;
            for(int k=0;k<n;k++)
            {
                if(i==de_sters[k])
                   { 
                    sterge=1;
                    break;
                   }
            }

            if(sterge==0)
              { 
                 a->noduri[nou_n]=a->noduri[i];
                 nou_n++;
              }
        }

        a->nr_noduri = nou_n;
    
    }

}

int inaltimeMax(Arbore *a)
{
    int max_h=0;

    for(int i=0;i<a->nr_noduri;i++)
    {
        int h=1;
        int p=a->noduri[i].parinte;

        while(p!=-1)
        {
            h++;
            p=a->noduri[p].parinte;
        }

        if(h > max_h)
            max_h=h;
    }
    return max_h;
}
void afis(Arbore *a)
{
    printf("\nIndex:");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%4d",i);
    }

    printf("\nKey:");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",a->noduri[i].cheie);
    }
    printf("\nParent:");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%4d",a->noduri[i].parinte);
    }
    printf("\n===============================\n");
}
int main()
{
    FILE *f=NULL;
    f=fopen("in.txt","r");
    if(f==NULL)
    {
        perror("eroare la deschidere");
        exit(-1);
    }

    Arbore a=init();
  
    int key,parent;
    while(fscanf(f,"%d %d",&key,&parent)==2)
    {
        inserare(&a,key,parent);
    }
    
    afis(&a);

    printf("Preordine: ");preordine(&a,0);
    printf("\nInordine: ");inordine(&a,0);//e practic bine doar ca daca a doar un fiu nu stie daca e stanga sau dreapta si nu respecta st,rad,dr
    printf("\nPostordine: ");postordine(&a,0);

// cautare nod 
    Nod n;
    n.cheie=60;
    n.parinte=5;
    int gasit=findNode(&a,n);

    if(gasit>0)
        printf("\nNodul %d s-a gasit in arbore la indexul %d\n",n.cheie,gasit);
    else
        printf("\nNU SA GASIT\n");

// inaltimea arbore

    int height=inaltimeMax(&a);
    printf("Inaltimea arborelui este %d\n",height);
//sterg dp index

    stergNodindex(&a,n.parinte);
    afis(&a);
    
    return 0;
}