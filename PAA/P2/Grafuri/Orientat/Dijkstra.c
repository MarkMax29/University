#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 99999999


int vizitat[MAX+1],distanta[MAX+1],tata[MAX+1];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        vizitat[i]=0;
        distanta[i]=INF;
        tata[i]=-1;
    }
}
void init_graf(int **graf,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graf[i][j]=0;
        }
    }
}
void Dijkstra(int **graf,int n,int start)
{
    init(n);

    distanta[start]=0;

    for(int contor=0;contor<n;contor++)
    {
        int u=-1,min=INF;

        for(int i=0;i<n;i++)
        {
            if(vizitat[i]==0 && distanta[i]<min)
            {
                u=i;
                min=distanta[i];
            }

        }
        if(u==-1)
            return;
        vizitat[u]=1;

        for(int v=0;v<n;v++)
        {
            if(graf[u][v]!=0 && vizitat[v]==0 && distanta[u]+graf[u][v]<distanta[v])
            {
                distanta[v]=distanta[u]+graf[u][v];
                tata[v]=u;
            }
        }
    }

    printf("\nDistante minime de la start %d:\n\n",start);
    for(int i=0;i<n;i++)
    {
        if(distanta[i]==INF)
        {
            printf("Nodu %d e inaccesibil\n",i);
        }
        else
        {
            printf("Costul pana la nodul %d e: %d | Drumul: ",i,distanta[i]);
            int drum[MAX],k=0;
            int current=i;
            while(current!=-1)
            {
                drum[k++]=current;
                current=tata[current];
            }
            for(int j=k-1;j>=0;j--)
            {
                printf("%d ",drum[j]);
            }
            printf("\n");
        }
    }
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("arg problem\n");
        exit(-1);
    }
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("file prob\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

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
            perror("na ghinion\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    init_graf(graf,n);
    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
    }

    Dijkstra(graf,n,0);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("%d ",graf[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\n\nDistanta: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",distanta[i]);
    }
    printf("\nVizitat: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",vizitat[i]);
    }
    printf("\nTata: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",tata[i]);
    }
    printf("\n");
return 0;
}