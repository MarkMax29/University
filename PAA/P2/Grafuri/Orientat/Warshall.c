#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int reach[MAX][MAX];
void init(int **graf,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graf[i][j]=0;
        }
    }
}

void afis(int n)
{
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             printf("%d ",reach[i][j]);
         }
         printf("\n");
     }
}
void accesibilitate(int **graf,int n)
{
    for(int i=0;i<n;i++)   //practic pun in matricea de accesibilitate momentan doar drumurile directe adica de la un nod la altul, gen de la a la b fara alte noduri intermediare
    {
        for(int j=0;j<n;j++)
        {
            if(graf[i][j]!=0)
                reach[i][j]=1;
            else
                reach[i][j]=0;
        }
    }
   
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(reach[i][k] && reach[k][j])
                {
                    reach[i][j]=1;
                }
            }
        }
    }
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("eroare arg\n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("eroare file\n");
        exit(-1);
    }
    int n;
    fscanf(f,"%d",&n);

    int **graf=(int**)malloc(sizeof(int*)*(n));
    if(graf==NULL)
    {
        perror("puloc\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n));
        if(graf[i]==NULL)
        {
            perror("puloc graf\n");
            for(int j=0;j<n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    init(graf,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }
    
    printf("Matricea de accesibilitate: \n");

    accesibilitate(graf,n);
    afis(n);
     printf("\n\nExista drumuri in felul urmator:\n");
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(reach[i][j]!=0)
             {
                 printf("de la %d -> %d\n",i,j);
             }
         }
     }

    return 0;
}