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
        perror("not ok \n");
        exit(-1);
    }

    for(int i=0;i<ALFABET;i++)
    {
        nou->copii[i]=NULL;
    }

    nou->sf_cuv=0;
    return nou;
}

void inserare(Nod **rad,char *cuv,char *min_cuv)
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
    if(min_cuv[0]=='\0' || strcmp(cuv,min_cuv)<0)// aia cu min_cuv[0] e practic pentru initializarea minimului ca la inceput de program nu stii care e minimul n-ai cu ce sa compari 
        strcpy(min_cuv,cuv);
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
    char sir[50],mini[50]="";
    while(fscanf(f,"%s",sir)==1)
    {
        int j;
        for(int i=0;i<strlen(sir);i++)
        {
            if(sir[i]==',')
                j=i;
        }
        sir[j]='\0';
        inserare(&rad,sir,mini);
    }

    printf("Primul cuv din dictionar: %s\n",mini);
    return 0;
}