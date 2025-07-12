/*Aplicația 9.6: Se considera o lista liniara dublu inlantuita. Sa se scrie o functie care primeste ca parametru adresa
primului nod al listei si muta ultimul nod in fata primului.
*/


#include<stdio.h>
#include<stdlib.h>
typedef struct LIST{
  int elem;
  struct LIST *next;
  struct LIST *prev;
}LIST;
LIST *creare_nod(LIST *prev,LIST *next,int elem)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));
  if(aux==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  aux->elem=elem;
  aux->prev=prev;
  aux->next=next;
  return aux;
}
LIST *inserare_inceput(LIST *lista,int elem)
{
  LIST *aux=creare_nod(NULL,lista,elem);
  if(lista!=NULL)
      lista->prev=aux;
  return aux;

}
LIST *inserare_sfarsit(LIST* lista,int elem)
{
  LIST *p=NULL,*aux=creare_nod(NULL,NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      p=lista;
      while(p->next!=NULL)
	p=p->next;
      p->next=aux;
      aux->prev=p;
    }
  return lista;
      
}

LIST *stergere_final(LIST *lista)
{
  if(lista==NULL)
    return NULL;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
  LIST *p=lista;
  while(p->next!=NULL)
    p=p->next;
  p->prev->next=NULL;
  free(p);
  return lista;
}
LIST *muta(LIST* lista)
{
  LIST *p=lista;
  while(p->next->next!=NULL)
    p=p->next;
  int aux=p->next->elem;
  lista=stergere_final(lista);
  /*while(p->prev!=NULL)
    p=p->prev;*/
  lista=inserare_inceput(lista,aux);
  return lista;
      
}
void afis(LIST *lista)
{
  LIST *p=lista;;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
}
int main()
{
  LIST *lista=NULL;
  for(int i=1;i<=6;i++)
      lista=inserare_sfarsit(lista,i);
  printf("LISTA INITIALA:");
  afis(lista);
  printf("\n");
  lista=muta(lista);
  printf("LISTA FINALA:");
  afis(lista);
  printf("\n");
  return 0;
}
