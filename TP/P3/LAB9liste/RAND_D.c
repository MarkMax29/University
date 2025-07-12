/*Se citesc din fișierul text nr.txt un număr natural n și apoi n litere.
a) Să se creeze lista simplu înlănțuită ordonată care să rețină literele în ordine alfabetică. Se va folosi doar o
funcție de adaugare de elemente noi în listă în ordine.
b) Să se scrie o funcție care primește o listă simplu înlănțuită de litere și schimbă ordinea a două elemente care
sunt consecutive doar dacă primul e vocală și al doilea e consoană, altfel le lasă în ordinea găsită. Să se
aplice această funcție pe lista creată la punctul a) de atâtea ori până lista rezultată este aceeași cu lista primită ca
parametru (nu se mai modifică lista prin aplicarea funcției).
Exemplu: intrare: 7 e f c a d b i
a) Lista inițială în ordine alfabetică: a b c d e f i
b) iteratia 1: b a c d f e i
iteratia 2: b c a d f e i
iteratia 3: b c d a f e i
iteratia 4: b c d f a e i
iteratia 5: b c d f a e i (e la fel lista ca si la iteratia 4, ne oprim si afisam lista finala)
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct LIST{
  char elem;
  struct LIST *next;
}LIST;

LIST *creare_nod(LIST *next,char elem)
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

LIST *inserare_sfarsit(LIST *lista,char elem)
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
void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%c ",p->elem);
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
void sortare(LIST *lista)
{
  if(lista==NULL)
    return;

  int sorted;
  char aux;
  LIST *p=NULL,*q=NULL;
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
	  p=p->next;}
    }while(sorted!=1);

}
LIST *sub_a()
{
  FILE *f=NULL;
  f=fopen("citire.txt","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  int n;
  char c;
  LIST *lista=NULL;
  fscanf(f,"%d",&n);
  while(n!=0)
    { fscanf(f,"%c",&c);
      if(isalpha(c))
	{
	  lista=inserare_sfarsit(lista,c);
	  n--;
	}
    }
    
   sortare(lista);
   // afis(lista);
   // printf("\n");
   return lista;


}
void sub_b(LIST *lista)
{
  LIST *p=NULL,*q=NULL;
  char aux;
  int iter=1,modifica;
  do{
      p=lista;
      modifica=1;
      while(p->next!=NULL)
	{
	  q=p->next;
	  if((strchr("aeiou",p->elem)) && (strchr("aeiou",q->elem)==0))
	    {  aux=p->elem;
	      p->elem=q->elem;
	      q->elem=aux;
	      modifica=0;
	      p=p->next;
	    }
	  p=p->next;
	}
      printf("ITERATIA %d: ",iter);
      afis(lista);
      printf("\n");
      iter++;
      
  }while(modifica!=1);	
  
  
}
int main()
{
  LIST *lista=NULL;
  lista=sub_a();
  sub_b(lista);
  elib(lista);

  return 0;
}
