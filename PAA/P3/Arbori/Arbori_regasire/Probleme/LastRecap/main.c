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
    Nod *nou=(Nod*)malloc(sizeof(Nod));
    if(nou==NULL)
    {
        perror("Not ok allocating\n");
        exit(-1);
    }

    for(int i=0;i<ALFABET;i++)
    {
        nou->copii[i]=NULL;
    }

    nou->sf_cuv=0;

    return nou;
}

void inserare(Nod **rad,char *cuv,char *maxim)
{
    if(*rad==NULL)
        *rad=creare();

    Nod *curent=*rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        int index=tolower(cuv[i])-'a';
        if(curent->copii[index]==NULL)
            curent->copii[index]=creare();
        curent=curent->copii[index];
    }

    curent->sf_cuv=1;
    if(maxim[0]=='\0'||strcmp(cuv,maxim)>0)
    {
        strcpy(maxim,cuv);
    }
}

void inaltime(Nod *rad,char *buf,int nivel,int *maxim)
{
    if(rad==NULL)
        return;//specific conditie de oprire recursivitate

    if(rad->sf_cuv==1)
    {
        buf[nivel]='\0';
        if(*maxim<=nivel)
        {
            *maxim=nivel;    
        }
    }

    for(int i=0;i<ALFABET;i++)
    {
        if(rad->copii[i]!=NULL)
        {
            buf[nivel]='a'+i;
            inaltime(rad->copii[i],buf,nivel+1,maxim);
        }
    }
    
}

void afis_inaltime_arb(Nod *rad)
{
    char buf[512];
    int maxi=-1;
    inaltime(rad,buf,1,&maxi);//Înălțimea arborelui de regăsire = numărul de noduri de pe cel mai lung drum de la rădăcină până la o frunză (adică include și rădăcina și frunza).

    printf("Inaltime arbore: %d\n",maxi);
}

int nr_pag(Nod *rad)
{
    if(rad==NULL)
        return 0;
    int cnt=1;
    for(int i=0;i<ALFABET;i++)
    {
       cnt+=nr_pag(rad->copii[i]);
    }

    return cnt;
}

void afisare(Nod *rad,char *buf,int nivel)
{
    if(rad==NULL)
        return;
    if(rad->sf_cuv==1)
    {
        buf[nivel]='\0';
        printf("%s\n",buf);
    }

    for(int i=0;i<ALFABET;i++)
    {
        if(rad->copii[i]!=NULL)
        {
            buf[nivel]=i+'a';
            afisare(rad->copii[i],buf,nivel+1);
        }
    }
}


Nod *pref(Nod *rad,const char *prefix)
{
    Nod *curent=rad;
    for(int i=0;prefix[i]!='\0';i++)
    {
        int index=prefix[i]-'a';
        if(curent->copii[index]==NULL)
            return NULL;
        curent=curent->copii[index];
    }
    return curent;
}

void autocomplete(Nod *rad,const char *prefix)
{
    char buf[512];
    int nivel=0;
    for(;prefix[nivel]!='\0';nivel++)
    {
        buf[nivel]=prefix[nivel];
    }

    Nod *last=pref(rad,prefix);
    if(last==NULL)
    {
        printf("Nu exista cuv cu prefixul dat\n");
         return;
    }
        afisare(last,buf,nivel);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("Not ok\n");
        exit(-1);
    }
    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Openning error\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);
    char sir[30];
    Nod *rad=NULL;
    char maxim[50]="";

    for(int i=0;i<n;i++)
    {
        fscanf(f,"%s",sir);
        inserare(&rad,sir,maxim);
    }
    afis_inaltime_arb(rad);

    int noduri=nr_pag(rad);
    printf("Numarul de noduri alocate in arbore: %d\n",noduri);


    printf("Cel mai mare cuvant din pct de vedere lexicografic este: %s\n",maxim);


    char buf[512];
    printf("\nCuvintele din dictionar: \n");
    afisare(rad,buf,0);

    printf("\nCuv care incep cu prefixul dat: \n");
    autocomplete(rad,"ar");
    return 0;
}