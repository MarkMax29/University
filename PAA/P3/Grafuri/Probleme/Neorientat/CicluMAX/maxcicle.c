#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int maxim=0;
int stiva[100],top=0;

void dfs_ciclu_max(int graf[MAX+1][MAX+1],int vizitat[MAX+1],int n,int start,int parinte)
{
    vizitat[start]=1;
    stiva[top++]=start;

    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1)
        {
            if(vizitat[i]==0)
                dfs_ciclu_max(graf,vizitat,n,i,start);
            else if(i!=parinte)
            {
                int length=0;
                for(int j=top-1;j>=0;j--)
                {
                    length++;
                    if(stiva[j]==i)
                        break;  
                }

                if(length>maxim)
                    maxim=length;
            }
        }
    }
    top--;
    vizitat[start]=2;
}

void afis_lung(int graf[MAX+1][MAX+1],int vizitat[MAX+1],int n)
{

    maxim=0;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
            dfs_ciclu_max(graf,vizitat,n,i,-1);
    }

    if(maxim!=0)
        printf("Lungimea celui mai lung ciclu e:%d\n",maxim);
    else
        printf("Nu exista ciclu\n");
}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("not ok\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("open file error \n");
        exit(-1);
    }

    int graf[MAX+1][MAX+1];
    memset(graf,0,sizeof(graf));

    int n;
    fscanf(f,"%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }


    int vizitat[MAX+1];
    memset(vizitat,0,sizeof(vizitat));
    afis_lung(graf,vizitat,n);

    return 0;
}