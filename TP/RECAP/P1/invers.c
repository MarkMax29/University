#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 9
#define MIN 1
typedef struct LIST{
  int elem;
  struct LIST *next;
}LIST;

LIST *creare_nod(LIST *next,int elem)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));
  if(aux==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  aux->elem=elem;
  aux->next=next;
  return aux;
}

LIST *inserare_inceput(LIST *lista,int elem)
{
  return creare_nod(lista,elem);
}
LIST *inserare_sfarsit(LIST *lista,int elem)
{
  LIST *p=NULL,*aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      p=lista;
      while(p->next!=NULL)
	p=p->next;
      p->next=aux;
    }
  return lista;
}
LIST *inserare_dupa_x(LIST *lista,int elem,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    {
      p=p->next;
    }
  if(p==NULL)
    return lista;
  p->next=inserare_inceput(p->next,elem);
  return lista;
}
LIST *stergere_inceput(LIST *lista)
{
  LIST *p=lista;
  if(lista==NULL)
    return lista;
  lista=lista->next;
  free(p);
  return lista;
}
LIST *stergere_sfarsit(LIST *lista)
{
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
  LIST *p=lista;
  while(p->next->next!=NULL)
    p=p->next;
  LIST *q=p->next;
  p->next=NULL;
  free(q);
  return lista;

}
LIST *stergere_random(LIST *lista,int elem)
{
  LIST *p=NULL;
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
  if(lista->elem==elem)
    {
      p=lista;
      lista=lista->next;
      free(p);
      return lista;
    }
  LIST *prev=lista;
  p=lista->next;
  while(p!=NULL)
    {
      if(p->elem==elem)
	{
	  prev->next=p->next;
	  free(p);
	  break;
	}
      p=p->next;
      prev=prev->next;
    }
  return lista;
      	
}

void eliberare(LIST *lista)
{
  LIST *aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }
}

LIST *inversare(LIST *lista)
{
  LIST *p=NULL,*prev=NULL,*q=NULL;
  prev=lista;
  p=lista->next;
  prev->next=NULL;
  while(p!=NULL)
    {
      q=p;
      p=p->next;
      q->next=prev;
      prev=q;
    }
  lista=prev;
  return lista;
}
void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
}


int main()
{

  LIST *lista=NULL,*lista2=NULL;
  srand(time(NULL));
  int v[10];
  for(int i=0;i<10;i++)
    {
      v[i]=rand()%(MAX -MIN+1)+MIN;
    }
  for(int i=0;i<10;i++)
    lista=inserare_sfarsit(lista,v[i]);
  printf("lista init: ");
  afisare(lista);
  printf("\n");
  // eliberare(lista);
  lista2=inversare(lista);
  printf("lista inversata: ");
  afisare(lista2);
  // eliberare(lista);
  //eliberare(lista2);
  

}
      
      
      
  
