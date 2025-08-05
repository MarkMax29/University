#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX 100

typedef struct Nod{
    int cheie;
    int parinte;
}Nod;

typedef struct Arbore{
    Nod *noduri;
    int size;
}Arbore;

void inserare(Arbore *a,int new_key,int parinte)
{
    a->noduri[a->size].cheie=new_key;
    a->noduri[a->size].parinte=parinte;
    a->size++;
}

void afis(Arbore *a)
{
    printf("Index:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",i);
    }
    printf("\nCheie:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",a->noduri[i].cheie);
    }
    printf("\nParinte:");
    for(int i=0;i<a->size;i++)
    {
     
       printf("%d ",a->noduri[i].parinte);
       
    }
    printf("\n");
}
int main(int argc,char **argv)
{

    if(argc!=2)
    {
        perror("Not good arg!\n");
        exit(-1);
    }

    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("error at openning\n");
        exit(-1);
    }
    char caract[17];
    fscanf(f,"%s",caract);

    Arbore *a=(Arbore*)malloc(sizeof(Arbore));
    if(a==NULL)
    {
        perror("Smth went wrong!\n");
        exit(-1);
    }
    a->size=0;  
    a->noduri=NULL;
    int cheie,parinte;
    while(fscanf(f,"%d,%d",&cheie,&parinte)==2)
    {
        Nod *aux=(Nod*)realloc(a->noduri,(a->size+1)*sizeof(Nod));
        if(aux==NULL)
        {
            perror("Realloc failed\n");
            free(a->noduri);
            free(a);
            fclose(f);
            exit(-1);
        }
        a->noduri=aux;
        inserare(a,cheie,parinte);
    }
    afis(a);
    free(a->noduri);
    free(a);
    fclose(f);
    return 0;
}