#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 9999999

void init(int graf[MAX+1][MAX+1],int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graf[i][j]=0;
        }
    }
}
int vizitat[MAX+1];
void PRIM(int graf[MAX+1][MAX+1],int n,int start)
{
    //memset(vizitat,0,sizeof(vizitat));
    int u[MAX+1];
    memset(u,0,sizeof(u));

    int total=0;
    u[start]=1;
    for(int pas=1;pas<=n;pas++)
    {
        int min=INF,mini=-1,minj=-1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]!=0 && u[i]!=u[j] && min>graf[i][j])
                {
                    min=graf[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }

        if(mini!=-1 && minj!=-1)
        {
            printf("Muchia : %d -> %d (cost=%d)\n",mini,minj,min);
            total+=min;
            u[mini]=1;
            u[minj]=1;

        }
    }
    printf("\n====Costul total min: %d ====\n",total);
}

void Kruskal(int graf[MAX+1][MAX+1],int n)
{
    int s[MAX+1];
    for(int i=1;i<=n;i++)
    {
        s[i]=i;
    }

    int total=0;
    for(int pas=1;pas<n;pas++)
    {
        int min=INF,mini=-1,minj=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]!=0 && s[i]!=s[j] && min>graf[i][j])
                {
                    min=graf[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }

        if(mini!=-1 && minj!=-1)
        {
            int vechi=s[mini];
            int nou=s[minj];
            for(int i=1;i<=n;i++)
            {
                if(s[i]==vechi)
                {
                    s[i]=nou;
                }
            }

            total+=min;
            printf("Muchia : %d -> %d (cost=%d)\n",mini,minj,min);


        }
    }

    printf("\n ====Cost total min: %d ====\n",total);
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
        perror("Not openning file\n");
        exit(-1);
    }

    int graf[MAX+1][MAX+1];
    int n;

    fscanf(f,"%d",&n);

    init(graf,n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }

    printf("PRIM:\n");
    PRIM(graf,n,1);

    printf("\n\nKRUSKAL: \n");
    Kruskal(graf,n);
    return 0;
}