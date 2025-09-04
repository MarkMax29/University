#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod{
    int key;
    struct Nod *st;
    struct Nod *dr;
}Nod;


Nod *creaza(int val)
{
    Nod *nou=(Nod*)malloc(sizeof(Nod));
    if(nou==NULL)
    {
        perror("eroare la alocare\n");
        exit(-1);
    }
    nou->key=val;
    nou->st=NULL;
    nou->dr=NULL;

    return nou;
}

void insereaza(Nod **rad,int val)
{
    if(*rad==NULL)
    {
        *rad=creaza(val);
        return;
    }

    if(val<(*rad)->key)
        insereaza(&(*rad)->st,val);
    else
        insereaza(&(*rad)->dr,val);
}


void preordine(Nod *rad)
{
    if(rad==NULL)
        return;
    printf("%d ",rad->key);
    preordine(rad->st);
    preordine(rad->dr);
}
void inordine(Nod *rad)
{
    if(rad==NULL)
        return;
    inordine(rad->st);
    printf("%d ",rad->key);
    inordine(rad->dr);
}

void postordine(Nod *rad)
{
    if(rad==NULL)
        return;
    postordine(rad->st);
    postordine(rad->dr);
    printf("%d ",rad->key);
}


int end=0,front=0;

void push(Nod **coada,Nod *val)
{
    coada[end++]=val;
}
Nod *queue(Nod **coada)
{
    return coada[front++];
}

void bfs(Nod *rad)
{
    if(rad==NULL)
    {
        printf("Arbore vid\n");
        return;
    }

    Nod *coada[100];
    end=0,front=0;
    push(coada,rad);

    while(front<end)
    {
        Nod *nod=queue(coada);

        printf("%d ",nod->key);
        if(nod->st!=NULL)
        {
           push(coada,nod->st);
        }
        if(nod->dr!=NULL)
        {
            push(coada,nod->dr);
        }
    }
    printf("\n");
}

///Stergerea dupa X///

Nod *maxim(Nod *rad)
{
    while(rad->dr!=NULL)
    {
        rad=rad->dr;
    }
    return rad;
}

Nod *stergere(Nod *rad,int x)
{
    if(rad==NULL)
        return rad;

    if(x<rad->key)
        rad->st=stergere(rad->st,x);
    else if(x>rad->key)
        rad->dr=stergere(rad->dr,x);
    else
    {
        //cazul in care n-are copii
        if(rad->st==NULL && rad->dr==NULL)
        {
            free(rad);
            return NULL;
        }//cazul cu un copil st sau dr
        else if(rad->st==NULL)
        {
            Nod *aux=rad->dr;
            free(rad);
            return aux;
        }
        else if(rad->dr==NULL)
        {
            Nod *aux=rad->st;
            free(rad);
            return aux;
        }
        else //caz cu 2 copii iau cel mai mare predecesor (adica ultimul din subarborele stang in parcurgerea in inordine) si il inlocuiesc cu nodul curent si apelez stergerea pe el 
        {
            Nod *pred=maxim(rad->st);
            rad->key=pred->key;
            rad->st=stergere(rad->st,pred->key);

        }
    }

    return rad;
}


int compar(const void *elem1,const void *elem2)
{
    int *e1=(int*)elem1;
    int *e2=(int*)elem2;

    if(*e1>*e2)
        return 1;
    else if(*e1<*e2)
        return -1;
    return 0;
}

Nod *inaltMin(int *v,int st,int dr)// asa e inserarea pentru arbore de inaltime minima pentru arbore binar ordonat 
{
    if(st>dr)
        return NULL;
   

    int mij=st+(dr-st)/2;
    Nod *nod_rad=creaza(v[mij]);//creez radacina 
    nod_rad->st=inaltMin(v,st,mij-1);//apelez pentru jumatatea din stanga sa pot pune mijlocul jumatatii din stanga la stanga radacinii
    nod_rad->dr=inaltMin(v,mij+1,dr);

    return nod_rad;

}
int adancimeNod(Nod *rad,int x)
{
    int depth=0;
    while(rad!=NULL)
    {
        if(rad->key==x)
            return depth;
        else if(x<rad->key)
            rad=rad->st;
        else
            rad=rad->dr;
        depth++;
    }

    return -1;
}

void afiseazaNodurilaadancimeaK(BSTNode *rad, int k) //Imi afiseaza toate nodurile care se afla la nivelul k 
{
    if (rad == NULL || k < 0) return;
    if (k == 0) {
        printf("%d ", rad->cheie);
        return;
    }
   afiseazaNodurilaadancimeaK(rad->st, k - 1);
  afiseazaNodurilaadancimeaK(rad->dr, k - 1);
}

int main()
{
    FILE *f=fopen("in.txt","r");
    if(f==NULL)
    {
        perror("Not ok openning\n");
        exit(-1);
    }

    Nod *rad=NULL;
    Nod *r=NULL;
    int v[20],k=0;
    int nr;
    while(fscanf(f,"%d",&nr)==1)
    {
        insereaza(&rad,nr);
        v[k++]=nr;
    }

    printf("Preo: ");
    preordine(rad);

    printf("\nInor: ");
    inordine(rad);

    printf("\nPost: ");
    postordine(rad);

    printf("\nCupr: ");
    bfs(rad);

   // rad=stergere(rad,45);
   // bfs(rad);
 
    qsort(v,k,sizeof(int),compar);
    r=inaltMin(v,0,k-1);
    printf("\n");
    bfs(r);

    int adanc=adancimeNod(rad,41);
    if(adanc!=-1)
        printf("Adancimea nodului %d e: %d\n",41,adanc);
    else
        printf("Nu s-a gasit nodu\n");

    return 0;
}