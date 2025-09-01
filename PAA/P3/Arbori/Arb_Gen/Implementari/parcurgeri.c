#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct NOD{
    char cheie;
    int parinte;// index in vector sau -1 daca e radacina
}NOD;

typedef struct Arbore{
    NOD noduri[MAX];
    int size;
}Arbore;


int cauta_index_dp_cheie(Arbore *a,char ch)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].cheie==ch)
            return i;

    }
    return -1;
}
int get_rad_index(Arbore *a)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==-1)
        {
            return i;
            break;
        }
    }
    return -2;

}
void creare(Arbore *a,char key,char *parent)
{
    if(a->size>=MAX)
    {
        perror("depasire volum max\n");
        exit(-1);
    }
    int parent_index;   
    if(strcmp(parent,"-1")==0)
        parent_index=-1;
    else
        parent_index=cauta_index_dp_cheie(a,parent[0]);

    a->noduri[a->size].cheie=key;
    a->noduri[a->size].parinte=parent_index;
    a->size++;
    
}


void afis (Arbore *a)
{
    printf("Index:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%d ",i);
    }
    printf("\nCheie:   ");
    for(int i=0;i<a->size;i++)
    {
        printf("%c ",a->noduri[i].cheie);
    }
    printf("\nParinte: ");
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==-1)
            printf("%d ",a->noduri[i].parinte);
        else
            printf("%c ",'A'+a->noduri[i].parinte);// asa il afisam ca si caracter dar efectiv in vector e index si facem 'A' + INDEXUL DIN VECTOR sa obtinem cheia pentru parintele acelui nod 
    }
    printf("\n");
}

void preordine(Arbore *a,int index)
{
    printf("%c ",a->noduri[index].cheie);

    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==index)
            preordine(a,i);
    }
}
void postordine(Arbore *a,int index)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==index)
            postordine(a,i);
    }
    printf("%c ",a->noduri[index].cheie);
}

int prim_copil(Arbore *a,int index)
{
    for(int i=0;i<a->size;i++)
    {
        if(a->noduri[i].parinte==index)
        {
            return i;
            break;
        }
    }
    return -2;
}
int frate_dr(Arbore *a,int index)
{
    int p=a->noduri[index].parinte;
    for(int i=index+1;i<a->size;i++)
    {
        if(a->noduri[i].parinte==p)
        {
            return i;
            break;
        }
    }
    return -2;
}
void inordine(Arbore *a,int index)
{
    int ch_prim=prim_copil(a,index);
    if(ch_prim ==-2)
    {
         printf("%c ",a->noduri[index].cheie);
    }
    else 
    {
        inordine(a,ch_prim);
        printf("%c ",a->noduri[index].cheie);
        ch_prim=frate_dr(a,ch_prim);
        while(ch_prim!=-2)
        {
            inordine(a,ch_prim);
            ch_prim=frate_dr(a,ch_prim);
        }
    }
}

/// PARCURGEREA PRIN CUPRINDERE !!!!  ///
int front=0,end=0;
void push(int *coada,int value)
{
    coada[end++]=value;//va fi indexul gen parintele sau idk yet
}

int queue(int *coada)
{
    return coada[front++];
}
void cuprindere(Arbore *a,int index,int *coada)
{
    int fiu;
      push(coada,index);
      while(front<end)
      {
        int index_nod=queue(coada);
        printf("%c ",a->noduri[index_nod].cheie);
        fiu=prim_copil(a,index_nod);

        if(fiu!=-2)
        {
            push(coada,fiu);
            int frate=frate_dr(a,fiu);
            while(frate!=-2)
            {
                push(coada,frate);
                frate=frate_dr(a,frate);
            }
        }
      }
}

///stergerea nu merge din ceva motiv ///
void stergere(Arbore *a, int index) {

    for(int i=a->size-1;i>=0;i--)
    {
        if(a->noduri[i].parinte==index) 
        {
            a->noduri[i].parinte=-3;
            stergere(a,i);

        }
    }

    for(int i=index+1;i<a->size;i++)
    {
        a->noduri[i-1]=a->noduri[i];
    }
    a->size--;

     for(int i=0;i<a->size;i++)
     {

         if(a->noduri[i].parinte==index)
          {
           // if(prim_copil(a,i)!=-2 || frate_dr(a,i)!=-2)
                a->noduri[i].parinte--;
          }

     }
        
}


int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not ok arg\n");
        exit(-1);
    }

    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("not ok file\n");
        exit(-1);
    }

    Arbore a;
    a.size=0;

    char key,parent[3];
    while(fscanf(f," %c %s",&key,parent)==2)
    {
        creare(&a,key,parent);
    }

    afis(&a);

    int rad=get_rad_index(&a);

    printf("\nPreordine: ");
    preordine(&a,rad);
    printf("\n");

    printf("Postordine: ");
    postordine(&a,rad);
    printf("\n");

    printf("Inordine: ");
    inordine(&a,rad);
    printf("\n");

    int *coada=(int*)malloc(sizeof(int)*(a.size));
    if(coada==NULL)
    {
        perror("Not enough memory!\n");
        exit(-1);
    }
    printf("\nCuprindere:");
    cuprindere(&a,rad,coada);
    printf("\n\n");

    int delete=cauta_index_dp_cheie(&a,'D');
    stergere(&a,delete);

    afis(&a);
    return 0;
}