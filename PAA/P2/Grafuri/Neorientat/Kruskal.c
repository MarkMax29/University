#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define INF 99999999
void init(int **graf,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graf[i][j]=0;
        }
    }
} 

void Kruskal(int **graf,int n)
{
    int s[MAX],total=0;
    int muchii_folosite[MAX][MAX]={0};//o matrice copie practic unde marchez ce muchii sau folosit pana in momentul de fata ca sa nu se repete cand afisez muchiile de la MST
   
    for(int i=0;i<n;i++)
    {
        s[i]=i;//initializez fiecare componenta (adica fiecare nod e o componenta initial)
    }
    for(int contor=0;contor<n-1;contor++)
    {
        int min=INF,mini=-1,minj=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graf[i][j]!=0 && s[i]!=s[j] && graf[i][j]<min && muchii_folosite[i][j]==0)
                {
                    min=graf[i][j];
                    mini=i;
                    minj=j;
                  
                }
            }

        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[minj])
            {
                s[i]=s[mini];
            }
        }
        if(mini!=-1 && minj!=-1)
            {
                printf("Muchie adaugate: %d - %d (cost= %d)\n",mini,minj,graf[mini][minj]);
                total=total+graf[mini][minj];
                muchii_folosite[mini][minj]=1;
                muchii_folosite[minj][mini]=1;
            }

    }
    printf("Costul MST: %d\n",total);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("arg problem\n");
        exit(-1);
    }
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("file problem\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("aloc puloc\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("puloc\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

    init(graf,n);
    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
        graf[b][a]=cost;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }

    Kruskal(graf,n);

    return 0;
}