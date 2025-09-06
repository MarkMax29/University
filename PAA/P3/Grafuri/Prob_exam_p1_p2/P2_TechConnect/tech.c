#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 9999999
void init(int **graf,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graf[i][j]=0;
        }
    }
}


void Prim(int **graf,int n,int start)
{
    int u[n];
    memset(u,0,sizeof(u));
    int total=0;
    u[start]=1;
    for(int pas=0;pas<n-1;pas++)
    {
        int min=INF,mini=-1,minj=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
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
            total+=min;
            u[mini]=1;
            u[minj]=1;
        }
    }
    printf("Costul minim total pentru conectarea tuturor localitatilor: %d\n",total);
    

}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not ok arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not ok at openning\n");
        exit(-1);
    }
    char cod[25];
    int n;

    fscanf(f,"%s",cod);
    fscanf(f,"%d",&n);

    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("error allocation\n");
        free(graf);
        exit(-1);
    }

    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("error allocation line of matrix\n");
            for(int j=0;j<=n;j++)
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

    int start=0;
    Prim(graf,n,start);
    return 0;

}