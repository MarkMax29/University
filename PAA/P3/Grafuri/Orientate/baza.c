#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int graf[MAX+1][MAX+1];
int vizitat[MAX+1];
int trans[MAX+1][MAX+1];
int stiva[MAX+1];//e vector de fapt dar o simulam ca pe o stiva cu LIFO 
int top=0;

void grad_noduri(int n)
{
    for(int i=1;i<=n;i++)
    {
        int ext=0,in=0,grad=0;
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]!=0)
            {
                ext++;
            }
            else if(graf[j][i]!=0)
            {
                in++;
            }
        }
        grad=ext+in;
        printf("Gradul pentru nodul %d este =%d (cu grad int=%d , si ext=%d)\n",i,grad,in,ext);
    }
}

void dfs(int graf[MAX+1][MAX+1],int n,int start)
{
    vizitat[start]=1;
    //printf("%d ",start);
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]!=0 && vizitat[i]==0)
        {
            dfs(graf,n,i);
        }
    }
}

///VERIFICARE TARE CONEX///

int verif_tare_conex(int n,int start)
{
    memset(vizitat,0,sizeof(vizitat));
    dfs(graf,n,start);
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            return 0;
        }
    }

    int transpus[MAX+1][MAX+1];
    memset(transpus,0,sizeof(transpus));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]!=0)
                transpus[j][i]=graf[i][j];
        }
    }
    memset(vizitat,0,sizeof(vizitat));
    dfs(transpus,n,start);
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
            return 0;
    }

    return 1;
    
}

void tare_conex(int n,int start)
{
    if(verif_tare_conex(n,start)==1)
        printf("graful e tare conex\n");
    else
        printf("graful nu e tare conex\n");
}



/// NR COMP TARE CONEXE///

//pentru parcurgerea grafului original si punerea in stiva 
void dfs1(int graf[MAX+1][MAX+1],int n,int start)
{
    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]!=0 && vizitat[i]==0)
            dfs1(graf,n,i);
    }
    stiva[++top]=start;
}


void dfs2(int trans[MAX+1][MAX+1],int n,int start)
{
    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(trans[start][i]!=0 && vizitat[i]==0)
        {
            dfs2(trans,n,i);
        }
    }

}

void nr_comp(int n)
{
    memset(vizitat,0,sizeof(vizitat));
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            dfs1(graf,n,i);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            trans[i][j]=graf[j][i];
        }
    }

    memset(vizitat,0,sizeof(vizitat));
    int nr=0;
    for(int i=top;i>=1;i--)
    {
        int u=stiva[i];
        if(vizitat[u]==0)
        {
            nr++;
            dfs2(trans,n,u);
        }
    }

    printf("nr de comp tare conexe: %d\n",nr);
}


int color[MAX+1];
/// VERIFICARE CICLU IN GRAF ORIENTAT ///

int dfs_ciclu(int nod,int graf[MAX+1][MAX+1],int n,int color[MAX+1])
{
    // 0 (alb) nevizitat
    //1 (gri) in recursie
    //2 (negru) finalizat (am terminat toti vecinii lui)

    color[nod]=1;// il marchez cu 1 adica culoarea gri ceea ce inseamna ca e in recursie nodul acesta
    for(int i=1;i<=n;i++)
    {
        if(graf[nod][i]!=0)
        {
            if(color[i]==0)
            {
                if(dfs_ciclu(i,graf,n,color))
                    return 1;// ciclu gasit undeva in adancime 
            }
            else if(color[i]==1)
            {
                return 1;// am o muchie catre un nod gri inseamna ca am ciclu
            }
        }
    }
    color[nod]=2; //il marcham ca finalizat iam vazut toti vecinii(negru)
    return 0;


}

int areCiclu(int graf[MAX+1][MAX+1],int n)
{
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(dfs_ciclu(i,graf,n,color))
            {
              
                return 1;
            }
        }
    }

    return 0;
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
        perror("not ok at openning file\n");
        exit(-1);
    }

    memset(graf,0,sizeof(graf));
    int n;
    fscanf(f,"%d",&n);
    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }

    grad_noduri(n);

    memset(vizitat,0,sizeof(vizitat));
    dfs(graf,n,1);

    tare_conex(n,1);

    nr_comp(n);


    //Ciclu//

    if(areCiclu(graf,n)==1)
        printf("Graful are ciclu\n");
    else
        printf("N-are ciclu\n");
    return 0;
}