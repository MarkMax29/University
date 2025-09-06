#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ALFABET 27

typedef struct Nod{
    struct Nod *copii[ALFABET];
    int sf;
}Nod;


Nod *creare()
{
    Nod *nou=(Nod*)malloc(sizeof(Nod));
    if(nou==NULL)
    {
        perror("Not ok \n");
        exit(-1);
    }
    for(int i=0;i<ALFABET;i++)
    {
        nou->copii[i]=NULL;
    }

    nou->sf=0;
    return nou;
}

void inserare(Nod **rad,char *cuv)
{
    if(*rad==NULL)
     {
        *rad=creare();
     }
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
    curent->sf=1;
}

void cuv_cu_e(Nod *rad,char *buf,int nivel,int *count)
{
    if(rad==NULL)
        return;
    if(rad->sf==1)
    {
        if(nivel>=2 && buf[1]=='e')
            {
                buf[nivel]='\0';
                (*count)++;
                printf("%s\n",buf);
            }

    }

    for(int i=0;i<ALFABET;i++)
    {
        if(rad->copii[i]!=NULL)
        {
            buf[nivel]='a'+i;
            cuv_cu_e(rad->copii[i],buf,nivel+1,count);
        }
    }
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

    char line[1000];
    fgets(line,sizeof(line),f);

    char *p=strtok(line," ,\n\r");
    while(p!=NULL)
    {
        inserare(&rad,p);
        p=strtok(NULL," ,\n\r");
    }

    char buf[100];
    int cont=0;
    cuv_cu_e(rad,buf,0,&cont);

    printf("Numarul de cuv cu e pe poz 2 este : %d\n",cont);

    return 0;
}