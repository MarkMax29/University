//Gradul maxim al arborelui.Verific fiecare nod cati copii are ,prin pargurgere si memorez nodul care are cei mai multi copii


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct Nod{
    char nume[10];
    int parinte,fiu,frate;
}Nod;

typedef struct Arbore{
    Nod noduri[MAX];
    int size;
}Arbore;

int cauta_dp_nume(Arbore *a,char *nume)
{
    for(int i=0;i<a->size;i++)
    {
        if(strcmp(a->noduri[i].nume,nume)==0)
            return i;
    }
    return -1;
}

char *afis_nume(Arbore *a,int index)
{
    for(int i=0;i<a->size;i++)
    {
        if(i==index)
        {
            return a->noduri[i].nume;
        }
    }
    return NULL;
}
void creare(Arbore *a,char *nume,char *parent)
{
    if(a->size>MAX)
    {
        perror("Depasire\n");
        exit(-1);
    }

    int parent_index;
    if(strcmp(parent,"-1")==0)
    {
        parent_index=-1;
    }
    else
    {
        parent_index=cauta_dp_nume(a,parent);
    }

    strcpy(a->noduri[a->size].nume,nume);
    a->noduri[a->size].parinte=parent_index;
    a->noduri[a->size].fiu=-1;
    a->noduri[a->size].frate=-1;

    if(parent_index!=-1)
    {
        if(a->noduri[parent_index].fiu==-1)
        {
            a->noduri[parent_index].fiu=a->size;
        }
        else
        {
            int f=a->noduri[parent_index].fiu;
            while(a->noduri[f].frate!=-1)
            {
                f=a->noduri[f].frate;
            }
            a->noduri[f].frate=a->size;
        }
      
    }
    a->size++; 

}

void print(Arbore *a)
{
    printf("Index:    ");
    for(int i=0;i<a->size;i++)
    {
        printf("%11d ",i);
    }
    printf("\nCheie:    ");
    for(int i=0;i<a->size;i++)
    {
        printf("%11s ",a->noduri[i].nume);
    }
    printf("\nParinte:  ");
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==-1)
            printf("%10d ",a->noduri[i].parinte);
        else
            printf("%11s ",afis_nume(a,a->noduri[i].parinte));
    }
    printf("\nPrim fiu: ");
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].fiu==-1)
            printf("%10d ",a->noduri[i].fiu);
        else
            printf("%11s ",afis_nume(a,a->noduri[i].fiu));
    }
    printf("\nFrate drt: ");
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].frate==-1)
            printf("%10d ",a->noduri[i].frate);
        else
            printf("%11s ",afis_nume(a,a->noduri[i].frate));
    }
    printf("\n");
}

void maxim_dir(Arbore *a)
{
    int maxim=-1,max_ind=-2;
    for(int i=0;i<a->size;i++)
    {
        int fiu=a->noduri[i].fiu;
        int nr=0;
        if(fiu!=-1)
        {
            nr++;
            int f=a->noduri[fiu].frate;
            while(f!=-1)
            {
                f=a->noduri[f].frate;
                nr++;
            }
        }
        if(maxim<nr)
        {
            maxim=nr;
            max_ind=i;
        }
    }

    printf("Directorul %s are cele mai multe directoare (copii directi) si anume : %d\n",afis_nume(a,max_ind),maxim);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("NOt good arg\n");
        exit(-1);
    }
    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at opennnning file");
        exit(-1);
    }

    Arbore a;
    a.size=0;

    char nume[10],parinte[10];

    while(fscanf(f,"%s %s",nume,parinte)==2)
    {
        creare(&a,nume,parinte);
    }
   print(&a);
    
   maxim_dir(&a);
return 0;
}