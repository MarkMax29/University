
#define MAX 20
int vizitat[MAX+1];
int predec[MAX+1];
void init_matrice(int **graf,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graf[i][j]=0;
        }
    }
}
void init_vizitat(int *vizitat,int n)
{
    for(int i=0;i<=n;i++)
    {
        vizitat[i]=0;
    }
}
void init_predec(int *predec,int n)
{
    for(int i=0;i<=n;i++)
    {
        predec[i]=-1;
    }
}
void citire_pe_muchii(int **graf,FILE *f,int n)
{
    init_matrice(graf,n);
    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
        graf[b][a]=1;
    }
}
void citire_cu_matrice(int **graf,int n,FILE *f)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            fscanf(f,"%d",&graf[i][j]);
        }

    }
}
void afis_pe_muchii(int **graf,int n)
{
    for(int i=0;i<=n;i++)
     {
        for(int j=i+1;j<=n;j++)
            {
                if(graf[i][j]==1)
                {
                    printf("%d - %d\n",i,j);
                }
            }
    }
        
}
void afis_matrice_adiacenta(int **graf,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
}
