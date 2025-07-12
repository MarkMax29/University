#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 20
#define MAX 100
#define MIN 1
#define Bmax 2
#define Bmin 1
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

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
}
LIST *inserare_sfarsit(LIST *lista,int elem)
{
  LIST *aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      LIST *p=lista;
      while(p->next!=NULL)
	{
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
}
/*LIST *stergere(LIST *lista,int elem,int *b)
{
  LIST *p=NULL;
  if(lista==NULL)
    return NULL;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
	  while(p!=NULL)
	    {
	      if(i%2!=0)
		{
		  prev->next=p->next;
		  free(p);
		  i++;
		}
	      p=p->next;
	      prev=prev->next;
	      i++;
	    }
	  
  
    
    
}
*/
void free_list(LIST *lista)
{
  LIST *aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }
}
void pbC ()
{
  LIST *lista=NULL;
  int v[SIZE];
  srand(time(NULL));
  for(int i=0;i<SIZE;i++)
    v[i]=rand()%(MAX-MIN+1)+MIN;

  int b;
  b=rand()%(Bmax-Bmin+1)+Bmin;
  for(int i=0;i<SIZE;i++)
    lista=inserare_sfarsit(lista,v[i]);
  afisare(lista);
  printf("\n");

  LIST *lista1=lista;				\
  int k=1,c=SIZE;
  while(lista1!=NULL && lista1->next!=NULL)
    {
      LIST *p=lista1;
      LIST *lista2=NULL;

      int x = 0;

        // Parcurgere lista și creare lista2
        for (int i = 1; i <= c && p != NULL; i++) {
	  if ((b == 1 && i % 2 == 0) || (b == 2 && i % 2 != 0))
	    {
	      lista2 = inserare_sfarsit(lista2, p->elem);
	      x++;
	    }
	  p = p->next;
        }
	printf("ITERATIA %d: ",k);
	afisare(lista2);
	printf("\n");
	free_list(lista1);
	lista1=lista2;
	c=x;
	k++;
    }
  
}
int main()
{

  pb();
  return 0;
}
