#include<stdio.h>
#include<stdlib.h>

typedef struct LIST {
  int elem;
  struct LIST *next;
}LIST;

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
      p=p->next;
    }
}

LIST *creare_nod(int elem,LIST *next)
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
LIST *inserare_inceput(int elem,LIST *lista)
{
  return creare_nod(elem,lista);

}
LIST *inserare_dupax(int elem,LIST *lista,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    {
      p=p->next;
    }
  if(p==NULL)
    return lista;
  p->next=inserare_inceput(elem,p->elem);
  return lista;
  
}
LIST *inserare_sfarsit(int elem,LIST *lista)
{
  LIST *p=NULL;
  LIST *aux=creare_nod(elem,NULL);
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
      
    }
  return lista;
     
}
LIST *stergere_inceput(int elem,LIST *lista)
{
  if(lista==NULL)
    return lista;
  LIST *p=lista;
  lista=lista->next;
  free(p);
  return lista;
}
LIST *stergere_final(int elem,LIST *lista)
{
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {  free(lista);
      return NULL;
    }
  LIST *p=lista;
  while(p->next->next!=NULL)
    {
      p=p->next; 
    }
  LIST *q=NULL;
  q=p->next;
  p->next=NULL;
  free(q);
  return lista;
    
}
LIST *stergere_random(int elem,LIST *lista)
{
  list *p=NULL;
  if(lista==NULL)
    return lista;
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
      
void free(LIST *lista)
{
  LIST *aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }
}


}

  


////LISTE DUBLU INLANTUITE


typedef struct LIST {

  int elem;
  struct LIST *prev;
  struct LIST *next;
}LIST;

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      prfintf("%d ",p->elem);
      p=p->next;
    }
}
LIST *creare_nod(int elem,LIST *prev,LIST *next)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));
  if(aux==NULL)
    {
      ...}
  aux->prev=prev;
  aux->next=next;
  aux->elem=elem;
  return aux;
}

LIST *inserare_inceput(int elem,LIST *lista)
{
  return creare_nod(elem,NULL,lista);
}
LIST *inserare_sfarsit(int elem,LIST *list)
{
  LIST *p=lista,*aux=NULL;
  aux=creare_nod(elem,lista,NULL);
  if(lista==NULL)
    aux=lista;
  else
    {
      while(p->next!=NULL)
	{
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
}
LIST *stergere(int elem,LIST *lista)
{

  LIST *p=lista,*aux=NULL;
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {
      p=lista;
      lista=lista->next;
      lista=lista->prev;
      free(p);
      return lista;
    }
  if(p->next->elem==elem)
    {
      aux=p->next;
      p->next=NULL;
      free(aux);
      return lista;
    }
  while(p->next->next!=NULL)
    {
      if(p->next->elem==elem)
	{
	  aux=p->next;
	  p->next=p->next->next;
	  p>next->prev=p;
	  free(aux);
	  return lista;
	  break;
	}
    }
	  
}
  
