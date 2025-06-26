#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ALFABET 26 //literele de la a la z

typedef struct Nod{
    struct Nod *copii[ALFABET];
    int sfarsit_cuv;///1 cand s-a ajuns la sfarsitul unui cuvant 
}Nod;

Nod *creaza_nod()
{
    Nod *nou=(Nod*)malloc(sizeof(Nod));
    if(nou==NULL)
    {
        perror("error\n");
        exit(-1);
    }
    nou->sfarsit_cuv=0;
    for(int i=0;i<ALFABET;i++)
    {
        nou->copii[i]=NULL;
    }
    return nou;
}
void inserare(Nod *radacina,const char *cuv)
{
    Nod *curent=radacina;
    while(*cuv)
    {
        int index=*cuv-'a';
        if(curent->copii[index]==NULL)//practic extinde arborele contruind "ramura "lipsa
        {
            curent->copii[index]=creaza_nod();
        }
        curent=curent->copii[index];//merg spre acea litera(avansez)
        cuv++;//trec la urmatoarea litera din cuvant
    }
    curent->sfarsit_cuv=1;
}

void afisare(Nod *nod,char *buffer,int nivel)
{
    
    if(nod->sfarsit_cuv==1)
    {
        buffer[nivel]='\0';
        printf("%s\n",buffer);
    }
    for(int i=0;i<ALFABET;i++)
    {
        if(nod->copii[i]!=NULL)
        {
            buffer[nivel]='a'+i;
            afisare(nod->copii[i],buffer,nivel+1);
        }
    }
}
int cauta(Nod *radacina,const char *cuv)
{
    Nod *curent=radacina;
    while(*cuv)
    {
        int index=*cuv-'a';
        if(curent->copii[index]==NULL)
        {
            return 0;
        }
        curent=curent->copii[index];
        cuv++;
    }
    return curent->sfarsit_cuv;
}

void cauta_prefix(Nod *rad,const char *prefix)
{
  
   char buffer[100];
   int nivel=0;
    Nod *curent=rad;
    while(*prefix && curent!=NULL)
    {
        int index=*prefix-'a';
        curent=curent->copii[index];
        buffer[nivel++]=*prefix;
        prefix++;
    }

    if(curent==NULL)
    {
        printf("Nu exista cuv cu prefixul asta \n");
        return;
    }

    afisare(curent,buffer,nivel);

}

int main()
{
    Nod *rad=creaza_nod();
    char buffer[200];

    const char *cuvinte[]={"ion","an","ioana","ana","andrei","ionut"};
    int n=sizeof(cuvinte)/sizeof(cuvinte[0]);

    for(int i=0;i<n;i++)
        inserare(rad,cuvinte[i]);

    //printf("Cuvintele din arbore in ordine lexicografica:\n");
    //afisare(rad,buffer,0);

    cauta_prefix(rad,"io");
}