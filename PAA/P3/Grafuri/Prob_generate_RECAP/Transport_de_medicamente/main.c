#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
                                                                                
#define MAX 20   
#define INF 999999                                                               
int graf[MAX+1][MAX+1],vizitat[MAX+1];   
int D[MAX+1],predecesor[MAX+1];                                       
                                               
void drum_cheltuieala__min(int n,int start,int dest)
{

    for(int i=0;i<=MAX;i++)
    {
        predecesor[i]=-1;
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
            if(vizitat[v]==0 && graf[u][v]!=0 && graf[u][v]+D[u]<D[v])
            {
                D[v]=D[u]+graf[u][v];
                predecesor[v]=u;
            }
        }
    }

    int drum[n],k=0,curent=dest;

    while(curent!=-1)
    {
        drum[k++]=curent;
        curent=predecesor[curent];
    }

    printf("Drum de la %d la %d: ",start,dest);
    for(int i=k-1;i>=0;i--)
    {
        printf("%d ",drum[i]);
    }
    printf(" | cu costul minim de : %d \n",D[dest]);

}


int main(int argc,char **argv)                                                  
{                                                                               
                                                                                
    if(argc!=2)                                                                 
    {                                                                           
        perror("pl\n");                                                         
        exit(-1);                                                               
    }                                                                           
                                                                                
    FILE *f=fopen(argv[1],"r");                                                 
    if(f==NULL)                                                                 
    {                                                                           
        perror("pz\n");                                                         
        exit(-1);                                                               
    }                                                                           
                                                                                
    int n;                                                                      
    fscanf(f,"%d",&n);   

    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
    }

    drum_cheltuieala__min(n,1,8);
    printf("\n\nVectorul de dist: ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",D[i]);

    }
    printf("\nPredecesorul:    ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",predecesor[i]);
    }
    return 0;
}