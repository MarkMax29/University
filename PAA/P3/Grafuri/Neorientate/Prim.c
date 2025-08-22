#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MIN 999999999
int graf[MAX+1][MAX+1];


void Prim(int n,int start)
{
    int u[MAX+1];
    memset(u,0,sizeof(int)*(MAX+1));

    u[start]=1;
    int suma=0;
    printf("Muchiile din MST:\n");

    for(int pas=1;pas<n;pas++)
    {
        int min=MIN,mini=-1,minj=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]!=0 && u[i]==1 && u[j]==0 && graf[i][j]<min)
                {
                    mini=i;
                    minj=j;
                    min=graf[i][j];
                }
            }
        }
        if(mini!=-1 && minj!=-1)
        {
            suma=suma+min;
            printf("%d -> %d (cost=%d)\n",mini,minj,min);
            u[minj]=1;
        }
    }

    printf("Costul minim al arborelui de acoperire minim este : %d\n",suma);
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
        perror("not ok open file\n");
        exit(-1);
    }
    memset(graf,0,sizeof(graf));

    int n;
    char sir[20];
    fscanf(f,"%s",sir);
    fscanf(f,"%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d ",&graf[i][j]);
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
    Prim(n,1);
    return 0;
}