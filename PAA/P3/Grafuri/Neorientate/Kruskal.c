#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define INF 9999999
int graf[MAX][MAX];

void kruskal(int n)
{
	int S[MAX];
	for(int i=1; i<=n; i++)
	{
		S[i]=i;
	}
	int cost=0;
	for(int pas=1; pas<n; pas++)
	{
		int min=INF;
		int mini=-1, minj=-1;
		
		for(int i =1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(graf[i][j]!=0 && S[i]!=S[j] && min>graf[i][j])
				{
					min=graf[i][j];
					mini=i;
					minj=j;
				}
			}
		}
        if(mini!=-1 && minj!=-1)
        {
            int set_mini = S[mini];
            int set_minj = S[minj]; 
            
            for(int i=1; i<=n ; i++)
            {
                if(S[i]==set_mini)
                {
                    S[i]=set_minj;
                }
            }
            cost+=graf[mini][minj];
            printf("Muchia adaugata este : %d -> %d (cost= %d)\n",mini,minj,graf[mini][minj]);
        }
    }
		printf("\nCostul minim pentru graf este %d\n", cost);
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

    kruskal(n);
    return 0;
}