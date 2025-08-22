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
void citire_muchii(int **graf,FILE *f)
{
    int a,b;
    while(fscanf(f,"%d %d ",&a,&b)==2)
    {
        graf[a][b]=1;
        graf[b][a]=1;
    }
}
void citire_matrice(int **graf,FILE *f,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d ",&graf[i][j]);
        }
    }
}
void afis_matrice(int **graf,int n)
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
void afis_muchii(int **graf,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(graf[i][j]!=0)
            {
                printf("%d -> %d\n",i,j);
            }
        }
    }
}