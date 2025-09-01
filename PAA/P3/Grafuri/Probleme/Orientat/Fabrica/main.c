#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define INF 999999

int graf[MAX+1][MAX+1];
int D[MAX+1],predec[MAX+1],vizitat[MAX+1];

void Dijkstra(int n,int start)
{
    memset(vizitat,0,sizeof(vizitat));
    for(int i=1;i<=n;i++)
    {
        D[i]=INF;
        predec[i]=-1;
    }

    D[start]=0;
    for(int pas=1;pas<=n;pas++)
    {
        int min=INF,u=-1;
     
        for(int i=1;i<=n;i++)
        {  
            if(vizitat[i]==0 && D[i]<min)
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
            if(graf[u][v]!=0 && vizitat[v]==0 && D[v]>D[u]+graf[u][v])
            {
                D[v]=D[u]+graf[u][v];
                predec[v]=u;
            }
        }
    }

    int drum[n],k=0,curent=n;
    while(curent!=-1)
    {
        drum[k++]=curent;
        curent=predec[curent];
    }
    printf("Timpul scurs de la inceperea functionarii sectiei 1 pana la sosirea produselor la sectia %d este: %d\n",n,D[n]);
    printf("Drumul este: ");
    for(int i=k-1;i>=0;i--)
    {
        printf("%d ",drum[i]);
    }
    printf("\n");
    

//astea nus obligatorii]

/*
    for(int i=1;i<=n;i++)
    {
        printf("%d ",D[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",predec[i]);
    }
    printf("\n");
    */
   
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
        perror("Not good openning file\n");
        exit(-1);
    }

  
    memset(graf,0,sizeof(graf));

    int n,a,b,cost;

    fscanf(f,"%d",&n);
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
    }



    Dijkstra(n,1);
    return 0;
}