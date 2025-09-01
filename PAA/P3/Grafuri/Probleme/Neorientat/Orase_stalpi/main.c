#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 9999999

void init(int graf[MAX+1][MAX+1])
{
    for(int i=0;i<=MAX;i++)
    {
        for(int j=0;j<=MAX;j++)
        {
            graf[i][j]=0;
        }
    }
}


void PRIM(int graf[MAX+1][MAX+1],int n,int start)
{
    int u[MAX+1];
     memset(u,0,sizeof(u));

     u[start]=1;
    int stalpi=0,total=0;

    printf("Muchii din MST:\n");
     for(int pas=1;pas<=n-1;pas++)
     {
        int min=INF,mini=-1,minj=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]!=0 && u[i]!=u[j] && min>graf[i][j])
                {
                    min=graf[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
        if(mini!=-1 && minj!=-1)
        {
            
            printf("%d %d cost(%d)\n",mini,minj,min);
            if(min<=100)
                stalpi+=0;
            else
                stalpi+=((min+99)/100)-1;

            total+=min;
            u[mini]=1;
            u[minj]=1;
        }

     }

     printf("\nCostul total minim al MST:%d\n\n",total);
     printf("NUMRUL MINIM DE STALPI DE ADAUGAT ESTE : %d\n",stalpi);
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not good arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not openning file \n");
        exit(-1);
    }    

    int graf[MAX+1][MAX+1];
    init(graf);

    int n;
    fscanf(f,"%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }

    PRIM(graf,n,1);



    return 0;
}