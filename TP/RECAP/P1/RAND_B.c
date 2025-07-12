#include<stdio.h>
#include<stdlib.h>
/*Sa se implementeze o functie în C care primeste un numar natural n, construieste si afiseaza o listă dublu
înlănțuită formată din primele 2𝑛 numere naturale, dispuse astfel:
• se pleacă de la lista 1 2
• exact la mijlocul acestei liste se inserează elementele 3 4 și se obține 1 3 4 2
• exact la mijlocul acestei liste se inserează elementele 5 6 7 8 și se obține 1 3 5 6 7 8 4 2
• etc.
• în general, la mijlocul șirului format din primele 2𝑘 numere naturale se inserează șirul ordonat format din
următoarele 2𝑘 numere naturale.
Se va implemente o functie main() adecvata si orice alte functii necesare. Să se afișeze toate listele intermediare obținute.
*/

typedef struct LIST{
  int elem;
  struct LIST *next,*prev;
}LIST;

LIST *creare_nod(LIST *next,LIST *prev,int elem)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));
  if(aux==NULL)
    {
      printf("eroare la alocare");
      exit(-1);
    }
  aux->elem=elem;
  aux->next=next;
  aux->prev=prev;
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
  LIST *aux=creare_nod(NULL,NULL,elem);
  LIST *p=NULL;
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
      aux->prev=p;
    }
  return lista;
}
LIST *inserare_inceput(int elem,LIST *lista)
{
 LIST *aux=creare_nod(lista,NULL,elem);
 if(lista!=NULL)
   lista->prev=aux;
 return aux;
}
  
LIST *inserare_dupa_x(int elem,LIST *lista,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    {
      p=p->next;
    }
  if(p==NULL)
    return lista;
  
  LIST *aux=creare_nod(p->next,p,elem);
  
  if(p->next!=NULL)
    p->next->prev=aux;
  
  p->next=aux;
  
  return lista;
  
}
void free_list(LIST *lista)
{
  LIST *aux = NULL;
  while (lista != NULL)
    {
      aux = lista->next;
      free(lista);
      lista = aux;
    }
}

int mijloc(LIST *lista,int *nr)
{

  LIST *p=lista;
  int i=1;
  while(i!=*nr/2)
    {
      p=p->next;
      i++;
    }
  return p->elem;

}

int main()
{
  LIST *lista=NULL;
  int n,c=1;
  scanf("%d",&n);//citesc 
  int nr=1,k=0,x;
  if(n==0)
    {
      lista=inserare_sfarsit(lista,nr);
      printf("iteratie %d:",c);
      afisare(lista);
      printf("\n");
	     
    }
  else
    {
      while(n!=0)
	{
	  nr=nr*2;
	  if(lista==NULL)
	    {
	      for(int i=1;i<=nr;i++)
	      {
		lista=inserare_sfarsit(lista,i);
	      }
	      k=nr;
	    }
	  else
	    {
	      x=mijloc(lista,&k);
	      for(int i=k+1;i<=nr;i++)
		{
		  lista=inserare_dupa_x(i,lista,x);		
		  x=i;
		}
	      k=nr;
	    }
	  printf("iteratie %d:",c);
	  afisare(lista);
	  printf("\n");
	  c++;
	  n--;
	}
    }	       		 
  return 0;
}
