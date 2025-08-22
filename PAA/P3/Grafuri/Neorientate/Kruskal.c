#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define INF 9999999
int graf[MAX+1][MAX+1];

void Kruskal(int n)
{
    int s[MAX+1],total=0;
   memset(s,0,sizeof(int)*(MAX+1));
    for(int i=1;i<=n;i++)
    {
        s[i]=i;
    }

    for(int pas=1;pas<n;pas++)
    {
        int min=INF,mini=-1,minj=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]!=0 && s[i]!=s[j] && graf[i][j]<min && j>i)
                {
                    min=graf[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
    if(mini!=-1 && minj!=-1)
     {
        for(int i=1;i<=n;i++)
        {
            if(s[i]==s[minj])
            {
                s[i]=s[mini];
            }
        }
            total+=graf[mini][minj];
            printf("Muchia adaugata este : %d -> %d (cost= %d)\n",mini,minj,graf[mini][minj]);
     }

    }
    printf("Costul total al MST: %d\n",total);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not enough arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not ok at openning file\n");
        exit(-1);
    }

    int n;
    char sir[20];
    fscanf(f,"%s",sir);
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

    Kruskal(n);
    return 0;
}