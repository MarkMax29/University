#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 9999999

int graf[MAX+1][MAX+1];
int dist[MAX+1][MAX+1],traseu[MAX+1][MAX+1];

void init(int n)
{
    for(int i=0;i<=MAX;i++)
    {
        for(int j=0;j<=MAX;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else if(graf[i][j]!=0)
                dist[i][j]=graf[i][j]; 
            else
                dist[i][j]= INF;
            traseu[i][j]=-1;
        }
    }
}

void Floyd(int n)
{
    init(n);
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    traseu[i][j]=k;
                }
            }
        }
    }

    printf("Distantele minime sunt :\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==INF)
                printf("INF ");
            else
                printf("%3d ",dist[i][j]);
        }
        printf("\n");
    }
}

void drum(int i,int j)
{

    if(traseu[i][j]!=-1)
    {
        drum(i,traseu[i][j]);
        printf("%d ",traseu[i][j]);
        drum(traseu[i][j],j);
    }
}


int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("no good arg\n");
        exit(-1);

    }
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("not openning file \n");
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

    Floyd(n);
    int start=1,final=6;
    printf("Drum de la %d la %d : %d ",start,final,start);
    drum(start,final);
    printf("%d \n",final);
    return 0;
}

