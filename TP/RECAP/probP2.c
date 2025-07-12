#include<stdio.h>
#include<stdlib.h>
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
LIST *random_x(LIST *lista, char elem)
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
  p=lista->next; //daca nu merge aici e baiu un pic 
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
void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%c",p->elem);
      p=p->next;
    }
}

void eliberare(LIST *lista)
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
  LIST *lista=NULL,*lista1=NULL;
  char ch;
  for(int i=1;i<argc;i++)
    {
      lista=NULL;
      lista1=NULL;
      int len=strlen(argv[i]);
      for(int j=0;j<=len-1;j++)
	lista=inserare_sfarsit(lista,argv[i][j]);
      lista1=lista;
      LIST *p=lista1;
      while(p!=NULL)
	{
	  int voc=0;
	  if(strchr("aeiou",p->elem))
	    {
	      ch=p->elem;
	      voc++;
	    }
	  LIST *q=p->next;
	  //ok=1; 
	  while(q!=NULL)
	    {
	      if(ch==q->elem)
		voc++;
	      q=q->next;
	    }
	  if(voc!=1 && voc!=0)
	    {
	      while(voc!=0)
		{
		  lista1=random_x(lista1,ch);
		  voc--;
		  p=lista1;
		}
	    }
	  else
	  p=p->next;
	}
      if(lista1==NULL)
	printf("<gol>\n");
      else
	{
	  afisare(lista1);
	  printf("\n");
	}
      
     
    }
  eliberare(lista);

  return 0;
}
