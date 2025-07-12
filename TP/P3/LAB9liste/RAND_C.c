/*4,5p) Se genereaza aleator un vector A format din numere naturale, din intervalul 1-100, pe un total de 20 pozitii. Se
genereaza tot aleator un numar natural B, in intervalul 1-2. Să se creeze o listă simplu înlănțuită cu elementele
vectorului. Sa se scrie o functie care parcurge lista, “eliminand” din ea elementele de pe pozitii impare, daca B=1 sau
pare daca B=2. Dupa fiecare parcurgere se afiseaza numarul iteratiei si lista. Se continua pana cand mai este doar un
singur element.
Exemplu: A= 2 5 7 8 9 10 1 3 6 4 (simplificat), B=1
Afiseaza:
Iteratia 1: 5 8 10 3 4
Iteratia 2: 8 3
Iteratia 3: 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
  aux->next=next;
  aux->elem=elem;
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
/*LIST *stergere_mijloc(LIST *lista,int elem)
{
  LIST *p=NULL;
  if(lista==NULL)
    return NULL;
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
  p=lista->next;
  LIST *prev=lista;
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
  }*/
LIST *stergere_mijloc(LIST *lista, int elem) {
    LIST *p = lista, *prev = NULL;
    while (p != NULL) {
        if (p->elem == elem) {
            if (prev == NULL) {
                lista = p->next;  // Ștergem primul nod
            } else {
                prev->next = p->next;  // Ștergem un nod din mijloc sau final
            }
            free(p);
            return lista;
        }
        prev = p;
        p = p->next;
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
void prb()
{
  int A[20],B;
  LIST *lista=NULL;
  srand(time(NULL));
  for(int i=0;i<20;i++)
    {

      A[i]=rand()%100+1;
      lista=inserare_sfarsit(lista,A[i]);

    }
  afis(lista);
  printf("\n");
  srand(time(NULL));
  B=rand()%2+1;
  int iter=1,poz;
  if(B==1 || B==2)
    {
      while(lista!=NULL && lista->next!=NULL)
	{
	  LIST *p=lista;
	  poz=1;
	  while(p!=NULL)
	    {
	      LIST *next=p->next;
	      if((B==1 && poz%2==1) || (B==2 && poz%2==0))
		lista=stergere_mijloc(lista,p->elem);
	      p=next;
	      poz++;
	      
	    }
	  printf("ITERATIA %d: ",iter);
	  afis(lista);
	  printf("\n");
	  iter++;
	  
	}
    }
  
}
int main()
{
  prb();
  return 0;
}
