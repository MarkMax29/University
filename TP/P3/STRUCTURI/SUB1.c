/*Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct AUTO{
 
  unsigned int cod:14;
  unsigned int nr_loc:4;
  unsigned int putere:9;
  unsigned int an_fab:11;
  char marca[15];
  char culoare[8];
}AUTO;

int introducere(int *size,AUTO *v)
{
  unsigned int cod,nr_loc,putere,an_fab;
  v=realloc(v,(*size+1)*sizeof(AUTO));
  if(v==NULL)
    {
      perror(NULL);
      free(v);
      exit(-1);
    }
  scanf("%15s %8s %d %d %d %d",(v+*size)->marca,(v+*size)->culoare,&cod,&nr_loc,&putere,&an_fab);
  (v+*size)->cod=cod;
  (v+*size)->nr_loc=nr_loc;
  (v+*size)->putere=putere;
  (v+*size)->an_fab=an_fab;
   *size=*size+1;
  return *size;    
}
void stergere(int *size,AUTO *v)
{
  unsigned int cod;
  printf("Introdu cod:");scanf("%d",&cod);
  for(int i=0;i<*size;i++)
    {
      if(v[i].cod==cod)
	{
	  for(int j=i;j<*size;j++)
	    {
	      v[j]=v[j+1];
	    }
	  *size=*size-1;
	}
    }
}
void afisare(int *size,AUTO *v)
{
    for(int i=0;i<*size;i++)
    {
      printf("marca:%s - culoare:%s - cod masina:%d - nr locuri:%d - putere:%d - an fabricatie:%d\n",v[i].marca,v[i].culoare,v[i].cod,v[i].nr_loc,v[i].putere,v[i].an_fab);
    }
}
void afis_nr_loc(int *size,AUTO *v)
{
  unsigned int loc;
  printf("Introdu nr de locuri: ");scanf("%d",&loc);
   for(int i=0;i<*size;i++)
    {
      if(v[i].nr_loc==loc)
	printf("marca:%s - culoare:%s - cod masina:%d - nr locuri:%d - putere:%d - an fabricatie:%d\n",v[i].marca,v[i].culoare,v[i].cod,v[i].nr_loc,v[i].putere,v[i].an_fab);
    }
  
}
int compar(const void *elem1,const void *elem2)
{
  const AUTO *e1=(const AUTO *)elem1;
  const AUTO *e2=(const AUTO *)elem2;
  if(e1->an_fab>e2->an_fab)
    return 1;
  else if(e1->an_fab<e2->an_fab)
    return -1;
  return 0;
    
}
void sortare(int *size,AUTO *v)
{
  qsort(v,*size,sizeof(AUTO),compar);
  printf("\n");
  afisare(size,v);
}
int main()
{

  int n;
  unsigned int cod,nr_loc,putere,an_fab;
  printf("Introdu n: ");scanf("%d",&n);
  AUTO *v=NULL;
  v=malloc(sizeof(AUTO)*n);
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      scanf("%15s %8s %d %d %d %d",v[i].marca,v[i].culoare,&cod,&nr_loc,&putere,&an_fab);
      v[i].cod=cod;
      v[i].nr_loc=nr_loc;
      v[i].putere=putere;
      v[i].an_fab=an_fab;
    }
  /*  afisare(&n,v);
  n=introducere(&n,v);
  afisare(&n,v);
  stergere(&n,v);
  afisare(&n,v);

  afis_nr_loc(&n,v);
  */
  sortare(&n,v);
  
  return 0;
}
