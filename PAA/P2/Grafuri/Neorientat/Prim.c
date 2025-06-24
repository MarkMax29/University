#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 999999999


int vizitat[MAX+1];
int tata[MAX+1];
int dist[MAX+1];
void init_vizitat(int n)
{
    for(int i=0;i<=n;i++)
    {
        vizitat[i]=0;
    }
}
void initializare(int n)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        tata[i]=-1;
    }
}
int** citire(int n,FILE *f)
{
   int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("Eroare alocare\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("eroare la alocare matrice adiacenta\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }

    return graf;
}
void afisare(int **graf,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(graf[i][j]!=0)
            {
                printf("%d %d cost=%d\n",i,j,graf[i][j]);
            }
        }
    }
}

void prim(int **graf,int n,int start)
{
    init_vizitat(n);//pentru vizitat
    initializare(n);//pentru distanta si tata

    //vizitat[start]=1;
    dist[start]=0;

    for(int contor=0;contor<n-1;contor++)
    {
        int u=-1,min=INF;
        for(int i=0;i<n;i++)
        {
            if(vizitat[i]==0 && dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        if(u==-1)
            return;

        vizitat[u]=1;

        for(int v=0;v<n;v++)
        {
            if(graf[u][v]!=0 && vizitat[v]==0 && graf[u][v]<dist[v])
            {
                dist[v]=graf[u][v];
                tata[v]=u;
            }
        }
    }

    int total=0;
    printf("Muchiile dint Arborele de Acoperire Minim:\n");
    for(int i=1;i<n;i++)
    {
        printf("%d - %d(cost: %d)\n",tata[i],i,graf[i][tata[i]]);
        total=total+graf[i][tata[i]];
    }
    printf("\nCost total =%d\n",total);

}
int main(int argc,char ** argv)
{

    if(argc!=2)
    {
        perror("NOT ENOUGH ARG!\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at reading!\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);
    int **graf=citire(n,f);
   
   //afisare(graf,n);
   prim(graf,n,0);
    return 0;
}