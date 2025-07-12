/*Aplicația 7.2: Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate.
Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.
*/

#include<stdio.h>
#include<stdlib.h>

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
LIST *inserare_sfarsit(LIST *lista,int elem)
{
  LIST *aux=creare_nod(NULL,elem),*p=NULL;
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
void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }

}
void elib(LIST *lista)
{
  LIST *aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }
}

LIST *prb(LIST *lista)
{
  LIST *prev=NULL,*q=NULL,*p=NULL;
  prev=lista;
  p=lista->next;
  prev->next=NULL;  // prima sagetuta arata spre NULL acum
  while(p!=NULL)
    {
      q=p;
      p=p->next;
      q->next=prev;;
      prev=q;
    }
  lista=prev;/// ca lista sa pointeze spre ultimul (care e acum primul nod)
  return lista;

}
int main()
{
  LIST *lista;
  for(int i=1;i<=4;i++)
    lista=inserare_sfarsit(lista,i);
  printf("LISTA INITIALA:");
  afis(lista);
  printf("\n");
  lista=prb(lista);
  printf("LISTA INVERSATA:");
  afis(lista);
  printf("\n");
  elib(lista);

  return 0;
}
