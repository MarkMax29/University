#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int graf[MAX+1][MAX+1];
void init(int n,int a[MAX+1][MAX+1])
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
}
void complement(int n,int graf[MAX+1][MAX+1])
{
    int compl[MAX+1][MAX+1];
    init(n,compl);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
                
            if(graf[i][j]==0 && i!=j)
                compl[i][j]=1;
            else
                compl[i][j]=0;

        }
    }

     printf("Graf complementar:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",compl[i][j]);
        }
        printf("\n");
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
        perror("error opennign\n");
        exit(-1);
    }


    int n;
    fscanf(f,"%d",&n);

    

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }
    }
    printf("Graf original: \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");

    }
   
    complement(n,graf);


    


    return 0;
}