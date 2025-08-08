#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct NOD{
    char cheie;
    int parinte;//lucram iar cu index 
    int prim_fiu;
    int frate_dr;

}NOD;

typedef struct Arbore{
    NOD noduri[MAX];
    int size;
}Arbore;

int caut_dp_cheie(Arbore *a,char ch)
{
    for(int i=0;i<a->size;i++)
     {
        if(a->noduri[i].cheie==ch)
            return i;
     } 
     return -1;
}

int get_index_rad(Arbore *a)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==-1)
            return i;
    }
    return -1;
}
void creare_nod(Arbore *a,char key,char *parent)
{
    if(a->size>MAX)//pentru ca ar trebui sa mi se dea un nr maxim de noduri MAX, nu folosesc alocare dinamica altfel as fi folosit 
    {
        perror("DEPASIRE LIMITA DIMENSIUNE VECTOR\n");
        exit(-1);
    }
   
    int parent_index;
    if(strcmp(parent,"-1")==0)
    {
        parent_index=-1;
    }
    else
    {
        parent_index=caut_dp_cheie(a,parent[0]);
    }
   
    a->noduri[a->size].cheie=key;
    a->noduri[a->size].parinte=parent_index;
    a->noduri[a->size].prim_fiu=-1;
    a->noduri[a->size].frate_dr=-1;
   
    if(parent_index!=-1)
    {
        if(a->noduri[parent_index].prim_fiu==-1) //verific daca mai are fii sau nu 
            a->noduri[parent_index].prim_fiu=a->size;//cumva merg invers adica daca vr sa adaug un nod nou ii atribui parintelui acelui nod indexul/litera pentru primul fiu ,legand astfel parintele cu nodul curent de adaugat ca si prim fiu
        else 
        {
            int fiu=a->noduri[parent_index].prim_fiu;
            while(a->noduri[fiu].frate_dr!=-1)
            {
                fiu=a->noduri[fiu].frate_dr;
            }
            a->noduri[fiu].frate_dr=a->size;
        }
    }
    a->size++;

}

void preordine(Arbore *a,int index)
{
    if(index==-1)
        return;
    printf("%c ",a->noduri[index].cheie);
    preordine(a,a->noduri[index].prim_fiu);
    preordine(a,a->noduri[index].frate_dr);
   
}
void postordine(Arbore *a,int index)
{
    int copil=a->noduri[index].prim_fiu;
    while(copil!=-1)
    {
        postordine(a,copil);
        copil=a->noduri[copil].frate_dr;    
    } 
    printf("%c ",a->noduri[index].cheie);
}

void inordine(Arbore *a,int index)
{
    int fiu=a->noduri[index].prim_fiu;//1.verific daca pt nodul curent fiul e diferit de -1
    if(fiu!=-1)
    {
        inordine(a,fiu);
        printf("%c ",a->noduri[index].cheie);//3.dupa ce se termina de afisat din else stanga,se intoarce recursiv la radacina si il afisez 
        int copil=a->noduri[fiu].frate_dr;//4. ii caut fatele dreapta si cat timp exista iar apelez recursiv functia si dupa ce am terminat cu o ramura se intoarce si actualizeaza copil cu urmatorul frate dreapta daca exista 

        while(copil!=-1)
        {
            inordine(a,copil);
            copil=a->noduri[copil].frate_dr;
        }
    }
    else //2.daca nu e atunci afisez nodul curent de exemplu pentru exemplul din fisier pornind de la A ajung la E care nu mai are fiu deci il afisez practic aici afisez fiul stang 
    {
        printf("%c ",a->noduri[index].cheie);
    }

}


//CUPRINDERE//


int end=0,front=0;

void push(int *coada,int value)
{
    coada[end++]=value;
}

int queue(int *coada)
{
    return coada[front++];
}


void cuprindere(Arbore *a,int *coada,int index)
{
    push(coada,index);

    while(front<end)//fi atent la asta
    {
        int nod=queue(coada);
        printf("%c ",a->noduri[nod].cheie);

        int fiu=a->noduri[nod].prim_fiu;
        if(fiu!=-1)
        {
            push(coada,fiu);
            int frate=a->noduri[fiu].frate_dr;
            while(frate!=-1)
            {
                push(coada,frate);
                frate=a->noduri[frate].frate_dr;
            }
        }
    }
}

void stergere(Arbore *a,int index)
{
    int copil=a->noduri[index].prim_fiu;
    while(copil!=-1)
    {
        int frate=a->noduri[copil].frate_dr;
        stergere(a,copil);
        copil=frate;
    }

    a->noduri[index].cheie='0';
    a->noduri[index].prim_fiu=-1;
    a->noduri[index].frate_dr=-1;
}
void afis(Arbore *a)
{
    printf("Index:    ");
    for(int i = 0; i < a->size; i++)
    {
        printf("%3d ", i);
    }

    printf("\nCheie:    ");
    for(int i = 0; i < a->size; i++)
    {
        printf("%3c ", a->noduri[i].cheie);
    }

    printf("\nParent:   ");
    for(int i = 0; i < a->size; i++)
    {
        if (a->noduri[i].parinte == -1)
            printf("  - ");
        else
            printf("%3c ", 'A' + a->noduri[i].parinte);
    }

    printf("\nPrim fiu: ");
    for(int i = 0; i < a->size; i++)
    {
        if (a->noduri[i].prim_fiu == -1)
            printf("  - ");
        else    
            printf("%3c ", 'A' + a->noduri[i].prim_fiu);
    }

    printf("\nFrate dr: ");
    for(int i = 0; i < a->size; i++)
    {
        if (a->noduri[i].frate_dr == -1)
            printf("  - ");
        else
            printf("%3c ", 'A' + a->noduri[i].frate_dr);
    }

    printf("\n");
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not good arg\n");
        exit(-1);
    }

    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at openning file\n");
        exit(-1);
    }

    Arbore a;
    a.size=0;


    char key,parent[3];
    while(fscanf(f," %c %s",&key,parent)==2)
    {
        creare_nod(&a,key,parent);
    }
    afis(&a);

    int rad=get_index_rad(&a);
    printf("\nPreorder : ");
    preordine(&a,rad);
    printf("\nPostorder: ");
    postordine(&a,rad);
    printf("\nInorder  : ");
    inordine(&a,rad);
    printf("\n");



    int *coada=(int*)malloc(sizeof(int)*MAX);
    if(coada==NULL)
    {
        perror("ERROR AT QUEUE!\n");
        exit(-1);
    }
    printf("\nCuprindere: ");
    cuprindere(&a,coada,rad);
    printf("\n");
    int delete=caut_dp_cheie(&a,'B');
    stergere(&a,delete);
    afis(&a);

    printf("\n\nSubarborele cu radacina %c a fost stearsa impreuna cu fii sai : ",'A'+delete);
    for(int i=0;i<a.size;i++)
    {
        if(a.noduri[i].cheie=='0' && i!=delete)
            printf("%c ",'A'+i);
    }
    printf("\n");
    fclose(f);

    return 0;
}