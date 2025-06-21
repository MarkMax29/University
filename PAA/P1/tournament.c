#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX 128
/*A sports tournament organizer needs to manage elimination brackets for 64 teams. Each match eliminates one team, and winners advance to the next round until a champion is determined. The system must efficiently:

    Track which teams advance at each round
    Determine the path any team took to reach their final position
    Calculate the minimum number of matches needed
    Find all teams that were eliminated by the eventual winner

Design an algorithm to represent this tournament structure and implement functions to answer queries about team progression and match outcomes.*/

typedef uint8_t TipCheie;


//structura pentru un meci: castigator ,meci din stanga, meci din dreapta (sau concurenti/echipe)
typedef struct Nod{

    TipCheie key;//memoram castigatorul unui meci
    struct Nod *left; //meciul anterior 1 
    struct Nod* right; //meciul anterior 2
}Nod;

typedef struct Echipanod{
    TipCheie id;
    Nod* nod;
}Echipanod;

//mapare pt ca vrem sa stim daca o echipa a fost deja implicata int-un meci si sa nu mai cream alt nod ci sa il folosim pe ala 
Echipanod mapare[MAX];
int nr_noduri=0;

//aici practic creez echipele adica A,B,C,...
Nod* creazanod(TipCheie key)
{
    Nod* nou=(Nod*)malloc(sizeof(Nod));
    if(nou==NULL)
    {
        perror("eroare la alocare");
        exit(-1);
    }

    nou->key=key;
    nou->left=NULL;
    nou->right=NULL;

    return nou;
}
// Funcție unificată: dacă nou == NULL → returnează nodul existent
// dacă nou != NULL → înlocuiește nodul pentru echipă cu meciul nou
Nod *getsauCreazasauInlocuieste(TipCheie key, Nod *nou)
{
    for(int i=0;i<nr_noduri;i++)
    {
        if(mapare[i].id==key)
        {   if(nou!=NULL)
                mapare[i].nod=nou;//inlocuim doar daca ni s-a dat un nod nou            
            return mapare[i].nod;//returnam nodul curent asociat 
        }
    }


    //daca nu am gasit deloc echipa o adaugam
    Nod *realnod;
    if(nou!=NULL)   
        realnod=nou;
    else 
        realnod=creazanod(key);
    mapare[nr_noduri].id=key;
    mapare[nr_noduri].nod=realnod;
    nr_noduri++;
    return realnod;
}


Nod *construiesteArbore(const char *numefis)
{
    FILE *f=NULL;
    f=fopen(numefis,"r");
    if(f==NULL)
    {
        perror("eroare la deschidere fisier");
        exit(-1);
    }

    TipCheie e1,e2,winner;
    Nod *radacina=NULL;

    while(fscanf(f,"%c %c %c",&e1,&e2,&winner)==3)
    {
        //Obtinem nodurile curente ale echipelor 
        Nod *st=getsauCreazasauInlocuieste(e1,NULL);
        Nod *dr=getsauCreazasauInlocuieste(e2,NULL);

        //cream meciul castigat 
        Nod* meci=creazanod(winner);
        meci->left=st;
        meci->right=dr;

        //inlocuim nodul echipe castigatoare cu noul meci
        getsauCreazasauInlocuieste(winner,meci);

        radacina=meci;//pastram ultimul nod creat drept campion
    }

    fclose(f);
    return radacina;
}

//parcurgere in adancime postordine
int afiseazaDrum(Nod* radacina,TipCheie echipa)
{
    if(radacina==NULL)
        return 0;

    if(radacina->left ==NULL && radacina->right==NULL && radacina->key==echipa)
        return 1;//echipa exista in arbore

    if(afiseazaDrum(radacina->left,echipa) || afiseazaDrum(radacina->right,echipa))
    {

        TipCheie lft=radacina->left->key;
        TipCheie rgh=radacina->right->key;
        TipCheie castig=radacina->key;


        printf("Meci: %c vs %c -> castigat: %c\n",lft,rgh,castig);

        if(castig!=echipa)
        {
                printf("    Echipa %c a fost eliminat aici \n",echipa);
                return 0;
        }
        return 1;
    }
    return 0;


}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("not enough arg!\n");
        exit(-1);
    }
    
    Nod *arbore=construiesteArbore(argv[1]);
    printf("CAMPIONUL ESTE : %c\n",arbore->key);

    if(!afiseazaDrum(arbore,'G'))
    {
        printf("Echipa %c nu a fost gasita in turneu.\n",'G');
    }

    
    return 0;
}