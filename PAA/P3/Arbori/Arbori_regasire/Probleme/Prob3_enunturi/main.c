/*Fie un dictionar implementat cu ajutorul unui arbore de regasire. Sa se scrie o functie care determina
cuvantul cel mai lung. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALFABET 27

typedef struct Nod{
    struct Nod *copii[ALFABET];
    int sf_cuv;
}Nod;
Nod *creare()
{
    Nod *nod=(Nod*)malloc(sizeof(Nod));
    if(nod==NULL)
    {
        perror("at allocation\n");
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

    Nod *cur=*rad;

    for(int i=0;cuv[i]!='\0';i++)
    {
        if(isalpha(cuv[i]))
        {
            int index=tolower(cuv[i])-'a';
            if(cur->copii[index]==NULL)
            {
                cur->copii[index]=creare();
            }
            cur=cur->copii[index];
        }
        
    }
    cur->sf_cuv=1;
}

void cuvmax(Nod *rad,char *buf,int nivel,char *cuv_max,int *maxim)// sa fie prin pointer maxim 
{
    if(rad==NULL)
        return;

    if(rad->sf_cuv==1)
    {
        buf[nivel]='\0';
        if(*maxim<nivel)
        {
            *maxim=nivel;
            strcpy(cuv_max,buf);
        }
    }

    for(int i=0;i<ALFABET;i++)
    {
        if(rad->copii[i]!=NULL)
        {
            buf[nivel]='a'+i;
            cuvmax(rad->copii[i],buf,nivel+1,cuv_max,maxim);
        }
    }
}

void cuvant_maxim(Nod *rad)
{
    char buff[256],max[256];
    max[0]='\0';// ma scapa sa nu afisez chestii random
    int best=-1;
    cuvmax(rad,buff,0,max,&best);
    printf("Cuvantul de lungime maxima este: %s\n",max);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("NO GOOD ARG\n");
        exit(-1);
    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("PROBLEM AT OPENNING\n");
        exit(-1);
    }

    Nod *rad=NULL;
    char cuv[30];
    while(fscanf(f,"%s",cuv)==1)
    {
        inserare(&rad,cuv);
    }

    cuvant_maxim(rad);

    return 0;
}