#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define INF 999999
double drum[MAX+1][MAX+1];  
int traseu[MAX+1][MAX+1];


void Floyd(int n,double graf[MAX+1][MAX+1],int *mini,int *minj,double *maxim)
{
    for(int i=0;i<=MAX;i++)
    {
        for(int j=0;j<=MAX;j++)
        {
            if(i==j)   
                 drum[i][j]=0;
            else if(graf[i][j]==0)
                drum[i][j]=INF;
            else
                drum[i][j]=graf[i][j];

            traseu[i][j]=-1;
        }
    }
    

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(drum[i][j]>drum[i][k]+drum[k][j])
                {
                    drum[i][j]=drum[i][k]+drum[k][j];
                    traseu[i][j]=k;
                }
            }
        }
    }



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(*maxim<drum[i][j] && drum[i][j]!=INF)
            {
                *maxim=drum[i][j];
                *mini=i;
                *minj=j;
            }
        }
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
        perror("Openning fail\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    double graf[MAX+1][MAX+1];
    memset(graf,0,sizeof(graf));

    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost*(1.00/3.00);
    }

    printf("Initial:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%.2f ",graf[i][j]);
        }
        printf("\n");

    }

    double maxim=0;
    int mini=-1,minj=-1;
  
    Floyd(n,graf,&mini,&minj,&maxim);

    printf("\nMatrice de drumuri:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(drum[i][j]==INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%.2f ",drum[i][j]);
                
            }
        
        }
        printf("\n");
    }

    printf("\n");
    printf("Drumul cel mai periculos: %d ",mini);
    tras(mini,minj);
    printf("%d cu rata de infectare de : %.2f\n",minj,maxim);

  
    return 0;



}