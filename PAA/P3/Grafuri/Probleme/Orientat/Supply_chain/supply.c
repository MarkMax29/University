#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
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

int reach[MAX+1][MAX+1];

void Warshall(int graf[MAX+1][MAX+1],int n)
{
    memset(reach,0,sizeof(reach));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            reach[i][j]=graf[i][j];
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(reach[i][k]!=0 && reach[k][j]!=0)
                {
                    reach[i][j]=1;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",reach[i][j]);
        }
        printf("\n");
    }
}

void affected(int n,int supplier)
{
    if(supplier > n)
    {
        perror("dont exist\n");
        exit(-1);
    }
    printf("Supllierii pe care iar afecta: ");
    for(int j=1;j<=n;j++)
    {
        if(reach[supplier][j])
            printf("%d ",j);
    }
    printf("\n");
}

// mai am 2 functii de facut dar nici nu inteleg ce si nici nu mai am chef acm sincer
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
        perror("not ok file\n");
        exit(-1);

    }


    int n;
    fscanf(f,"%d",&n);

    int a,b;
    int graf[MAX+1][MAX+1];
    init(graf,n);

    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
    }
    Warshall(graf,n);
    affected(n,1);
    return 0;
}