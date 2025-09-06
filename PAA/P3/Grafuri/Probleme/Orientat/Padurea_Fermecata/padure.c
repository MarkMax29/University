#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 500
#define INF 999999

void init(int **graf,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graf[i][j]=0;
        }
    }
}
int citire(FILE *f)
{
char sir[30];
    fscanf(f,"%s",sir);

    int n=0;
    for(int i=0;i<strlen(sir);i++)
    {
        int ok=1;
        if(isdigit(sir[i]))
        {
            int k=sir[i]-'0';
            for(int d=2;d<k;d++)
            {
                if(k%d==0)
                {
                    ok=0;
                    break;
                }
            }
            if(ok==1)
                n=n+k;
        }
    }

    return n;
}

void citire_graf(FILE *f,int **graf,int n)
{
    init(graf,n);
    char a[4],b[4];
    int R;
    while(fscanf(f,"%s %s %d",a,b,&R)==3)
    {
        int x=(((int)a[0]+(int)a[1]+(int)a[2])%n)+1;
        int y=(((int)b[0]+(int)b[1]+(int)b[2])%n)+1;
        int cost=R%17+1;
        printf("%d %d %d\n",x,y,cost);
        graf[x][y]=cost;
    }
    
}
 int D[MAX+1][MAX+1],traseu[MAX+1][MAX+1];
void Floyd(int **graf,int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                D[i][j]=0;
            else if(graf[i][j]==0)
                D[i][j]=-INF;
            else
                D[i][j]=graf[i][j];
            traseu[i][j]=-1;
        }
    }


    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(D[i][j]<D[i][k]+D[k][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    traseu[i][j]=k;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(D[i][j]==-INF)
                printf("INF ");
            else
                printf("%d ",D[i][j]);
        }
        printf("\n");
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",traseu[i][j]);
        }
        printf("\n");
    }
}

void tras(int i,int j)
{
    if(traseu[i][j]!=-1)
    {
        tras(i,traseu[i][j]);
        printf("%d ",traseu[i][j]);
        tras(traseu[i][j],j);
    }

    //printf(" cost(%d)\n",D[i][j]);
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
        perror("Not ok at openning file\n");
        exit(-1);
    }

    int n=citire(f);
    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("allocation error\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("error at allocating line of matrix\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

    citire_graf(f,graf,n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    Floyd(graf,n);

    int start=1,final=5;
    printf("%d",start);
    tras(1,5);
    printf("%d",final);
    return 0;
}