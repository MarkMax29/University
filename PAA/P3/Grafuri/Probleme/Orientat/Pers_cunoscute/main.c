#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void cunoscuti(int **graf,int n)
{
    int ok=0,pers=-1,in=0,ext=0;
    for(int i=1;i<=n;i++)
    {
         in=0,ext=0;
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]==1)
                ext++;
            else if(graf[j][i]==1)
                in++;
        }
        if(in==n-1 && ext==0)
            {
                ok=1;
                pers=i;
            }
    }

    if(ok==1)
        printf("Persoana cunoscuta de toti si cel care nu cunoaste pe nimeni e : %d\n",pers);
    else
        printf("Nu exista astfel de pers!\n");
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("not ok arg\n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("not ok file\n");
        exit(-1);
    }

       int n;
    fscanf(f,"%d ",&n);

    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("not ok allocate\n");
        free(graf);
        exit(-1);
    }

    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("not ok\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    
    //nu fac cu memset ca se fute daca fac alocare dinamica deci initializare simpla 
   // memset(graf,0,sizeof(int)*(n+1));

 init(graf,n);
    
    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
    printf("\n");
  cunoscuti(graf,n);


    return 0;
}