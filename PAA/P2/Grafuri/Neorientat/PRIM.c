#include <stdio.h>
#include <stdlib.h>


#define MAX 20
#define INF 999999

int vizitat[MAX+1];
int distanta[MAX+1];
int tata[MAX+1];
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
void init_vectori(int n)
{
    for(int i=0;i<n;i++)
    {
        vizitat[i]=0;
        distanta[i]=INF;
        tata[i]=-1;
    }
}

void PRIM(int **graf,int n,int start)
{
    init_vectori(n);

    distanta[start]=0;

    for(int k=0;k<n-1;k++)
    {
        int u=-1,min=INF;
        for(int i=0;i<n;i++)
        {
            if(vizitat[i]==0 && distanta[i]<min)
            { 
                min=distanta[i]; 
                u=i;
            }
               
        }
    if(u==-1)
    {
        printf("ceva e bai\n");
        return;
    }
        vizitat[u]=1;
        for(int v=0;v<n;v++)
        {
            if(graf[u][v]!=0 && vizitat[v]==0 && graf[u][v]<distanta[v])
            {
                distanta[v]=graf[u][v];
                tata[v]=u;

            }
        }
    }

    int total=0;
    printf("Arborele de acoperire minim va fi alc din muchiile cu costurile:\n");
    for(int i=0;i<n;i++)
    {
        if(tata[i]!=-1)
        {   
            printf("%d -%d (cost=%d)\n",tata[i],i,graf[i][tata[i]]);
            total=total+graf[i][tata[i]];
        }
    }
    printf("Iar costul total este : %d\n",total);
}
int main(int argc,char **argv)
{

    if(argc!=2)
    {
        perror("NOT CORECT ARG!\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at opening!\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("eroare alc puloc\n");
        free(graf);
        exit(-1);
    }

    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("Error at alocating lines!\n");
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
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
        graf[b][a]=cost;
    }
   
    PRIM(graf,n,1);
    
    return 0;
}