#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 99999999

int graf[MAX+1][MAX+1];
int vizitat[MAX+1];
int parinte[MAX+1];
int D[MAX+1];

void Dijkstra(int n,int start)
{
    memset(vizitat,0,sizeof(vizitat));
    memset(parinte,-1,sizeof(parinte));
    for(int i=0;i<=MAX;i++)
    {
        D[i]=INF;
    }
    
    D[start]=0;
    for(int pas=1;pas<n;pas++)
    {
        int u=-1,min=INF;
        for(int i=1;i<=n;i++)
        {
            if(D[i]<min && vizitat[i]==0)
            {
                u=i;
                min=D[i];
            }
        }

        if(u==-1)
            return;
        vizitat[u]=1;
        for(int v=1;v<=n;v++)
        {
            if(graf[u][v]>0 && vizitat[v]==0 && D[u]+graf[u][v]<D[v])
            {
                D[v]=D[u]+graf[u][v];
                parinte[v]=u;
            }
        }

    }

    for(int i=1;i<=n;i++)
    {
        int drum[n],k=0,curent=i;
        while(curent!=-1)
        {
            drum[k++]=curent;
            curent=parinte[curent];
        }
        printf("DRUMUL de la %d la %d: ",start,i);
        for(int j=k-1;j>=0;j--)
        {
            printf("%d ",drum[j]);
        }
        printf(" cu costul %d\n",D[i]);

    }
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
        perror("Not ok at openning file \n");
        exit(-1);

    }
    int n;
    fscanf(f,"%d",&n);

    memset(graf,0,sizeof(graf));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
    Dijkstra(n,1);

    return 0;
}