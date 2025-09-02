#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int key;
    struct Nod *st;
    struct Nod *dr;
}Nod;

//asta e strict pentru a crea un nod 
Nod *creare(int valoare)
{
    Nod *nod=(Nod*)malloc(sizeof(Nod));
    if(nod==NULL)
    {
        perror("eroare la alocare\n");
        exit(-1);
    }

    nod->key=valoare;
    nod->st=NULL;
    nod->dr=NULL;

    return nod;
}

//asta e functia de inserare efectiva a unui nod in arbore
// se face cu bfs cumva cu coada 

int end=0,front=0;

void push(Nod **coada,Nod *value)
{
    coada[end++]=value;
}

Nod *queue(Nod **coada)
{
    return coada[front++];
}

void inserare(Nod **rad,int val)
{
    if(*rad==NULL)
    {
        *rad=creare(val);
        return ;
    }

    Nod *coada[100];//declaram o coada de max 100 de elem
    front=0;
    end=0;

    push(coada,*rad);// bagam radacina

    while(front<end)
    {
        Nod *curent=queue(coada);//scot un nod 

        if(curent->st==NULL)//vad daca in partea stanga nu am noduri atunci creez nodul cu valoarea respectiva si se leaga practic de arbore
        {
            curent->st=creare(val);
            return;
        }
        else
        {
            push(coada,curent->st);// daca am in partea stanga nod atunci il bag in coada ca il iau ca si copii radacinei curent (ideea e ca se merge pe niveluri de la st la dr)
        }

        if(curent->dr==NULL)
        {
            curent->dr=creare(val);
            return;
        }
        else
        {
            push(coada,curent->dr);
        }
    }
}



/// ACUM PARCURGERE IN CUPRINDERE(BFS->PE NIVELURI)///

void bfs(Nod *rad)//pentru parcurgere trb dor o * pt ca nu faci schimbari asupra arborelui doar o parcurgi si afisezi adica asa iei copia din main si doar afisezi
{

    if(rad==NULL)
    {
        printf("Arbore vid\n");
        return;
    }

    Nod *coada[100];
    end=front=0;
    push(coada,rad);

    while(front<end)
    {
        Nod *nod=queue(coada);
        printf("%d ",nod->key);
        
        if(nod->st!=NULL)
            push(coada,nod->st);
        if(nod->dr!=NULL)
            push(coada,nod->dr);
    }

    printf("\n");
}


/// DFS preordine///

void preorder(Nod *rad)
{
    if(rad==NULL)
        return;
    printf("%d ",rad->key);
    preorder(rad->st);
    preorder(rad->dr);
}

/// Inordine ///

void inorder(Nod *rad)
{
    if(rad==NULL)
        return;
    inorder(rad->st);
    printf("%d ",rad->key);
    inorder(rad->dr);
}
/// Postordine ///
void postorder(Nod *rad)
{
    if(rad==NULL)
        return;
    postorder(rad->st);
    postorder(rad->dr);
    printf("%d ",rad->key);
}



///STERGEREA UNUI SUBERBORE CU RAD DE CHEIA X   ///

void freeSubarbore(Nod *nod)
{
    if(nod==NULL)
        return;
    freeSubarbore(nod->st);
    freeSubarbore(nod->dr);
    free(nod);
}

void freeArbore(Nod **rad)
{
    freeSubarbore(*rad);
    *rad=NULL;  //foarte important ca invalideaza radacina
}
// tot cu BFS COADA plus avem alte 2 functii care prima ii pentru a parcurge in postordine de la frunze spre radacina si a doua apeleaza pe prima cu radacina si il invalideaza punand pointerul pe null 
int stergsubarbX(Nod **rad,int x)
{
    if(*rad==NULL)
        return 1; 

    if((*rad)->key==x)
    {            
        freeArbore(rad);
        return 1;    
    }

    front=0;end=0;
    Nod *coada[100];

    push(coada,*rad);

    while(front<end)
    {
        Nod *nod=queue(coada);

        if(nod->st!=NULL)
        {
            if(nod->st->key==x)
            {
                freeSubarbore(nod->st);
                nod->st=NULL;
                return 1;
            }
            push(coada,nod->st);
        }

        if(nod->dr!=NULL)
        {
            if(nod->dr->key==x)
            {
                freeSubarbore(nod->dr);
                nod->dr=NULL;
                return 1;
            }
            push(coada,nod->dr);
        }
    }

    return 0;// in cazul in care x nu se gaseste in arbore 


}


///Inaltimea arborelui ///

int max(int a,int b)
{
    return (a>b) ? a:b;// returneaza maximul dintre a si b
}

int inaltime(Nod *nod)
{
    if(nod==NULL)
        return 0;
    int hst=inaltime(nod->st);
    int hdr=inaltime(nod->dr);

    return 1+max(hst,hdr);//se uita practic in ambii subarbori si verifica care e mai inalt si +1 ca sa adaugam si radacina practic 
}

int main()
{
    Nod *radacina=NULL;//acesta practic e arborele nostru,un pointer catre radacina 

    FILE *f=fopen("in.txt","r");
    if(f==NULL)
    {
        perror("Not openning\n");
        exit(-1);
    }

    int nr;
    while(fscanf(f,"%d",&nr)==1)
    {
        inserare(&radacina,nr);
    }

    printf("BFS: ");
    bfs(radacina);

    printf("Preordine: ");
    preorder(radacina);

    printf("\nInordine: ");
    inorder(radacina);


    printf("\nPostordine: ");
    postorder(radacina);

    int height=inaltime(radacina);
    printf("\nInaltime inainte de stergere: %d\n",height);

    int ok=stergsubarbX(&radacina,90);
    if(ok==1)
    {
        printf("\nS-A GASIT X SI S-A STERS TOT SUBARBORELE INCEPAND CU RAD X\n");
        bfs(radacina);

    }
    else
    {
        printf("Nu s-a gasit X\n");
    }
    height=0;
    height=inaltime(radacina);
    printf("\nInaltime dupa stergere: %d\n",height);
    return 0;
}