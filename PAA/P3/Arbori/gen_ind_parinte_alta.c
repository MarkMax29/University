#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct Nod{
    int cheie;
    int parinte;
}Nod;

typedef struct Arbore{ 
    Nod noduri[MAX];
    int size;
}Arbore;

void creare(Arbore *a,int key,int parent)
{
    if(a->size>MAX)
    {
        perror("depasire\n");
        exit(-1);
    }
    a->noduri[a->size].cheie=key;
    a->noduri[a->size].parinte=parent;
    a->size++;
}

void print(Arbore *a)
{
    printf("Index:    ");
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",i);
    }
    printf("\nCheie:    ");
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",a->noduri[i].cheie);
    }
    printf("\nParinte: ");;
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",a->noduri[i].parinte);
    }
    printf("\n");
}
int foundinx(Arbore *a,int cheie)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].cheie==cheie)
        {
            return i;
            break;
        }
    }

    return -1;

}
void problema_p2(Arbore *a,int cheie,int count)
{
    
    int indx=foundinx(a,cheie);
    if(a->noduri[indx].parinte!=-1)
    {
       count++;
       printf("%d %d\n",a->noduri[indx].cheie,a->noduri[indx].parinte);
       problema_p2(a,a->noduri[indx].parinte,count);
    }
    else
    {
        printf("\nNivel:%d\n",count);
    }
   
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Notgood arg!\n");
        exit(-1);
    }
    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at openning\n");
        exit(-1);
    }


    char smth[17];
    fscanf(f,"%s",smth);

    int k,p;
    Arbore a;
    a.size=0;

    while(fscanf(f,"%d, %d",&k,&p)==2)
    {
        creare(&a,k,p);
    }
   // print(a);

   int count=0;
   problema_p2(&a,555,count);
    return 0;
}