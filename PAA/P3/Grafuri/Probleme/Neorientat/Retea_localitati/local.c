#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 999999
int vizitat[MAX+1],predec[MAX+1];

void Dijkstra(int **graf,int n,int m,int start)
{
    int D[MAX+1];
    for(int i=0;i<=n;i++)
    {
        D[i]=INF;
        predec[i]=-1;
        vizitat[i]=0;
    }

    D[start]=0;
    for(int pas=1;pas<=n-1;pas++)
    {
        int min=INF,u=-1;
        for(int i=1;i<=n;i++)
        {
            if(min>D[i] && vizitat[i]==0)
            {
                min=D[i];
                u=i;
            }
        }

        if(u==-1)
            return;
        vizitat[u]=1;

        for(int v=1;v<=n;v++)
        {
            if(graf[u][v]!=0 && vizitat[v]==0 && D[v]>D[u]+graf[u][v]+m)
            {
                D[v]=D[u]+graf[u][v]+m;
                predec[v]=u;
            }
        }
    }
//PENTRU CA VREA TRASEELE DE LA 1 LA TOATE CELELATE N-1 
    for(int i=2;i<=n;i++)
    {
        int drum[n],k=0,curent=i;
        while(curent!=-1)
        {
            drum[k++]=curent;
            curent=predec[curent];
        }

        printf("Drum de la 1 la %d: ",i);
        for(int j=k-1;j>=0;j--)
        {
            printf("%d ",drum[j]);
        }
        printf("    | cost=%d\n",D[i]);
        
        
    }
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not ok \n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not ok reading\n");
        exit(-1);
    }

    int n,m;
    fscanf(f,"%d %d",&n,&m);
    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("not ok allocating\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("error allocate\n");

            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
        graf[b][a]=cost;
    }

    int start=1;
    Dijkstra(graf,n,m,start);
    return 0;
}