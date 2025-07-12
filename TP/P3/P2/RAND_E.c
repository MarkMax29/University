/*2. Să se scrie un program care citește din linia de comandă mai multe șiruri de caractere și creează câte o listă simplu
înlănțuită pentru fiecare șir de caractere care conține în noduri literele cuvântului. Să se scrie o funcție care șterge
toate caracterele care apar de mai multe ori în lista primită ca parametru. Să se apeleze funcția pentru fiecare listă
creată din șirurile de caractere și afișează rezultatele pe ecran.
INPUT: ./exe programare examen sambata
OUTPUT:
Listele după prelucrare:
pogme
xamn
smbt
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

LIST *stergere_mijloc(LIST *lista,char elem)
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
      
}

void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%c",p->elem);
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
int main(int argc,char ** argv)
{
  LIST *p=NULL,*q=NULL;
  for(int i=1;i<argc;i++)
    {
      LIST *lista=NULL;
      for(int j=0;j<strlen(argv[i]);j++)
	{
	  lista=inserare_sfarsit(lista,argv[i][j]);
	}
      p=lista;
      // prev=p;
      int contor=1;
      while(p->next!=NULL)
	{
	  char ch=p->elem;
	   contor=1;
	  q=p->next;
	  while(q!=NULL)
	    {
	      if(p->elem==q->elem)
		contor++;
	      q=q->next;
	    }
	  if(contor>1)
	    {
	      //p=p->next;
	      while(contor!=0)
		{
		  lista=stergere_mijloc(lista,ch);
		  contor--;	  
		}
	       p=lista;
	    }
	  else
	    p=p->next;
	}
      afis(lista);
      printf("\n");
      elib(lista);
    }
	 

  return 0;
}
