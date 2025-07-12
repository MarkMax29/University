/*Se citește un număr natural n din linia de comandă și apoi n numere întregi. Să se creeze o listă dublu înlănțuită
ordonată care să conțină aceste numere. Să se afișeze lista. Să se scrie o funcție care șterge toate elementele dintr-o
listă care sunt divizibile cu un număr k (k generat aleator în afara funcției și transmis ca parametru, număr întreg
între 2 și 12). Să se apeleze funcția de 3 ori asupra listei, cu k diferit. Să se afișeze lista la fiecare pas.
INPUT: ./exe 9 1 7 3 8 9 6 2 4 5
OUTPUT:
Lista initiala: 1 2 3 4 5 6 7 8 9
k = 3, lista: 1 2 4 5 7 8
k = 8, lista: 1 2 4 5 7
k = 2, lista: 1 5 7
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
  aux->next=next;
  aux->prev=prev;
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
LIST *stergere_inceput(LIST *lista)
{
  if(lista==NULL)
    return NULL;
  LIST *aux=lista;
  lista=lista->next;
  if(lista!=NULL)
    lista->prev=NULL;
  free(aux);
  return lista;
}
LIST *stergere_mijloc(LIST *lista,int elem)
{
  LIST *p=lista;
  if(lista==NULL)
    return NULL;
  if(lista->elem==elem)
    return stergere_inceput(lista);
  while(p!=NULL)
    {
      if(p->elem==elem)
	{
	  if(p->next!=NULL)
	    {
	      p->prev->next=p->next;
	      p->next->prev=p->prev;
	    }
	  else
	    {
	      p->prev->next=NULL;
	      free(p);
	      return lista;
	    }
	}
      p=p->next;
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
void sortare(LIST *lista)
{
  LIST *p,*q;
  int sorted,aux=0;
    do
      {
	p=lista;
	sorted=1;
	while(p->next!=NULL)
	  {
	    q=p->next;
		if(p->elem>q->elem)
		  {
		    aux=p->elem;
		    p->elem=q->elem;
		    q->elem=aux;
		    sorted=0;
		  }
	    p=p->next;
	  }
       
    }while(sorted!=1);

}
int main(int argc,char **argv)
{

  int n,j=2;
  LIST *lista=NULL,*p=NULL;
  n=atoi(argv[1]);
  for(int i=0;i<n;i++)
    {
      int nr=atoi(argv[j]);
      lista=inserare_sfarsit(lista,nr);
      j++;
    }
  sortare(lista);
  LIST *copy=lista;
  int k1=-1;
  srand(time(NULL));
  for(int i=0;i<3;i++)
    {
  
      int k=2+rand()%10;
      p=copy;
      while(p!=NULL)
	{
	  if(p->elem%k==0)
	    {
	      LIST *aux=p->next;
	    copy=stergere_mijloc(copy,p->elem);
	    p=aux;
	    }
	  else
	    p=p->next;
	}
   
      printf("k=%d ",k);
      afis(copy);
      printf("\n");
      copy=lista;
    }
      
  //afis(lista);
  //printf("\n");
  return 0;
}
