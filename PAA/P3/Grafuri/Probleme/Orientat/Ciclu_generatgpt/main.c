#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int graf[MAX+1][MAX+1],vizitat[MAX+1],color[MAX+1];

int dfs(int n,int start)
{
    color[start]=1;
 
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1)
        {
            if(color[i]==0)
            {
                if(dfs(n,i))
                    return 1;
            }
            else if(color[i]==1)
            {
                return 1;
            }
        }
    }

    color[start]=2;
    return 0;
}

int areciclu(int n)
{
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(dfs(n,i))
                return 1;
        }
    }
    return 0;
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
    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
    }

    if(areciclu(n))
        printf("DA\n");
    else
        printf("NU\n");
    return 0;
}