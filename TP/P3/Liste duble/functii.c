/*Aplicația 8.5: Să se imlementeze o listă dublu înlănțuită care gestionează un parc de automobile. Informaţiile
relative la un automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai
putere între 1 și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile,
datele sunt citite de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou în listă la începutul listei;
b) Ștergerea unui anumit automobil din listă, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste pe ecran;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.

*/


#include<stdio.h>
#include<stdlib.h>


typedef struct MASINA{
  unsigned int cod:14;
  unsigned int nr_loc:4;
  unsigned int putere:9;
  unsigned int an_fab:11;
  char marca[15];
  char culoare[10];
}MASINA;

typedef struct LIST{
  MASINA elem;
  struct LIST *next;
  struct LIST *prev;
}LIST;

LIST *creare_nod(LIST *next,LIST *prev,MASINA elem)
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
  aux->prev=prev;
  return aux;
     
}
LIST *inserare_inceput(MASINA elem,LIST *lista)
{
  LIST *aux=creare_nod(lista,NULL,elem);
  if(lista!=NULL)
    lista->prev=aux;
  return aux;
}
LIST *inserare_sfarsit(MASINA elem,LIST *lista)
{
  LIST *p=NULL,*aux=creare_nod(NULL,NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      p=lista;
      while(p->next!=NULL)
	p=p->next;
      p->next=aux;
      aux->prev=p;
    }
  return lista;
	  
}
/*LIST *inserare_dupa_x(LIST *lista,int elem,int x)
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
*/
LIST *stergere_inceput(LIST *lista)
{
  if(lista==NULL)
    return NULL;
  LIST *aux=lista;
  lista=lista->next;
  if(lista!=NULL)
    lista->prev=NULL;
  free(aux);
  return lista;
}
     
LIST *stergere_sfarsit(LIST *lista)
{
  if(lista==NULL)
    return NULL;
  if(lista->next==NULL)
    {
      free(lista);
      return NULL;
    }
  LIST *p=lista;
  while(p->next!=NULL)
    p=p->next;
  p->prev->next=NULL;
  free(p);  
  return lista;
}
LIST *stergere_random(LIST *lista,int elem)
{
  LIST *p=lista;
  if(lista==NULL)
    return NULL;
  if(lista->elem.cod==elem)
    return stergere_inceput(lista);
  while(p!=NULL)
    {
      if(p->elem.cod==elem)
	{
	  if(p->next!=NULL)
	    {
	      p->prev->next=p->next;
	      p->next->prev=p->prev;
	    }
	  else
	    {
	      p->prev->next=NULL;
	      free(p);
	      return lista;
	    }
	}
	  p=p->next;
    }
  return lista;
      

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
void afis(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%d %d %d %d %s %s ",p->elem.cod,p->elem.nr_loc,p->elem.putere,p->elem.an_fab,p->elem.marca,p->elem.culoare);
      p=p->next;
    }
}
MASINA citire_automobil() {
    MASINA masina;
    int cod,nr_loc,putere,an_fab;
    printf("Introduceti codul masinii (intre 1 si 9000): ");
    scanf("%d", &cod);
    masina.cod=cod;
    printf("Introduceti numarul de locuri (intre 1 si 9): ");
    scanf("%d", &nr_loc);
    masina.nr_loc=nr_loc;
    printf("Introduceti puterea masinii (CP, intre 1 si 500): ");
    scanf("%d", &putere);
    masina.putere=putere;
    printf("Introduceti anul fabricatiei (intre 1800 si 2017): ");
    scanf("%d", &an_fab);
    masina.an_fab=an_fab;
    printf("Introduceti marca masinii: ");
    scanf("%s", masina.marca);
    printf("Introduceti culoarea masinii: ");
    scanf("%s", masina.culoare);
    return masina;
}
void introducere_noua(MASINA masina,int *i,LIST *list)
{

  printf("MASINA:%d\n",*i+1);
  masina=citire_automobil();
  list=inserare_inceput(masina,list);
  *i=*i+1;
}
int main()
{
  int n,i;
  printf("INTRODUCETI NR DE MASINA:");
  scanf("%d",&n);
  MASINA masina;
  LIST *list=NULL;
  for(i=0;i<n;i++)
    {
      printf("MASINA:%d\n",i+1);
      masina=citire_automobil();
      list=inserare_sfarsit(masina,list);
      
    }
  printf("LISTA ESTE:\n");
  afis(list);
  printf("\n");
  /* introducere_noua(masina,&i,list);
  printf("DUPA INTTRODUCERE:");
  afis(list);
  printf("\n");*/
  int c;
  printf("Introduceti un cod(0 la 9000)");
  scanf("%d",&c);
  stergere_random(list,c);
  printf("LISTA DUPA STERGERE:");
  afis(list);
  printf("\n");

}
	     

  
