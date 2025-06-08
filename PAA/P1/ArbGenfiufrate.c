#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef int TipCheie;

typedef struct {
    TipCheie cheie;
    TipCheie parinte;
    TipCheie primul_fiu;
    TipCheie frate_dr;
}Nod;

typedef struct {
    Nod noduri[MAX];
    int nr_noduri;
}Arbore;

Arbore init()
{
    Arbore a;
    a.nr_noduri=0;
    return a;
}

void inserare(Arbore *a,TipCheie val,int index_parinte)
{
    if(a->nr_noduri>=MAX)
    {
        printf("depasire nr max de noduri\n");
        return;

    }

    a->noduri[a->nr_noduri].cheie=val;
    a->noduri[a->nr_noduri].parinte=index_parinte;
    a->noduri[a->nr_noduri].frate_dr=-1;
    a->noduri[a->nr_noduri].primul_fiu=-1;
    

    if(index_parinte==-1)
    {//nu il legam de nimic doar il punem in vector 
    }
    else
    { if(a->noduri[index_parinte].primul_fiu==-1)
        {
            a->noduri[index_parinte].primul_fiu=a->nr_noduri;
        }
      else {
        int fiu=a->noduri[index_parinte].primul_fiu;
    
      while(a->noduri[fiu].frate_dr!=-1)
        {
            fiu=a->noduri[fiu].frate_dr;
        }
        a->noduri[fiu].frate_dr=a->nr_noduri;
      }
    }    
    a->nr_noduri++;
}
int cautaIndex(Arbore *a,int cheie)
{
    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].cheie==cheie)
        {
            return i;
            break;
        }
    }
    return -1;
}
void stergereNod(Arbore *a,int cheie)
{
    int index=cautaIndex(a,cheie);
    if(index==-1)
    {
        printf("Nodul cu cheia %d nu a fost gasit \n",cheie);
        return;
    }

    for(int i=0;i<a->nr_noduri;i++)
    {
        if(a->noduri[i].primul_fiu==index)
        {
            a->noduri[i].primul_fiu=a->noduri[index].frate_dr;
            return;
        }

        int frate=a->noduri[i].primul_fiu;

        while(frate!=-1 && a->noduri[frate].frate_dr!=-1)
        {
            if(a->noduri[frate].frate_dr==index)
                {
                    a->noduri[frate].frate_dr=a->noduri[index].frate_dr;
                    return;

                }
            frate=a->noduri[frate].frate_dr;//trec la urmatorul frate
        }
    }
}

int drumMax(Arbore *a,int index)
{
    if(index==-1)
        return 0;

    int max_drum=0;
    int copil=a->noduri[index].primul_fiu;
    while(copil!=-1)
    {
        int drum=drumMax(a,copil);
        if(drum>max_drum)
            max_drum=drum;
        copil=a->noduri[copil].frate_dr;
    }
    return max_drum+1;
}

void preordine(Arbore *a,int index)
{
    if(index==-1)
        return;
    printf("%d ",a->noduri[index].cheie);
    int copil=a->noduri[index].primul_fiu;
    while(copil!=-1)
    {
        preordine(a,copil);
        copil=a->noduri[copil].frate_dr;
    }
}
void inordine(Arbore *a, int index) {
    if (index == -1) return;

    int prim = a->noduri[index].primul_fiu;

    if (prim != -1) {
        inordine(a, prim); // primul copil
    }

    printf("%d ", a->noduri[index].cheie); // nodul curent

    if (prim != -1) {
        int frate = a->noduri[prim].frate_dr;
        while (frate != -1) {
            inordine(a, frate);
            frate = a->noduri[frate].frate_dr;
        }
    }
}


void postordine(Arbore *a,int index)
{
    if(index==-1)
    return;

    int copil=a->noduri[index].primul_fiu;

    while(copil!=-1)
    {
        postordine(a,copil);
        copil=a->noduri[copil].frate_dr;
    }
    printf("%d ",a->noduri[index].cheie);
}



void afis(Arbore *a)
{
    printf("        Index:");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",i);
    }
    printf("\n          Key: ");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",a->noduri[i].cheie);
    }
    printf("\n      Parinte: ");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",a->noduri[i].parinte);
    }
    printf("\n     Prim Fiu: ");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",a->noduri[i].primul_fiu);
    }
    printf("\nFrate Dreapta: ");
    for(int i=0;i<a->nr_noduri;i++)
    {
        printf("%5d",a->noduri[i].frate_dr);
    }
    printf("\n==============================================================\n");

}
int main()
{
    Arbore a = init();

    inserare(&a, 10,-1);        // index 0
    inserare(&a, 20, 0);          // index 1
    inserare(&a, 30, 0);          // index 2
    inserare(&a, 40, 1);          // index 3
    inserare(&a, 50, 1);          // index 4
    inserare(&a, 60, 4);          // index 5

    afis(&a);
    printf("Pre: ");preordine(&a,0);
    printf("\nIn: ");inordine(&a,0);
    printf("\nPost: ");postordine(&a,0);

    printf("\nDrum maxim: %d\n", drumMax(&a, 0));

    stergereNod(&a, 20); // sterge nodul cu cheia 20 si tot subarborele sau devine inaccesibil
    printf("Drum maxim dupa stergere: %d\n", drumMax(&a, 0));
    
    
    return 0;
}