#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pacient{
    int id,an;
}Pacient;

typedef struct Nod{
    Pacient pacient;
    struct Nod *st;
    struct Nod *dr;
}Nod;


Nod *creare(Pacient valoare)
{
    Nod *nod=(Nod*)malloc(sizeof(Nod));
    if(nod==NULL)
    {
        perror("error at alocating\n");
        exit(-1);
    }

    nod->pacient.id=valoare.id;
    nod->pacient.an=valoare.an;
    nod->st=NULL;
    nod->dr=NULL;

    return nod;
}

int front=0,end=0;
void push(Nod **coada,Nod *value)
{
    coada[end++]=value;

}

Nod *queue(Nod **coada)
{
    return coada[front++];
}
void inserare(Nod **rad,Pacient val)
{
    if(*rad==NULL)
    {
        *rad=creare(val);
        return;
    }

    Nod *coada[100];
    end=0;
    front=0;
   
    push(coada,*rad);

    while(front<end)
    {
        Nod *nod=queue(coada);
        if(nod->st==NULL)
        {
            nod->st=creare(val);
            return;
        }
        else
        {
            push(coada,nod->st);
        }

        if(nod->dr==NULL)
        {
            nod->dr=creare(val);
            return;
        }
        else
        {
            push(coada,nod->dr);
        }
    }

}
int maxim(int a,int b)
{
    return a>b ? a:b;
}

int inaltime(Nod *rad)
{
    if(rad==NULL)
        return 0;
    int hs=inaltime(rad->st);
    int hd=inaltime(rad->dr);

    return 1+maxim(hs,hd);
}
void preordine(Nod *rad)
{
    if(rad==NULL)
        return;
    printf("%d %d\n",rad->pacient.id,rad->pacient.an);
    preordine(rad->st);
    preordine(rad->dr);

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
        perror("Not ok at openning file\n");
        exit(-1);
    }

    int n;
    fscanf(f,"%d",&n);

    Pacient v[n];
    Nod *radacina=NULL;

    int id,an;
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d %d",&id,&an);
        v[i].id=id;
        v[i].an=an;
    }
    for(int i=0;i<n;i++)
    {
        inserare(&radacina,v[i]);
    }

    int h=(int)floor(log2(n))+1;

    int inalt=inaltime(radacina);
    preordine(radacina);

    printf("Inlatime minima: %d | Inaltime arbore: %d\n",h,inalt);
    return 0;
}