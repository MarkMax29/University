#include <stdio.h>
#include <stdlib.h>
#include "citiri.h"
#define MAX 20



///=====PARCURGERE IN ADANCIME=====///
void dfs_adanc(int **graf,int start,int n)
{
    vizitat[start]=1;
    printf("%d ",start);// imi afiseaza cum a trecut prin parcurgerea dfs
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1 && vizitat[i]==0)
        {
            dfs_adanc(graf,i,n);
        }
    }
}


///=======Nr componente conexe======////
void comp_conexe(int **graf,int n)
{
    int comp=0;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
        {
            comp++;
            dfs_adanc(graf,i,n);
        }
    }
    printf("\nNumar componente conexe: %d\n",comp);
}


///====VERIF DACA E CONEX====///
void verif_graf_conex(int n)
{
    int ok=1;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==0)
            {   
                ok=0;
                break;
            }
    }
    if(ok==1)
        printf("GRAFUL ESTE CONEX!\n");
    else
        printf("GRAF NECONEX!\n");
    
}

///===== VERIF DACA EXISTA CICLU====///

int ciclu(int start,int parinte,int **graf,int *vizitat,int n)
{
    vizitat[start]=1;
    for(int i=1;i<=n;i++)
    {
        if(graf[start][i]==1)
        {
            if(vizitat[i]==0)
            {
                if(ciclu(i,start,graf,vizitat,n))
                {

                    return 1;   //practic aici fac parcurgerea dfs pana ajung sa gasesc un nod vizitat
                }
            }
            else if(i!=parinte)
            {
                return 1;// daca e vizitat , si nodul de unde vin (parintele) e diferit de nodul curent(i) atunci am ciclu 
                //practic verifica daca nu merg inapoi pe aceaasi muchie si ca e un ciclu inchis
            }
        }
    }
    return 0;
}


///======VERIF DACA E BIPARTID======////

int bipartid(int **graf,int nod,int culoare,int *vect_culori,int n)
{
    vect_culori[nod]=culoare;

    for(int i=1;i<=n;i++)
    {
        if(graf[nod][i]==1)
        {
            if(vect_culori[i]==-1)
            {
                if(bipartid(graf,i,1-culoare,vect_culori,n)==0)
                    return 0;
            }
            else if(vect_culori[i]==culoare)
                return 0;
        }
    }
    return 1;

}


///=====PARCURGERE IN CUPRINDERE BFS====///
int front=0,end=0;
void push(int *coada,int value)
{
    coada[end++]=value;
}
int queue(int *coada)// cu asta scot un nod din coada
{
    return coada[front++];
}

void cuprindere_bfs(int **graf,int start,int dest,int *coada,int n)
{
    init_vizitat(vizitat,n);
    init_predec(predec,n);

    push(coada,start);
    vizitat[start]=1;

    while(front<end)
    {
        int nod=queue(coada);//am scos primul nod din coada
        if(nod==dest)//daca nodul din coada e cel cautat ies din while
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
    for(int i=1;i<=n;i++)
    {
        printf("%d ",predec[i]);//doar afisez vectorul de predecesori practic predecesorul fiecareui nod 
    }
    printf("\n");
    if(vizitat[dest]==0)
    {
        printf("NU S-A GASIT DRUM CATRE DEST!\n");
        exit(-1);
    }

    int curent=dest,drum[MAX+1],k=0;
    printf("\nDRUM: ");
    while(curent!=-1)
    {
        drum[k++]=curent;
        curent=predec[curent];
    }
    for(int i=k-1;i>=0;i--)
    {
        printf("%d ",drum[i]);//practic e cel mai scurt drum cred 
        
    }
    printf("\n");
}
int main(int argc,char **argv)
{

    if(argc!=2)
    {
        perror("Not correct arguments!\n");
        exit(-1);
    }

    FILE *f=NULL;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Error at opening file!\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

///alocare si pornim cu nodurile de la 1///
    int **graf=(int**)malloc(sizeof(int*)*(n+1));
    if(graf==NULL)
    {
        perror("Error at alocate matrix\n");
        free(graf);
        exit(-1);
    }
    for(int i=0;i<=n;i++)
    {
        graf[i]=(int*)malloc(sizeof(int)*(n+1));
        if(graf[i]==NULL)
        {
            perror("Error at alocating\n");
            for(int j=1;j<=n;j++)
            {
                free(graf[j]);
            }
            free(graf);
            exit(-1);
        }
    }

// daca am citire initial din matrice si afise muchiile //    
/*
   citire_cu_matrice(graf,n,f);
   afis_pe_muchii(graf,n);
*/

//daca am citire de muchii si afisez matricea//
    citire_pe_muchii(graf,f,n);
    afis_matrice_adiacenta(graf,n);

//afisez parcurgerea dfs//
    init_vizitat(vizitat,n);
    
    dfs_adanc(graf,5,n);//imi afiseaza parcurgerea in dfs
  
    printf("\n");
    verif_graf_conex(n);  //practic trebe prima data sa fac dfs ca sa vad ca avem cel putin o muchie intre oricare 2 noduri si doar zice de e conex sau nu 
  
    init_vizitat(vizitat,n);//fut o initiere si merge dupa comp_conex ca sa resetez vizitarea ca se apeleaza practic parcurgerea efectiva dfs in comp_conexe//
    comp_conexe(graf,n); //pentru primu nod nevizitat gasit apeleaza dfs si fce parcurgerea si dupa se intoarce in func comp_conexe si continua 
   


   // verificare ca e ciclu sau nu 
    init_vizitat(vizitat,n);
    if(ciclu(1,-1,graf,vizitat,n)==1)
        printf("GRAFUL CONTINE CICLU!\n");
    else
        printf("GRAFUL N-ARE CICLU\n");



    //Pentru a ferifica daca tot graful e bipartid
    //facem si verificare ca fiecare componenta conexa sa fie 

    for(int i=1;i<=n;i++)//initializare pt vect de culori/vizitat
    {
        vizitat[i]=-1;
    }
    //aici e verif pentru fiecare comp conexa
    int ok=1;
    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==-1)
        {
            if(bipartid(graf,i,0,vizitat,n)==0)
            {
                ok=0;
                break;
            }
        }
    }
    
    if(ok==1)
        printf("GRAF BIPARTID!\n");
    else
        printf("GRAFUL NU E BIPARTID!\n");

    ///==parcurgere in cuprindere///

    int *coada=(int*)malloc(sizeof(int)*(n+1));
    if(coada==NULL)
    {
        perror("Not enough memory!\n");
        exit(-1);
    }
    cuprindere_bfs(graf,1,5,coada,n);
    return 0;
}