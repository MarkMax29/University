#include <stdio.h>
#include <stdlib.h>

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
void prieten_cu_toti(int **graf,int n)
{
    int in,ext,ok=0;
    for(int i=0;i<n;i++)
    {
        in=0;
        ext=0;
        for(int j=0;j<n;j++)
        {
            if(graf[i][j]!=0)
                ext++;
            else if(graf[j][i]!=0)
                in++;
        }
        if(ext==0 && in==n-1)
            {   
                printf("Persoana care e stiut de toti si nu stie pe nimeni e :%d\n",i);
                ok=1;
            }
        
    }
    if(ok==0)
        printf("Nu exista astfel de persoana\n");
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("arg\n");
        exit(-1);
    }
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("file\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    int **graf=(int**)malloc(sizeof(int*)*n);
    if(graf==NULL)
    {
        perror("puloc\n");
        free(graf);
        exit(-1);
    }

    for(int i=0;i<n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*n);
        if(graf[i]==NULL)
        {
            perror("bazdmeg\n");
            for(int j=0;j<n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
    }
    prieten_cu_toti(graf,n);
    return 0;
}