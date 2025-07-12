/*. Sa se implementeze o functie în C care primeste un numar natural n, construieste si afiseaza o listă dublu
înlănțuită formată din primele 2𝑛 numere naturale, dispuse astfel:
• se pleacă de la lista 1 2
• exact la mijlocul acestei liste se inserează elementele 3 4 și se obține 1 3 4 2
• exact la mijlocul acestei liste se inserează elementele 5 6 7 8 și se obține 1 3 5 6 7 8 4 2
• etc.
• în general, la mijlocul șirului format din primele 2𝑘 numere naturale se inserează șirul ordonat format din
următoarele 2𝑘 numere naturale.
Se va implemente o functie main() adecvata si orice alte functii necesare. Să se afișeze toate listele intermediare obținute
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct LIST{
  int elem;
  struct LIST *next;
  struct LIST *prev;
}LIST;
LIST *creare_nod(LIST *next,LIST *prev,int elem)
{
  LIST *aux=NULL;
  aux=(LIST *)malloc(sizeof(LIST));
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
    {p=lista;
      while(p->next!=NULL)
	p=p->next;
      p->next=aux;
      aux->prev=p;
    }
  return lista;
    
}
LIST *inserare_mijloc(LIST *lista,int elem,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    p=p->next;
  if(p==NULL)
    return lista;
  LIST *aux=creare_nod(p->next,p,elem);
  if(p->next!=NULL)
    p->next->prev=aux;
  p->next=aux;
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
LIST *pb(LIST *lista,int n)
{
  int nr=1,k=0,i=0;
  LIST *p=NULL;
  while(n!=1)
    {
      p=lista;
      k=0;
      nr=nr*2;
      i=1;
      while(i!=nr/2)
	{
	  p=p->next;
	  i++;
	}
      k=nr+1;
      while(k!=nr*2)
	{
	  lista=inserare_mijloc(lista,k,p->elem);
	  k++;
	  p=p->next;
	}
      lista=inserare_mijloc(lista,k,p->elem);
      n--;
    }
  
  return lista;    

}
		    
int main()
{
  LIST *lista=NULL;
  int n;
  scanf("%d",&n);
  lista=inserare_sfarsit(lista,1);
  lista=inserare_sfarsit(lista,2);
  lista=pb(lista,n);
  afis(lista);
  printf("\n");

  return 0;
}
