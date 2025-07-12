/*Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un
element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să
se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată.
Programul nu va folosi niciun vector
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
LIST *inserare_inceput(LIST *lista,int elem)
{
  return creare_nod(lista,elem);
}
LIST *inserare_sfarsit(LIST *lista,int elem)
{
  LIST *p,*aux=creare_nod(NULL,elem);
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
void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
}
/*void sortare(LIST *lista)
{
  LIST *copy=NULL;
  LIST *p=lista,*q=lista->next;
  while(q!=NULL)
    {
      if(p->elem>q->elem)
	{
	  copy=inserare_inceput(copy,q->elem);
	  q=q->next;
	}
      else if(p->elem<q->elem)
	{
	  copy=inserare_sfarsit(copy,p->elem);
	  p=q;
	  q=q->next;
	}
    }
  copy=inserare_sfarsit(copy,p->elem);
  //elib(lista);
  //lista=copy;
  printf("LISTA SORTATA:");
  afis(copy);
  printf("\n");
      
  }*/
void sortare(LIST *lista) {
    if (lista == NULL) return;

    LIST *p, *q;
    int temp;
    int sorted;

    do {
        sorted = 1;
        p = lista;

        while (p->next != NULL) {
            q = p->next;
            if (p->elem > q->elem) {
                // Schimbăm elementele
                temp = p->elem;
                p->elem = q->elem;
                q->elem = temp;
                sorted = 0;
            }
            p = p->next;
        }
    } while (sorted!=1);// SE TOT INTOARCE PANA CAND TOATA LISTA E SORTATA COMPLET 
}
LIST *inserare_mijloc(LIST *lista,int elem)
{
  LIST *p=lista;
  while(p!=NULL && p->elem<elem && p->next->elem<=elem )
      p=p->next;
  if(p==NULL)
    return lista;
  p->next=inserare_inceput(p->next,elem);
  return lista;
      

}
int main()
{
  LIST *lista=NULL;
  lista=inserare_sfarsit(lista,6);
  lista=inserare_sfarsit(lista,5);
  lista=inserare_sfarsit(lista,8);
  lista=inserare_sfarsit(lista,2);
  lista=inserare_sfarsit(lista,1);
  lista=inserare_sfarsit(lista,6);
  printf("LISTA INIT:");
  afis(lista);
  printf("\n");
  sortare(lista);
    printf("LISTA SORTATA:");
  afis(lista);
  printf("\n");
  printf("LSITA DUPA ADAUGARE:");
  lista=inserare_mijloc(lista,7);
  afis(lista);
  printf("\n");
    
  return 0;
}
