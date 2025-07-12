#include<stdio.h>
#include<stdlib.h>
typedef struct STUDENT{
  char nume[16],prenume[24];
  float lab,exam;
}STUDENT;

typedef struct LIST{
  STUDENT elem;
  struct LIST *next;
}LIST;
LIST *creare_nod(LIST *next,STUDENT elem)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));;
  if(aux==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  aux->elem=elem;
  aux->next=next;
  return aux;

}
LIST *inserare_sfarsit(LIST *lista,STUDENT elem)
{
  LIST *p=NULL;
  LIST *aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      p=lista;
      while(p->next!=NULL)
	{
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
}

void afisare(LIST *lista,STUDENT elem)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("NUME: %s - PRENUME: %s - NOTA LAB: %.2f - NOTA EXAM: %.2f",p->elem.nume,p->elem.prenume,p->elem.lab,p->elem.exam);
      p=p->next;
    }

}


void citire()
{
  int n=0;
  FILE *f=NULL;
  LIST *lista=NULL;
  f=fopen("TP.TXT","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  STUDENT student;
  while(fscanf(f,"%15s %23s %f %f",student.nume,student.prenume,&student.lab,&student.exam)==4)
    {
      n++;
      lista=inserare_sfarsit(lista,student);
      printf("NUME:%s PRENUME:%s are media:%f\n",student.nume,student.prenume,(student.lab+student.exam)/2);
    }
  fclose(f);
  FILE *bin=NULL;
  bin=fopen("REZULTATE.OUT","wb");
  if(bin==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  fwrite(&n,sizeof(int),1,bin);
  fclose(bin);
  printf("NUMARUL DE STUDENTI:%d\n",n);
}

int main()
{
  
  citire();
  return 0;
}
  
  
