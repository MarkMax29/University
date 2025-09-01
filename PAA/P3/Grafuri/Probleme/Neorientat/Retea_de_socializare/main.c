#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct Utilizator{
    char nume[20];
    char gen[2];
    int id;
    char local[15];
}Utilizator;

int graf[MAX+1][MAX+1];
int vizitat[MAX+1];

int end=0,front=0;
void push(int *coada,int value)
{
    coada[end++]=value;
}

int queue(int *coada)
{
    return coada[front++];
}

void bfs(int prieten,int n,int *coada,Utilizator *v)
{
    memset(vizitat,0,sizeof(vizitat));
    
    int dist[n];//petru a vedea la ce nivel de adancime suntem adica prietenii prieteniilor prietenilor....
    memset(dist,0,sizeof(int)*(n+1));

    int vect[n],c=1;// parcurgerea in cuprindere doar ca sa pot sa iau distanta la copilu corect 
    memset(vect,0,sizeof(int)*(n+1));
    
    vizitat[prieten]=1;
    dist[prieten]=0;
    vect[c++]=prieten;
    push(coada,prieten);
    
    
   int nr=0;
    while(front<end)
    {
        int nod=queue(coada);
        
        for(int i=1;i<=n;i++)
        {
            if(graf[nod][i]!=0 && vizitat[i]==0)
            {
                dist[i]=dist[nod]+1;
                vizitat[i]=1;
                push(coada,i);                
                vect[c++]=i;
            }
        }

    }

    for(int i=1;i<=n;i++)
    {
      
        if(dist[vect[i]]>=2)
        {
            if(nr!=3)
            {
                    printf("%d %s %s %s\n",v[vect[i]].id,v[vect[i]].nume,v[vect[i]].gen,v[vect[i]].local);
                    nr++;
            }
            else
                    return;
        }
    }
    
}
int main(int argc,char ** argv)
{
    if(argc!=2)
    {
        perror("Not ok arg\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Not ok at openning\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d ",&n);

   
    Utilizator *v;
    v=malloc(sizeof(Utilizator)*(n+1));
    if(v==NULL)
    {
        perror("nt ok\n");
        exit(-1);
    }

    for(int i=1;i<=n;i++)
    {
        char name[20],loc[15],sex[2];
        if(fscanf(f,"%s %s %s",name,sex,loc)!=3)
        {
            perror("smth went wrong\n");
            exit(-1);
        }
        v[i].id=i;
        strcpy(v[i].nume,name);
        strcpy(v[i].gen,sex);
        strcpy(v[i].local,loc);
        
    }

    int a,b;
    memset(graf,0,sizeof(graf));
    while(fscanf(f,"%d %d",&a,&b)==2)
    {
        graf[a][b]=1;
        graf[b][a]=1;
    }

    int *coada=(int*)malloc(sizeof(int)*(n));
    if(coada==NULL)
    {
        perror("NOt ok queue\n");
        exit(-1);
    }
    

    //problema
    bfs(2,n,coada,v);
 

    return 0;
}