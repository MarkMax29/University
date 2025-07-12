#include <stdio.h>
#include<stdlib.h>
union CARACT{
  char tara[20];
  int gen_haine:2;//0-barbati,1-femei,2-copii
  int karate;
  int cmsprod;///pretul celui mai scump produs;
};

  typedef struct MAGAZIN{
    unsigned int tip_mag:3;
    unsigned int nr_mag:13;
    float metrii;
    char nume_mag[25];
    union CARACT caracteristici;
  }MAGAZIN;

typedef struct LIST{
  MAGAZIN elem;
  struct LIST *next;
}LIST;

LIST *creare_nod(LIST *next,MAGAZIN elem)
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
LIST *inserare_sfarsit(LIST *lista,MAGAZIN elem)
{
  LIST *p=NULL,*aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      p=lista;
      while(p->next!=NULL)
	{
	  p=p->next;}
      p->next=aux;
    }
  return lista;
}     

LIST *citire(LIST *lista)
{
  int n,tip_mag,nr_mag,gen_haine;
  //LIST *lista=NULL;
  printf("INTRODUCETI NR DE MAGAZINE DIN BAZAR:");
  scanf("%d",&n);
  MAGAZIN v[n];
  for(int i=0;i<n;i++)
    {
      printf("tip magazin=");
      scanf("%d",&tip_mag);
      v[i].tip_mag=tip_mag;
      printf("nr de magazine=");
      scanf("%d",&nr_mag);
      v[i].nr_mag=nr_mag;
      printf("metrii patrati=");
      scanf("%f",&v[i].metrii);
      printf("nume magazin=");
      scanf("%24s",v[i].nume_mag);

      switch(v[i].tip_mag)
	{

	case 1:
	  {
	    printf("magazin de ceaiuri\n introdu tara:");
	    scanf("%19s",v[i].caracteristici.tara);
	    break;
	  }
	case 2:
	  {
	    printf("magazin de imbracaminte\n introdu tipul de haine:");
	    scanf("%d",&gen_haine);
	    v[i].caracteristici.gen_haine=gen_haine;
	    break;
	  }
	case 3:
	  {
	    printf("magazin de podoabe\n introdu numarul de karate:");
	    scanf("%d",&v[i].caracteristici.karate);
	    break;
	  }
	case 4:
	  {
	    printf("magazin de suveniruri\n introdu cel mai scump produs:");
	    scanf("%d",&v[i].caracteristici.cmsprod);
	    break;
	  }
	}
      lista=inserare_sfarsit(lista,v[i]);
      
    }
  return lista;
}

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      switch(p->elem.tip_mag)
	{
	case 1:
	  {
	    printf("%s - %d - %d - %.2f - %s\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.tara);
	    break;
	  }
	case 2:
	  {
	    switch(p->elem.caracteristici.gen_haine)
	      {
	      case 0:
		{
		  printf("%s - %d - %d - %.2f - haine de barbati\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      case 1:
		{
		  printf("%s - %d - %d - %.2f - haine de femei\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      case 2:
		{
		  printf("%s - %d - %d - %.2f - haine de copii\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      }
	    break;
	  }
	case 3:
	  {
	    printf("%s - %d - %d - %.2f - %d\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.karate);
	    break;
	  }
	case 4:
	  {
	    printf("%s - %d - %d - %f - %d\n",p->elem.nume_mag,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.cmsprod);
	    break;
	  }
	}
      p=p->next;
    }
}
int main()
{
  LIST *lista=NULL;
  lista=citire(lista);
  afisare(lista);
  
  return 0;
}
