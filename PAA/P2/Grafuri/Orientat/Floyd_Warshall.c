#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20
#define INF (INT_MAX/2)

int dist[MAX][MAX],traseu[MAX][MAX];
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

void Floyd(int **graf,int n)
{
    //prima data initializez matricea de distanta si traseu
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else if(graf[i][j]!=0)
            {
                dist[i][j]=graf[i][j];
            }
            else
                dist[i][j]=INF;
            traseu[i][j]=-1;

        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    traseu[i][j]=k;
                }
            }
        }
    }
    printf("Distantele minime intre toate nodurile:\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            {
                printf("INF ");
            }
            else
            printf("%3d ",dist[i][j]);
        }
        printf("\n");
    }
}
void drum(int i,int j)  //acesta o sa imi afiseze drumul dar contine doar nodurile intermediare ,nu si pe cele de start/final
{
    if(traseu[i][j]!=-1)
    {
        drum(i,traseu[i][j]);
        printf(" %d ->",traseu[i][j]);
        drum(traseu[i][j],j);
    }
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("eroare arg\n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("eroare file\n");
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
            perror("puloc graf\n");
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
    Floyd(graf,n);

    int start=4,final=3;
    printf("\n\nDrumul de la %d la %d: %d ->",start,final,start);
    drum(start,final);
    printf(" %d\n",final);
    return 0;
}