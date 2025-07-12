/*Aplicația 7.3: Să se scrie o funcție care primește ca parametri două liste și returnează o listă care reprezintă
reuniunea elementelor lor, fiecare element apărând o singură dată, chiar dacă în listele originare el este duplicat.
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
void afisare(LIST *lista)
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

LIST *reuniune(LIST *lista1,LIST *lista2)
{
  LIST *list=NULL,*p=NULL,*q=NULL,*k=NULL;
  p=lista1;
  while(p!=NULL)
    {
      list=inserare_sfarsit(list,p->elem);
      p=p->next;
    }
  q=lista2;
 
  while(q!=NULL)
    {
      k=list;
      int ok=0;
      while(k!=NULL && ok!=1)
	{
	  if(q->elem==k->elem)
	    ok=1;
	  k=k->next;
	}
      if(ok==0)
	list=inserare_sfarsit(list,q->elem);
      q=q->next;
    }
  return list; 

}
int main()
{
  LIST *lista1=NULL,*lista2=NULL,*tot=NULL;
  lista1=inserare_sfarsit(lista1,1);
  lista1=inserare_sfarsit(lista1,5);
  lista1=inserare_sfarsit(lista1,7);
  lista2=inserare_sfarsit(lista2,2);
  lista2=inserare_sfarsit(lista2,1);
  lista2=inserare_sfarsit(lista2,8);
  lista2=inserare_sfarsit(lista2,9);
  tot=reuniune(lista1,lista2);
  afisare(tot);
  printf("\n");
  return 0;
}
