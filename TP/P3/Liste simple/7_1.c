/*Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.*/

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

LIST *inserare_dupa_x(LIST *lista,int elem,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    p=p->next;
  if(p==NULL)
    return lista;
  p->next=inserare_inceput(p->next,elem);//modific sagetuta care va arata spre noul elem inclus in lista iar sagetuta de la eleem nou se formeaza in creaza nod (cred)
  return lista;
}
LIST *inserare_sfarsit(LIST *lista,int elem)
{

  LIST *p=NULL;
  LIST *aux=creare_nod(NULL,elem);
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
LIST *stergere_inceput(LIST *lista)
{

  if(lista==NULL)
    return lista;
  LIST *p=lista;
  lista=lista->next;
  free(p);
  return lista;
}
LIST *stergere_sfarsit(LIST *lista)
{
  LIST *p=NULL,*q=NULL;
  if(lista==NULL)
    return lista;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
  p=lista;
  while(p->next->next!=NULL)
    p=p->next;
  q=p->next;
  p->next=NULL;
  free(q);
  return lista; 

}
LIST *stergere_random(int elem,LIST *lista)
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

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->elem);
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
int compar(LIST *lista1,LIST *lista2)
{
  LIST *p=lista1,*q=lista2;
  while(p!=NULL && q!=NULL)
    {
      if(p->elem!=q->elem)
	{
	  return 0;
	  break;
	}
      p=p->next;
      q=q->next;
    }
  return 1;
}

int main()
{
  int n,nr,i=0;
  LIST *lista1=NULL,*lista2=NULL;
  scanf("%d",&n);
  while(i!=n)
    {
      scanf("%d",&nr);
      lista1=inserare_sfarsit(lista1,nr);
      lista2=inserare_sfarsit(lista2,nr);
      //lista2=inserare_inceput(lista2,nr);
      i++;
    }
  afisare(lista1);
  printf("\n");
  afisare(lista2);
  printf("\n");
  if(compar(lista1,lista2))
    printf("CELE 2 LISTE SUNT IDENTICE\n");
  else
    printf("CELE 2 NU SUNT EGALE\n");
	
	    
      

  return 0;
  
}
