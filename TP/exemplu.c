#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  CHUNK 10
typedef struct LIST{
  char elem;
  struct LIST *next;
 
}LIST;

LIST *creare_lista(LIST *next,char elem)
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

  LIST *p=NULL,*aux=creare_lista(NULL,elem);
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
/*LIST *sterge_random(LIST *lista,char elem)
{
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {  free(lista);
      return NULL;
    }

    }*/
LIST *sterg(LIST *lista)
{
  LIST *p=lista,*q=NULL,*lista1=NULL;
  int ok;
  char ch='\0';
  while(p!=NULL)
    {
      ok=1;
      q=p->next;
 
      while(q!=NULL && ok!=0)
	{
	  if(p->elem==q->elem)
	    {
	      ok=0;
	      ch=q->elem;
	      break;
	    }
	  
	  q=q->next;
	}
      if(ok==1 && ch!=p->elem)
	 lista1=inserare_sfarsit(lista1,p->elem);	
      p=p->next;
    }
    
  return lista1;

  
}
int main(int argc,char ** argv)
{
 
  for(int i=1;i<argc;i++)
    {
      LIST *lista=NULL,*lista1=NULL;
      int size=strlen(argv[i]);
      for(int j=0;j<size;j++)
	{
	  if((argv[i][j]>='a' && argv[i][j]<='z')|| (argv[i][j]>='A' && argv[i][j]<='Z'))
	    {
	      lista=inserare_sfarsit(lista,argv[i][j]);
	    }
	}
      
      lista1=sterg(lista);
      afisare(lista1);
      printf("\n");
      eliberare(lista1);
   
    }
  return 0;
}
