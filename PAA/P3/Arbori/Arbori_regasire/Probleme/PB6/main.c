#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        perror("not k allocating\n");
        exit(-1);
    }

    for(int i=0;i<ALFABET;i++)
    {
        nod->copii[i]=NULL;
    }
    nod->sf_cuv=0;

    return nod;
}

void inserare(Nod **rad,char *cuv,char *max_cuv)
{
    if(*rad==NULL)
    {
        *rad=creare();
    }

    Nod *curent=*rad;
    for(int i=0;cuv[i]!='\0';i++)
    {
        if((cuv[i]>='a' && cuv[i]<='z') || (cuv[i]>='A' && cuv[i]<='Z'))
        {
            int index=tolower(cuv[i])-'a';

            if(curent->copii[index]==NULL)
            {
                curent->copii[index]=creare();
                curent=curent->copii[index];
            }
        }
    }
    curent->sf_cuv=1;

    if(strcmp(cuv,max_cuv)>0)
    {
        strcpy(max_cuv,cuv);
    }

}

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        perror("not ok \n");
        exit(-1);

    }

    FILE *f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("not ok openning\n");
        exit(-1);
    }

    //int max=0;
    char sir[50],ultim_cuv[50];

    Nod *rad=NULL;
    while(fscanf(f,"%s",sir)==1)
    {
        int j;
        for (int i=0;i<strlen(sir);i++)
        {
            if(sir[i]==',')
                j=i;
        }
        sir[j]='\0';
        inserare(&rad,sir,ultim_cuv);

    }
    printf("Ultimul cuv: %s\n",ultim_cuv);
    return 0;
}