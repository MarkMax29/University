/*Aplicația 9.4: Se considera o lista liniara dublu inlantuita cu numar par de noduri. Sa se scrie o functie care
primeste ca parametru adresa primului nod al listei si interschimba primul nod cu cel de-al doilea, al treilea cu cel
de-al patrulea si asa mai departe.
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct LIST{
  int elem;
  struct LIST *prev;
  struct LIST *next;
}LIST;

LIST *creare_nod(LIST *next,LIST *prev,int elem)
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

LIST *inserare_sfarsit(LIST *lista,int elem)
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
void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
    
}
LIST *inters(LIST *lista)
{
  int aux;
  LIST *p=lista;
  while(p!=NULL)
    {
      aux=p->elem;
      p->elem=p->next->elem;
      p->next->elem=aux;
      p=p->next->next;
    }
  return lista;
  

}

int main()
{
  LIST *lista=NULL;
  for(int i=1;i<=6;i++)
    {
      lista=inserare_sfarsit(lista,i);
      
    }
  printf("LIST INITIALA:");
  afis(lista);
  printf("\n");
  lista=inters(lista);
  printf("LIST INTERSCHIMBATA:");
  afis(lista);
  printf("\n");
  


  return 0;
}
