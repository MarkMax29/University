#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
int graf[MAX+1][MAX+1],vizitat[MAX+1];

void dfs(int n,int start)
{
    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1 && vizitat[i]==0)
            dfs(n,i);
    }
}

void nr_comp(int n)
{
    int nr=0;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            dfs(n,i);
            nr++;
            printf("Comp %d: ",nr);
            int num=0;
            for(int j=1;j<=n;j++)
            {
                
                if(vizitat[j]==1)
                {
                    printf("%d ",j);
                    num++;
                    vizitat[j]=-1;
                }
                
            }
            printf(" | cu %d elemente\n",num);
        }
    }

    printf("\n NUMARUL TOTAL DE COMP CONEXE ESTE: %d\n",nr);
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


    memset(graf,0,sizeof(graf));

    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
        graf[b][a]=1;
    }
    memset(vizitat,0,sizeof(vizitat));
    nr_comp(n);
    return 0;
}