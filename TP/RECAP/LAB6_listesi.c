/*#include<stdio.h>
#include<stdlib.h>
typedef struct LIST{
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
LIST *creare_nod(LIST*next,int elem)
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

LIST *inserare_inceput(LIST *lista ,int elem)
{
  return creare_nod(lista,elem);
}

LIST *inserea_dupa_x(LIST*lista,int elem,int x)
{
  LIST *p=lista;
  while(p!=NULL && p->elem!=x)
    {
      p=p->next;
    }
  if(p==NULL)
    return lista;
  p->next=inserare_inceput(p->next,elem);
  return lista;
  
}
LIST *inserare_sfarsit(LIST *lista,int elem)
{
  LIST *p=NULL;
  LIST *aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;  ///daca lista e goala lista creaza un nod si primeste adresa aia
  else
    {
      p=lista;
      while(p->next!=NULL)// altfel parcurg pana p->next=NULL si schimb sagetuta la p->next cand a ajuns la ultimul nod 
	p=p->next;
      p->next=aux;
    }
  return lista;
}

LIST *stergere_inceput(LIST *lista)
{
  if(lista==NULL)
    return lista;
  LIST*p=lista;
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
    {  free(lista);
      return NULL;
    }
  p=lista;
  while(p->next->next!=NULL)
    {
      p=p->next;
    }
  q=p->next;
  p->next=NULL;
  free(q);
  return lista;
}

LIST *stergere_random_x(LIST*lista,int elem)
{
  LIST*p=NULL;
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
  LIST*prev=lista;
  p=lista->next;
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

void free_lista(LIST *lista)
{
  LIST*aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }
}
	

LIST *inversare(LIST *lista)
{
  LIST *p=NULL,*q=NULL,*prev=NULL;
  prev=lista;
  p=lista->next;
  prev->next=NULL;
  while(p!=NULL)
    {
      q=p;
      p=p->next;
      q->next=prev;
      prev=q;
    }
  lista=prev;

  return lista;
    
  

}
  
  
void pb7_2()
{
  LIST *lista=NULL;
  lista=inserare_sfarsit(lista,1);
  lista=inserare_sfarsit(lista,2);
  lista=inserare_sfarsit(lista,3);
  lista=inserare_sfarsit(lista,4);
  lista=inserare_sfarsit(lista,5);
  afisare(lista);
  printf("\n");
  LIST *lista2=inversare(lista);
  afisare(lista2);
}


int main()
{
  pb7_2();
  return 0;
}
*/


/*In doua fisiere text MultimeA.TXT si MultimeB.TXT se gasesc 2 multimi A si respectiv B
cu elemente numere naturale.
a) Sa se creeze cate o lista liniara simplu inlantuita pentru memorarea elementelor din fiecare
dintre cele 2 multimi.
b) Sa se scrie o functie care primeste parametrii adresele primului nod ale celor 2 multimi si
creaza si returneaza o noua lista liniara simplu inlantuita care memoreaza reuniunea celor 2
multimi.
c) Sa se scrie o functie care primeste parametrii adresele primului nod ale celor 2 multimi si
creaza si returneaza o noua lista liniara simplu inlantuita care se memoreze intersectia celor 2
multimi.
d) Sa se modifice informatiile din cele 2 fisiere din care s-a citit astfel incat fiecare fisier, pe
langa multimea initiala, sa contina, pe urmatoarele 2 randuri multimea reuniune, respectiv
multimea intersectie*/


#include<stdio.h>
#include<stdlib.h>

typedef struct LIST{
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

LIST *inserare_inceput(LIST*lista,int elem)
{
  return creare_nod(lista,elem);
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
	{
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
}

LIST *prob_aA(LIST *listaA)
{
  FILE *A=NULL;
  A=fopen("MultimeA.TXT","r");
  if(A==NULL)
    {
      perror(NULL);
      exit(-1);
    }
 
  int n;
  listaA=NULL;
  while(fscanf(A,"%d",&n)==1)
    {
      listaA=inserare_sfarsit(listaA,n);
    }
  return listaA;
  fclose(A);
 
  
  
}
LIST *prob_aB(LIST *listaB)
{
  FILE *B=NULL;
  B=fopen("MultimeB.TXT","r");
  if(B==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  int m;
  listaB=NULL;
  while(fscanf(B,"%d",&m)==1)
    {
      listaB=inserare_sfarsit(listaB,m);
    }
   return listaB;
    fclose(B);
}

LIST *prob_b(LIST *listaA,LIST *listaB)
{
  int ok=1;
  LIST *listaAB=NULL,*p=NULL,*q=NULL,*aux=NULL;
  p=listaA;
  listaAB=inserare_sfarsit(listaAB,p->elem);
  p=p->next;
  while(p!=NULL)
    {
      ok=1;
      aux=listaAB;
      while(aux!=NULL)
	{
	  if(p->elem==aux->elem)
	    ok=0;
	  aux=aux->next;
	}
      if(ok==1)
	listaAB=inserare_sfarsit(listaAB,p->elem); 
      p=p->next;
    }
  
  q=listaB;
  while(q!=NULL)
    {
      ok=1;
      aux=listaAB;
      while(aux!=NULL)
	{
	  if(q->elem==aux->elem)
	    ok=0;
	  aux=aux->next;
	}
      if(ok==1)
	listaAB=inserare_sfarsit(listaAB,q->elem);
      q=q->next;
    }
  return listaAB;
  
}
int verificare(int elem,LIST *rez)
{
  LIST *p=rez;
  int ok=1;
  while(p!=NULL)
    {
      if(elem==p->elem)
	  ok=0;
      p=p->next;
    }
  return ok;
  

}
LIST *intersectie(LIST *listaA,LIST *listaB)
{
  int ok;
  LIST *p=NULL,*q=NULL,*listaAB=NULL;
  p=listaA;

  while(p!=NULL)
    {
        q=listaB;
      while(q!=NULL)
	{
	  if(q->elem==p->elem)
	    {
	      if((ok=verificare(q->elem,listaAB))==1)
		listaAB=inserare_sfarsit(listaAB,q->elem);
	      break;
	    }
	  q=q->next;
	}
      p=p->next;
    }
  return listaAB;
}

int main()
{
  LIST *listaA=NULL,*listaB=NULL,*listaAB=NULL;
  listaA=prob_aA(listaA);
  listaB=prob_aB(listaB);
  afisare(listaA);
  printf("\n");
  afisare(listaB);
  printf("\n");
  listaAB=prob_b(listaA,listaB);
  afisare(listaAB);
  printf("\n");
  listaAB=intersectie(listaA,listaB);
  afisare(listaAB);
  


  return 0;
}



