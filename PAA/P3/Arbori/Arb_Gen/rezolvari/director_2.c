#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Nod{
    char nume[10];
    int frate,fiu,parinte;
}Nod;

typedef struct Arbore{
    Nod noduri[MAX];
    int size;
}Arbore;

int cauta_dp_cheie(Arbore *a,char *ch)
{
    for(int i=0;i<a->size;i++)
    {
        if(strcmp(a->noduri[i].nume,ch)==0)
        return i;
    }
    return -1;
}

int get_root(Arbore *a)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==-1)
        return i;
    }
    return -1;
}
void inserare(Arbore *a,char *nume,char *parinte)
{

    if(a->size>MAX)
    {
        perror("Depasire\n");
        exit(-1);
    }

    int parinte_index;
    if(strcmp(parinte,"-1")==0)
    {
        parinte_index=-1;
    }
    else
    {
        parinte_index=cauta_dp_cheie(a,parinte);
    }

    strcpy(a->noduri[a->size].nume,nume);
    a->noduri[a->size].parinte=parinte_index;
    a->noduri[a->size].fiu=-1;
    a->noduri[a->size].frate=-1;

    if(parinte_index!=-1)
    {
        if(a->noduri[parinte_index].fiu==-1)
        {
            a->noduri[parinte_index].fiu=a->size;
        }
        else
        {
            int f=a->noduri[parinte_index].fiu;
            while(a->noduri[f].frate!=-1)
            {
                f=a->noduri[f].frate;
            }
            a->noduri[f].frate=a->size;
        }
    }
    a->size++;


}
char *afis_nume(Arbore *a,int index)
{
   return a->noduri[index].nume;
}
void print(Arbore *a)
{
  printf("Index:    ");
  for(int i=0;i<a->size;i++)
  {
    printf("%10d ",i);
  }  

  printf("\nCheie:    ");
  for(int i=0;i<a->size;i++)
  {
    printf("%10s ",a->noduri[i].nume);
  }

  printf("\nParinte:  ");

  for(int i=0;i<a->size;i++)
  {
    if(a->noduri[i].parinte==-1)
        printf("%10d ",a->noduri[i].parinte);
    else
        printf("%10s ",afis_nume(a,a->noduri[i].parinte));
  }

  printf("\nPrim fiu: ");
  for(int i=0;i<a->size;i++)
  {
    if(a->noduri[i].fiu==-1)
        printf("%10d ",a->noduri[i].fiu);
    else
        printf("%10s ",afis_nume(a,a->noduri[i].fiu));
  }

  printf("\nFrate dr: ");
  for(int i=0;i<a->size;i++)
  {
    if(a->noduri[i].frate==-1)
        printf("%10d ",a->noduri[i].frate);
    else
        printf("%10s ",afis_nume(a,a->noduri[i].frate));
  }

}
int end=0,front=0;
void push(int *coada,int value)
{
    coada[end++]=value;
}
int queue(int *coada)
{
    return coada[front++];
}

void bfs(Arbore *a,int *coada,int index_rad)//cati nervi mio facut cacatu asta simplu 
{
    int nivel[MAX],k=0;
    push(coada,index_rad);
    
    nivel[index_rad]=0;
    k++;
    while(front<end)
    {
        int nod=queue(coada);
        
        int fiu=a->noduri[nod].fiu;
        if(fiu!=-1)
        {
            push(coada,fiu);
            nivel[fiu]=nivel[nod]+1;
            k++;

            int frate=a->noduri[fiu].frate;
            while(frate!=-1)
            {
                push(coada,frate);
                nivel[frate]=nivel[nod]+1;
                k++;
                frate=a->noduri[frate].frate;
            }

        }
    }

    int nr=0;
    for(int i=0;i<k;i++)
    
            if(nivel[i]==nivel[i+1])
            {
                nr++;
            }
            else
            {
                    nr++;
                    printf("Nivelul %d are: %d noduri\n",nivel[i],nr);
                    nr=0;
            }

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

    char nume[10],parinte[10];
    while(fscanf(f,"%s %s",nume,parinte)==2)
    {
        inserare(&a,nume,parinte);
    }
    print(&a);
    printf("\n");


    int *coada=(int*)malloc(sizeof(int)*MAX);
    if(coada==NULL)
    {
        perror("COADA EROARE\n");
        exit(-1);
    }
    int rad=get_root(&a);
    bfs(&a,coada,rad);
    return 0;
}