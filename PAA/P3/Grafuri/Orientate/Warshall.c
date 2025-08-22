#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int graf[MAX+1][MAX+1];
int reach[MAX+1][MAX+1];

void Warshall(int n)
{
    memset(reach,-1,sizeof(reach));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]!=0 || i==j)//la warshall si daca mergi de la i la i se considera ca e drum deci il notez ca si cum exista drum de la i la i ,adica fiecare nod ajunge la sine
                reach[i][j]=1;
            else
                reach[i][j]=0;
        }
    }
    for(int k=1;k<=n;k++)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(reach[i][k]==1 && reach[k][j]==1)
                {
                    reach[i][j]=1;
                }
            }
        }
    }

    printf("Matricea de accesibilitate: \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",reach[i][j]);
        }
        printf("\n");
    }
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror ("no arg\n");
        exit(-1);
    }
        
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("openning problem\n");
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

    Warshall(n);

    printf("\n\nDrumurile sunt in felul urmator: \n");
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=n;j++)
        {
            if(reach[i][j]!=0)
            {
                printf("%d->%d \n",i,j);
            }
        }
    }
    return 0;
}