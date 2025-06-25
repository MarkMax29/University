#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 99999999

int dist[MAX],viz[MAX],tata[MAX];
void init_vect(int n)
{
    for(int i=1;i<=n;i++)
    {
        viz[i]=0;
        dist[i]=INF;
        tata[i]=-1;
    }
}
void init(int **graf,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graf[i][j]=0;
        }
    }
}

void dijkstra(int **graf,int n,int start)
{
    init_vect(n);

    dist[start]=0;

    for(int contor=1;contor<=n;contor++)
    {
        int u=-1,min=INF;
        for(int i=1;i<=n;i++)
        {
            if(viz[i]==0 && dist[i]<min)
             {
                u=i;
                min=dist[i];
             }
        }

        if(u==-1)
            return;

        viz[u]=1;

        for(int v=1;v<=n;v++)
        {
            if(graf[u][v]!=0 && viz[v]==0 && dist[v]>dist[u]+graf[u][v])
            {
                dist[v]=dist[u]+graf[u][v];
                tata[v]=u;
            }
        }
    }
    printf("Durata productiei e: %d\n",dist[n]);
    int drum[MAX],k=0;
    int curent=n;
    while(curent!=-1)
    {
        drum[k++]=curent;
        curent=tata[curent];
    }
    printf("Drumul de la %d la %d este :",start,n);
    for(int j=k-1;j>=0;j--)
    {
        printf("%d ",drum[j]);
    }
    printf("\n");
}

void afis(int n)
{
    printf("DISTANTE: ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dist[i]);
    }
    printf("\nVIZITATE: ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",viz[i]);

    }
    printf("\nPREDECESOR:");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",tata[i]);
    }
    printf("\n");
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Eroare la arg\n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Eroare la deschidere fis\n");
        exit(-1);
    }

    int n,m;
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&m);

    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("puloc\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("bazdmeg\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    
    
    int a,b,cost;
    init(graf,n);
    for(int i=1;i<=m;i++)
    {
        fscanf(f,"%d %d %d",&a,&b,&cost);
        graf[a][b]=cost;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    dijkstra(graf,n,1);
   // afis(n);

    return 0;
}