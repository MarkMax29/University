#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int reach[MAX+1][MAX+1];

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

void Warshall(int graf[MAX+1][MAX+1],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            reach[i][j]=graf[i][j];
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(reach[i][k] && reach[k][j])
                    reach[i][j]=1;
            }
        }
    }
}

int calcul_acces_al_unei_permis(int n,int permis)
{
    int suma=0;
    for(int i=1;i<=n;i++)
        if(i!=permis)
            suma+=reach[permis][i];
    return suma;
}

void permis_cu_acces_maxim(int n)
{
    int maxim=0;
    for(int i=1;i<=n;i++)
    {
        int permis=calcul_acces_al_unei_permis(n,i);
        if(permis>maxim)
            maxim=permis;
    }
printf("Permisiunile cu accesibilitate maxima sunt : ");
    for(int i=1;i<=n;i++)
    {
        int perm=calcul_acces_al_unei_permis(n,i);
        if(perm==maxim)
            printf("%d ",i);
    }
}

void risc_ridicat_securitate(int risc,int n)//risc e dat in input prima linie
{
    printf("Permisiunile care ar face dintr-un angajat unul de risc ridicat de securitate sunt: ");
    for(int i=1;i<=n;i++)
    {
        int total=1;
        for(int j=1;j<=n;j++)
        {
            if(reach[i][j]==1)//toate care au mai multe drumuri adica mai multe de 1 decat risc 
                total++;
        }


        if(total>risc)
        {
            printf("%d ",i);
        }
    }

    printf("\n");
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
        perror("Not openning file\n");
        exit(-1);
    }

    int graf[MAX+1][MAX+1];
    int risc,n;
    fscanf(f,"%d",&risc);
    fscanf(f,"%d",&n);

    init(graf,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
              fscanf(f,"%d",&graf[i][j]);
        }
    }
    Warshall(graf,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",reach[i][j]);
        }
        printf("\n");
    }
      permis_cu_acces_maxim(n);
      printf("\n");
      risc_ridicat_securitate(risc,n);
    return 0;
}