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
        perror("alocare\n");
        exit(-1);

    }

    for(int i=0;i<ALFABET;i++)
    {
        nou->copii[i]=NULL;
    }

    nou->sf_cuv=0;
    return nou;
}

void inserare(Nod **rad,char *cuv)
{
    if(*rad==NULL)
        *rad=creare();

    Nod *curent=*rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        if(isalpha(cuv[i]))
        {
            int index=tolower(cuv[i])-'a';
            if(curent->copii[index]==NULL)
                curent->copii[index]=creare();

            curent=curent->copii[index];
        }
    }
    curent->sf_cuv=1;
}
int exista_cuv(Nod *rad,char *cuv)
{
    Nod *cur=rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        int index=tolower(cuv[i])-'a';
        if(cur->copii[index]==NULL)
            return 0;
        cur=cur->copii[index];
    }

    return cur->sf_cuv;
}
void sugestie(Nod *rad,char *cuv)
{

    char posibil[50];
    int size_cuv=strlen(cuv);
    for(int i=0;i<=size_cuv;i++)
    {
        for(char lit='a';lit<='z';lit++)
        {
        
            int k=0;
            for(int j=0;j<i;j++)
            {
               posibil[k++]=cuv[j];
            }   
            posibil[k++]=lit;
            for(int j=i;j<size_cuv;j++)
            {
                posibil[k++]=cuv[j];
            }

            posibil[k]='\0';
        
        if(exista_cuv(rad,posibil)==1)
        {
            printf("Avem sugestie: %s\n",posibil);
            return;
        }
     }
    }

    printf("Nu avem nicio sugestie\n");
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

    Nod *rad=NULL;
    
    char linie[1000];
    fgets(linie, sizeof(linie), f); // citim prima linie completă cu toate cuvintele

    // Sparge pe "," și " "
    char *p = strtok(linie, ", \n\r");
    while (p != NULL)
    {
        inserare(&rad, p);
        p = strtok(NULL, ", \n\r");
    }

    char cuv[50];
    fscanf(f,"%s",cuv);
    sugestie(rad,cuv);

    return 0;
}