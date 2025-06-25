#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct om
{
    char nume[25],gen[2],local[3];
    int id;

}om;
int vizitat[MAX],predecesor[MAX];

void init_vect(int n)
{
    for(int i=1;i<=n;i++)
    {
        vizitat[i]=0;
        predecesor[i]=-1;
    }
}
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
int front=0,end=0;
void push(int *coada,int value)
{
    coada[end++]=value;
}
int queue(int *coada)
{
    return coada[front++];
}
void bfs(int **graf,int n,int start,int *coada,om *vect)
{
    front=0;
    end=0;
    init_vect(n);

    push(coada,start);
    vizitat[start]=1;

    while(front<end)
    {
        int nod=queue(coada);

        for(int i=1;i<=n;i++)
        {
            if(graf[nod][i]==1 && vizitat[i]==0)
            {
                vizitat[i]=1;
                push(coada,i);
                predecesor[i]=nod;
            }
        }
    }

    int cont=0;
    printf("Sugestie de prietenie:");
    for(int i=1;i<=n;i++)
    {
        if(predecesor[predecesor[i]]==start && cont<=3)
        {
            printf("%s ",vect[i].nume);
            cont++;
        }
    }
}
int main(int argc,char**argv)
{
    if(argc!=2)
    {
        perror("arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("file");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    int *coada=(int*)malloc(sizeof(int)*(n+1));
    if(coada==NULL)
    {
        perror("coada\n");
        free(coada);
        exit(-1);
    }

    int **graf=(int**)malloc(sizeof(int*)*n);
    if(graf==NULL)
    {
        perror("puloc\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("bazdmeg\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

    om vect[n+1];
    for(int i=1;i<=n;i++)
    {
        fscanf(f,"%s %s %s",vect[i].nume,vect[i].gen,vect[i].local);
        vect[i].id=i;
    }
    int a,b;
    while(fscanf(f,"%d %d",&a,&b)==2)
    {

        graf[a][b]=1;
        graf[b][a]=1;

        printf("%s prieten cu %s\n",vect[a].nume,vect[b].nume);
    }
    printf("\n\n");
    bfs(graf,n,2,coada,vect);
    printf("\n");
    return 0;
}