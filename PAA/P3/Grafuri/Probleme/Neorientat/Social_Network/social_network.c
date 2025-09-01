#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

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
int vizitat[MAX+1];
void dfs(int graf[MAX+1][MAX+1],int n,int start,int *len)
{
    vizitat[start]=1;
    printf("%d ",start);
    (*len)++;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1 && vizitat[i]==0)
        {
            dfs(graf,n,i,len);
        }
    }
}

void grupuri_izolate(int graf[MAX+1][MAX+1],int n)
{
    memset(vizitat,0,sizeof(int)*(n+1));
    int nr=0,max=0,len;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            len=0;
            printf("Grupa %d: ",nr+1);
            dfs(graf,n,i,&len);
            printf("\n");
            nr++;
        }
        if(max<len)
        { 
            max=len;
        }
    }
    printf("\nNumarul de grupe diferite : %d\n",nr);
    printf("Cel mai mare grup de prieteni este de %d persoane\n",max);
}



///pentru cerinta 3 cu pucnte de articulatie///

void dfs2(int graf[MAX+1][MAX+1],int n,int start,int ignor)
{

    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i] && vizitat[i]==0 && i!=ignor)
            dfs2(graf,n,i,ignor);
    }
}
int nr_comp(int graf[MAX+1][MAX+1],int n,int ignor)
{
    int nr=0;
     memset(vizitat,0,sizeof(int)*(n+1));
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0 && ignor!=i)
        {
            dfs2(graf,n,i,ignor);
            nr++;
        }
    }
    return nr;
}

void puncte(int graf[MAX+1][MAX+1],int n)
{


    int comp=nr_comp(graf,n,-1);
    int comp_dp_ignor;
    printf("PUNCTELE DE ARTICULATIE SI MUCHIILE CARE S-AR STERGE:\n");
    for(int i=1;i<=n;i++)
    {
        comp_dp_ignor=nr_comp(graf,n,i);
        if(comp<comp_dp_ignor)
        {
            printf("Punctul %d cu muchiile:\n",i);
            for(int j=1;j<=n;j++)
            {
                if(graf[i][j]==1 )
                printf("%d %d\n",i,j);
            }

        }
    }
}
int main(int argc,char **argv)
{

    if(argc!=2)
    {
        perror("not good arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not ok arg\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);


    int graf[MAX+1][MAX+1];
    init(graf,n);

    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
        graf[b][a]=1;
    }

   
    grupuri_izolate(graf,n);
    puncte(graf,n);
    return 0;
}