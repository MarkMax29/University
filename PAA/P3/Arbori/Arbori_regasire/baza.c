#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALFABET 26
typedef struct Nod{
    struct Nod *copii[ALFABET];
    int sf_cuv;
}Nod;

Nod *creare()
{
    Nod *nod=(Nod*)malloc(sizeof(Nod));
    if(nod==NULL)
    {
        perror("error at allocating\n");
        exit(-1);
    }

    for(int i=0;i<ALFABET;i++)
    {
        nod->copii[i]=NULL;
    }

    nod->sf_cuv=0;

    return nod;
}

void inserare(Nod **rad,const char *cuv)
{
    if(*rad==NULL)
    {
        *rad=creare();
    }

    Nod *curent=*rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        int index=tolower(cuv[i])-'a';
        if(curent->copii[index]==NULL)
            curent->copii[index]=creare();
        curent=curent->copii[index];
    }
    curent->sf_cuv=1;
}

void afiseaza(Nod *rad,char *buffer,int nivel)
{
    if(rad==NULL)
        return;

    if(rad->sf_cuv==1)
    {
        buffer[nivel]='\0';
        printf("%s\n",buffer);
    }

    for(int i=0;i<ALFABET;i++)
    {
        if(rad->copii[i]!=NULL)
        {
            buffer[nivel]='a'+i;
            afiseaza(rad->copii[i],buffer,nivel+1);
        }
    }
}


int cauta_cuv(Nod *rad,const char *cuv)
{
    Nod *curent=rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        int index=tolower(cuv[i])-'a';
        if(curent->copii[index]==NULL)
        {
            return 0;
        }
        curent=curent->copii[index];

    }

    return curent->sf_cuv;
}

int exista_pref(Nod *rad,const char *pref)// pentru a verifica daca exista cuv cu un anumit prefix 
{
    Nod *curent=rad;
    for(int i=0;pref[i]!='\0';i++)
    {
        int index=tolower(pref[i])-'a';
        if(curent->copii[index]==NULL)
            return 0;
        curent=curent->copii[index];
    
    }

    return 1;   
}

Nod *prefix(Nod *rad,const char *pref)// pentru a verifica daca exista cuv cu un anumit prefix 
{
    Nod *curent=rad;
    for(int i=0;pref[i]!='\0';i++)
    {
        int index=tolower(pref[i])-'a';
        if(curent->copii[index]==NULL)
            return NULL;
        curent=curent->copii[index];
    
    }

    return curent;   // imi returneaza nodul la care se termina prefixul sau NULL daca nu exista 
}

void autocomplete(Nod *rad,const char *pref)
{
    char buf[256];
    int nivel=0;//musai sa il las aici pe nivel

    for(;pref[nivel]!='\0';nivel++)
    {
        buf[nivel]=pref[nivel];//pun in buffer prefixul
        
    }

    Nod *cur=prefix(rad,pref);//verific daca am in arbore prefixul respectiv si daca da atunci imi returneaza poiterul catre nodul unde se termina prefixul
    if(cur==NULL)
    {
        printf("Nu exista cuvinte cu prefixul %s\n",pref);
        return;
    }

    afiseaza(cur,buf,nivel);// afisez cuvantul care incepe cu prefixul pref
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
        perror("NOT OK At openning\n");
        exit(-1);
    }

    char cuv[100];
    Nod *rad=NULL;
    while(fscanf(f,"%s",cuv)==1)
    {
        inserare(&rad,cuv);
    }
    char buf[101];
    afiseaza(rad,buf,0);

    if(cauta_cuv(rad,"tipar")==1)
        printf("S-a gasit cuvantul\n");
    else
        printf("Nu s-a gasit cuvantul\n");

    printf("AUTOCOMPLETE: \n");
    autocomplete(rad,"");
    return 0;
}