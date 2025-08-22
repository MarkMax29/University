#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cu indicator parinte trebuie sa facem o parcurgere prin care aflu si cea mai lunga cale de la radacina
#define MAX 100

typedef struct Director{
    char nume[10];
    int parinte;
}Director;

typedef struct Arbore{
    Director directoare[MAX];
    int size;
}Arbore;


int cauta_index_dp_nume(Arbore *a,char *nume)
{
    for(int i=0;i<a->size;i++)
    {
        if(strcmp(a->directoare[i].nume,nume)==0)
            return i;
    }
    return -1;
}
int get_root(Arbore *a)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->directoare[i].parinte==-1)
            return i;
    }
    return -1;
}
void creare_director(Arbore *a,char *name,char *parent)
{
    if(a->size>MAX)
    {
        perror("Depasire size\n");
        exit(-1);
    }
    int parent_index;
    if(strcmp(parent,"-1")==0)
    {
        parent_index=-1;
    }
    else
    {
        parent_index=cauta_index_dp_nume(a,parent);
    }
    strcpy(a->directoare[a->size].nume,name);
    a->directoare[a->size].parinte=parent_index;
    a->size++;
    
}

int prim_fiu(Arbore *a,int index)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->directoare[i].parinte==index)
            return i;
    }
    return -2;
}
int frate(Arbore *a,int index)
{
    int p=a->directoare[index].parinte;
    for(int i=index+1;i<a->size;i++)
    {
        if(p==a->directoare[i].parinte)
            return i;
    }
    return -2;



}

int cale_max(Arbore *a, int radacina, int nivel, int poz_curenta) 
{
    int max_nivel = nivel;
    int max_poz = poz_curenta;

    // Verifică fiii
    int p = prim_fiu(a, radacina);
    if(p != -2) {
        int fiu_nivel = cale_max(a, p, nivel + 1, p);
        if(fiu_nivel > max_nivel) {
            max_nivel = fiu_nivel;
            max_poz = p;
        }
    }

    // Verifică frații
    int f = frate(a, radacina);
    while(f != -2) {
        int frate_nivel = cale_max(a, f, nivel, f);
        if(frate_nivel > max_nivel) {
            max_nivel = frate_nivel;
            max_poz = f;
        }
        f = frate(a, f);
    }

    return max_poz;

}
/*
int cale_max(Arbore *a,int radacina,int maxim,int poz_max)
{

    int p=prim_fiu(a,radacina);
    if(p!=-2)
        cale_max(a,p,1+maxim,poz_max);
    

    int maxi;
    if(maxi<=maxim)
    {
        maxi=maxim;
        poz_max=radacina;
    }
    int f=frate(a,p);
    while(f!=-2)
    {
        cale_max(a,f,maxim,poz_max);
            if(maxi<=maxim)
            {
                maxi=maxim;
                poz_max=f;
            }
        f=frate(a,f);
    }
    return poz_max;
}
*/


void print(Arbore *a)
{
    printf("Index:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%12d ",i);
    }
    printf("\nCheie:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%12s ",a->directoare[i].nume);
    }
    printf("\nParinte: ");
    
    for(int i=0;i<a->size;i++)
    {
        printf("%12d ",a->directoare[i].parinte);
    }
}
int main(int argc,char ** argv)
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
        perror("error at openning file\n");
        exit(-1);
    }

    Arbore a;
    a.size=0;

    char nume[10],parinte[10];
    while(fscanf(f,"%s %s",nume,parinte)==2)
    {
        creare_director(&a,nume,parinte);
    }
    print(&a);
    printf("\n");

    int rad=get_root(&a);
    int last_poz=cale_max(&a,rad,0,rad);
    printf("%d ",last_poz);
   
    return 0;
}