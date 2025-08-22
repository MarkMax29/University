#include <stdio.h>
#include <stdlib.h>
#include "citiri.h"
#include <string.h>
#define MAX 20
void grad_noduri_gmax_gmin(int **graf,int n)
{
    int maxi=-1,mini=99999999;
    int nod_max=-1,nod_min=-1;
    for(int i=1;i<=n;i++)
    {
        int nr=0;
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]!=0)
            nr++;
        }
        if(maxi<nr)
        {
            maxi=nr;
            nod_max=i;
        }
        if(mini>nr)
        {
            mini=nr;
            nod_min=i;
        }
        printf("Nodul %d are gradul %d\n",i,nr);
    }

    printf("\nNodul cu grad maxim e %d cu gradul %d\n",nod_max,maxi);
    printf("Nodul cu grad minim e %d cu gradul %d\n",nod_min,mini);
}

void dfs(int **graf,int start,int *vizitat,int n)
{
    vizitat[start]=1;//il marchez ca vizitat pe nodul de start
    //printf("%d ",start);

    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1 && vizitat[i]==0)//de aia e graf[start][i] pentru ca iau toti vecinii ai lui start
         dfs(graf,i,vizitat,n);  //deci practic iau toti vecinii nevizitati ai nodului curent si merg recursiv pana parcurg graful 
    }
}


void verif_conex(int **graf,int n,int start,int *vizitat)
{
    dfs(graf,start,vizitat,n);
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            printf("Graful nu e conex!\n");
            return;
        }
    }
    printf("Graful este conex\n");
}

void nr_comp_conex(int **graf,int n,int *vizitat)
{
    int nr=0;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            nr++;
            dfs(graf,i,vizitat,n);
        }
    }
    printf("Nr de comp conexe: %d\n",nr);
}


void izolate(int **graf,int n)
{
    int ok=0;
    printf("Noduri izolate: ");
    for(int i=1;i<=n;i++)
    {
        ok=0;
        for(int j=1;j<=n;j++)
        {
            if(graf[i][j]==1 && i!=j)
            {
                ok=1;
                break;
            }

        }
        if(ok==0)
        {
            printf("%d ",i);
        }
    }
}

int detect_ciclu(int **graf,int *vizitat,int start,int n,int parinte)
{
    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1)
        {
           if(vizitat[i]==0)
            {
                if(detect_ciclu(graf,vizitat,i,n,start))//ca sa nu tot mearga recursia daca gaseste in interiorul recursiei un ciclu si sa se opreasca
                {
                    return 1;
                }
            }
            else if(i!=parinte)//ca sa verfic ca nu considera un ciclu de la i la j si inapoi dci sa fie min 3 noduri implicate i guess 
            {
                return 1;
            }
        }
    }
    return 0;
}


int end=0,front=0;
void push(int *coada,int value)
{
    coada[end++]=value;
}

int queue(int *coada)
{
    return coada[front++];
}


void bfs(int **graf,int *coada,int n,int start,int dest,int *vizitat,int *predec)
{
    memset(vizitat,0,sizeof(int)*(n+1));
    memset(predec,-1,sizeof(int)*(n+1));

    vizitat[start]=1;
    push(coada,start);
    while(front<end)
    {
        int nod=queue(coada);
        if(nod==dest)
            break;
        for(int i=1;i<=n;i++)
        {
            if(graf[nod][i]==1 && vizitat[i]==0)
            {
                vizitat[i]=1;
                push(coada,i);
                predec[i]=nod;
            }
        }
    }

    if(vizitat[dest]==0)
    {
        perror("NU S-A GASIT NODUL IN GRAF\n");
        return;
    }
    printf("Drumul :");
    int drum[MAX+1],curent=dest,k=0;
    while(curent!=-1)
    {
        drum[k++]=curent;
        curent=predec[curent];
    }

    for(int i=k-1;i>=0;i--)
    {
        printf("%d ",drum[i]);
    }
    printf("\n");
}



///PUNCTE DE ARTICULATIE///

//Vom avea 3 functii : 1 pt a verifica cate comp conexe avem,1 pt parcurgrea dfs si unu care imi determina apeland celelate 2 functii care sunt puncte de articulatie
//Practic v3erificam pe rand fiecare nod daca "l-am sterge"(de fapt doar il ignoram in parcurgere), daca nr de comp conexe ar creste fata de cel initial si daca da inseamna ca e punct de articulatie.


void dfs_special(int **graf,int *vizitat,int n,int start,int nod_ignor)
{

    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=nod_ignor && graf[start][i]!=0 && vizitat[i]==0)
        {
            dfs_special(graf,vizitat,n,i,nod_ignor);
        }
    }
}

int comp_conex_special(int **graf,int *vizitat,int n,int nod_ignor)
{
    memset(vizitat,0,sizeof(int)*(n+1));
    int nr=0;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0 && i!=nod_ignor)
        {
            dfs_special(graf,vizitat,n,i,nod_ignor);
            nr++;
        }

    }
    return nr;

}

void puncte_de_articulatie(int **graf, int *vizitat,int n)
{
    int nr_comp_conexe_init=comp_conex_special(graf,vizitat,n,-1);
    printf("Punctele de articulatie sunt: ");
    for(int i=1;i<=n;i++)
    {
        int comp_conexe_per_nod_sters=comp_conex_special(graf,vizitat,n,i);
        if(nr_comp_conexe_init<comp_conexe_per_nod_sters)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
}


/// VERIFICARE DE E BIPARTID ///

/*int end=0,front=0;

void push(int *coada,int value)
{
    coada[end++]=value;
}
int queue(int *coada)
{
    return coada[front++];
}
*/
int bipartid(int **graf, int *vizitat, int *coada, int n, int start) 
{

    end = 0;
    front = 0;   //reinitializam aici ca sunt declarate global deja la bfs 
    int culoare[n + 1];
    memset(culoare, -1, sizeof(int) * (n + 1));

    culoare[start] = 0;
    vizitat[start] = 1;
    push(coada, start);

    while (front < end) 
    {
        int nod = queue(coada);
     
        for (int i = 1; i <= n; i++) 
        {
            if (graf[nod][i] == 1) 
            {
                if (culoare[i] == -1) 
                {
                    culoare[i] = !culoare[nod];
                    vizitat[i] = 1;
                    push(coada, i);
                } 
                else if (culoare[i] == culoare[nod]) 
                {
                    return 0; // conflict de culoare între vecini
                }
            }
        }
    }

    return 1;
}


void e_bipartid(int **graf,int *vizitat,int *coada,int n)
{
    memset(vizitat,0,sizeof(int)*(n+1));

    int bipartid_ok=1;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        { 
            if(bipartid(graf,vizitat,coada,n,i)==0)
            {
                bipartid_ok=0;
                break;
            }
        }    
        
    }

    if(bipartid_ok==1)
        printf("GRAFUL ESTE BIPARTID\n");
    else
        printf("GRAFUL NU E BIPARTID\n");
}



    ////BICONEX//// AVEM CA UN GRAF E BICONEX DACA PRACTIC NU AVEM PUNCTE DE ARTICULATIE ADICA DACA PRIN STERGEREA ORICARUI NOD NU IMPARTIM GRAFUL IN MAI MULTE COMPONENTE CONEXE 
    
void biconex(int **graf,int *vizitat,int n)
{
    int comp_init=comp_conex_special(graf,vizitat,n,-1);
    int ok=1;
    for(int i=1;i<=n;i++)
    {
        int comp_cu_nod_sters=comp_conex_special(graf,vizitat,n,i);
        if(comp_init<comp_cu_nod_sters)
        {
            ok=0;
            break;
        }
    }
    if(ok==1)
        printf("GRAFUL E BICONEX\n");
    else
        printf("GRAFUL NU E BICONEX\n");

}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Hopa nu-s bune argumentele\n");
        exit(-1);
    }

    FILE *f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("error at reading file\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d ",&n);
    
    /// ALOCARE DINAMINCA///     // se face cand nu stiu exact cate noduri am.De ex la P2 s-a dat in fisier n=1000 deci declaram global graf[MAX+1][MAX+1] si nu mai aveam de facut alocarea.
    
    int **graf=(int **)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("Error at alloc\n");
        free(graf);
        exit(-1);
    }


    for(int i=0;i<=n;i++)
    {
        graf[i]=(int *)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("Not ok at alocate\n");
            for(int j=0;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }
    
    
    ///INITIALIZARE///

    int vizitat[n+1];
    memset(vizitat,0,sizeof(vizitat));// imi initializeaza vectorul mult mai simplu decat sa fac o functie ///
    init(graf,n);
    
    
    ///CITIRI+AFISARI///
    /*
    citire_muchii(graf,f);
    afis_matrice(graf,n);
    */

    citire_matrice(graf,f,n);
    afis_muchii(graf,n);

   
    ///GRADURILE NODURILOR+GRAD MAX+GRAD MIN///
    grad_noduri_gmax_gmin(graf,n);

    ///PARCURGERE IN ADANCIME (DFS)///
    printf("\n");
    dfs(graf,1,vizitat,n);

    ///VERIFICARE DE E CONEX///
    printf("\n");
    verif_conex(graf,n,1,vizitat);


 
    ///NR COMP CONEXE ///
    printf("\n");   
    memset(vizitat,0,sizeof(vizitat));//trebe sa reinitializez vizitat doar daca l-am mai completat odata la verificare de conexivitate sau ceva de genu altfel mere fara 
    nr_comp_conex(graf,n,vizitat);


    ///NODURI IZOLATE///
     printf("\n");   
    izolate(graf,n);
    printf("\n");

    //VERIF DACA E CICLU///
    memset(vizitat,0,sizeof(vizitat));
    if(detect_ciclu(graf,vizitat,1,n,-1))
    {
        printf("Exista ciclu in graf\n");
    }
    else
    {
            printf("NU E CICLU\n");
    }


    ///BFS///
    int predec[MAX+1],*coada;
    coada=(int *)malloc(sizeof(int)*(n+1));
    if(coada==NULL)
    {
        perror("Not enough memory\n");
        exit(-1);
    }

    bfs(graf,coada,n,1,10,vizitat,predec);


    /// PUNCTE DE ARTICULATIE ///
        printf("\n");
        memset(vizitat,0,sizeof(int)*(n+1));
        puncte_de_articulatie(graf,vizitat,n);

    /// VERIFICARE DE E BIPARTID///

        printf("\n");
        memset(vizitat,0,sizeof(int)*(n+1));
        e_bipartid(graf,vizitat,coada,n);


    /// VERIFICARE DE E BICONEX///

        printf("\n");
        memset(vizitat,0,sizeof(int)*(n+1));
        biconex(graf,vizitat,n);

        return 0;
}
