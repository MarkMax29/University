#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
int graf[MAX+1][MAX+1];


void jucator(int n)
{
    int scor[n+1];
    memset(scor,0,sizeof(scor));
    int k;
    if(n<3)
        k=n;
    else
        k=3;
    for(int i=1;i<=n;i++)
    {
        int ext=0;
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]==1)
                ext++;
        }

        scor[i]=ext;
    }
    
    for(int j=0;j<k;j++)
    {
        int max=0,max_poz=-1;
        for(int i=1;i<=n;i++)
        {
            if(max<scor[i])
            {
                max=scor[i];
                max_poz=i;
            }
        }
        if(max_poz==-1)
            break;
        scor[max_poz]=-1;
        printf("jucator: %d, scor: %d\n",max_poz,max);
    }
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
        perror("Not ok openning file\n");
        exit(-1);
    }

    memset(graf,0,sizeof(graf));

    int n;
    fscanf(f,"%d",&n);

    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
    }

    jucator(n);

    return 0;
}