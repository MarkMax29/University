#include<stdio.h>
#include<stdlib.h>

typedef struct LIST{
  int elem;
  struct LIST *next;
}LIST;

LIST *creare_nod(int elem,LIST *next)
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
  return aux;
  
}
LIST *inserare_inceput(int elem,LIST *lista)
{
  return creare_nod(elem,lista);
}
/// ex7.1: S a se scrie o functie care primeste 2 liste si returneaza 1 daca ele sunt identice,altel 0.

int verificare(LIST *l1,LIST *l2)
{
  LIST *p=l1;
  LIST *q=l2;
  while(p!=NULL && q!=NULL)
    {
      if(p->elem!=q->elem)
	return 0;
      p=p->next;
      q=q->next;
      
    }
  if(p!=NULL || q!=NULL)
    return 0;
  return 1;

}
void pb_7_1()
{
  LIST *lista1=NULL;
  LIST *lista2=NULL;
  lista1=inserare_inceput(6,lista1);
  lista1=inserare_inceput(3,lista1);
  lista1=inserare_inceput(2,lista1);

  lista2=inserare_inceput(6,lista2);
   lista2=inserare_inceput(3,lista2);
 lista2=inserare_inceput(2,lista2);

 if(verificare(lista1,lista2)==1)
   printf("cele doua liste sunt egale\n");
 else
   printf("cele doua liste nu sunt egale\n");
}
LIST *inversare(LIST *lista)
{
  LIST *p=NULL,*aux=NULL,*prev=NULL;
  prev=lista;
  p=lista->next;
  prev->next=NULL;
  while(p!=NULL)
    {
      aux=p;
      p=p->next;
      aux->next=prev;
      prev=aux;
    }
  lista=prev;
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

void pb7_2()
{
  /// Sa se scrie o functie care primeste o lista si returneaza lista respectiva cu elementele inversate.
  ///Functia va actiona doar asupra listei originale, fara a folosi vectori sau alocare de noi elemente.3
  LIST *lista=NULL;
  lista=inserare_inceput(4,lista);
  lista=inserare_inceput(3,lista);
  lista=inserare_inceput(2,lista);
  lista=inserare_inceput(1,lista);
  LIST *rez=NULL;
  rez=inversare(lista);
  afisare(rez);
  
  
}

LIST *reuniune(LIST *lista1,LIST *lista2)
{
  LIST *p=lista1;
  LIST *q=lista2;
  LIST *lista=NULL;
  int ok;
  LIST *k=NULL;
  lista=inserare_inceput(p->elem,lista);
  p=p->next;
  while(p!=NULL)
    {
      ok=1;
      k=lista;
      while(k!=NULL)
	{
	  if(p->elem==k->elem)
	    ok=0;
	  k=k->next;
	}
      if(ok==1)
	lista=inserare_inceput(p->elem,lista);
      p=p->next;
    }
  while(q!=NULL)
    {
      ok=1;
      k=lista;
      while(k!=NULL)
	{
	  if(q->elem==k->elem)
	    ok=0;
	  k=k->next;
	}
      if(ok==1)
	lista=inserare_inceput(q->elem,lista);
      q=q->next;
    }
  return lista;

}

void pb7_3()
{
  ///Sa se scrie o functie care primeste ca parametri 2 liste si returneaza o lista care reprezinta reuniunea elementelor lor,fiecare element aparand o singura data, chiar daca in listele originale el este duplicat.

  LIST *lista1=NULL,*lista2=NULL;
  lista1=inserare_inceput(6,lista1);
  lista1=inserare_inceput(5,lista1);
  lista1=inserare_inceput(4,lista1);
  lista1=inserare_inceput(2,lista1);
  lista1=inserare_inceput(2,lista1);
  lista1=inserare_inceput(1,lista1);

  lista2=inserare_inceput(7,lista2);
  lista2=inserare_inceput(6,lista2);
  lista2=inserare_inceput(4,lista2);
  lista2=inserare_inceput(4,lista2);
  lista2=inserare_inceput(3,lista2);
  lista2=inserare_inceput(2,lista2);

  LIST *lista=NULL;
  lista=reuniune(lista1,lista2);
  afisare(lista);

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

void pb7_4()
{
  ///Pentru implementarea listei care memoreaza adresa ultimului element, sa se scrie o functie sterge, care sterge din lista un element dat.
  LIST *lista=NULL;
  lista=inserare_inceput(6,lista);
  lista=inserare_inceput(5,lista);
  lista=inserare_inceput(4,lista);
  lista=inserare_inceput(3,lista);
  lista=inserare_inceput(2,lista);
  lista=inserare_inceput(1,lista);
  lista=stergere_random(3,lista);
  afisare(lista);

}
int verificare2(LIST *lista1,LIST *lista2)
{
  LIST *p=lista1,*q=lista2;
  int ok;
  while(p!=NULL)
    {
      ok=0;
      q=lista2;
      while(q!=NULL)
	{
	  if(p->elem==q->elem)
	    ok=1;
	  q=q->next;
	}
      if(ok==0)
	  return 0;
      p=p->next; 
    }

  return 1;
   
}
void pb7_5()
{
  LIST *lista1=NULL,*lista2=NULL;

  lista1=inserare_inceput(2,lista1);
  lista1=inserare_inceput(1,lista1);

  lista2=inserare_inceput(2,lista2);
  lista2=inserare_inceput(2,lista2);
  lista2=inserare_inceput(1,lista1);
  int rez;
  rez=verificare2(lista1,lista2);
  if(rez==1)
    printf("%d - listele sunt egale",rez);
  else
    printf("%d - listele nu sunt egale",rez);
  
}
	      
int main()
{
  //pb_7_1();
  //pb7_2();
  //  pb7_3();
  // pb7_4();
  pb7_5();
  return 0;
}
