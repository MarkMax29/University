#include<stdio.h>
#include<stdlib.h>

typedef union CARACT{
  char tara[15];
  unsigned int tip_haine:2;
  unsigned int karate:5;
  int pretscump;
}CARACT;
  

typedef struct MAGAZIN{

  unsigned int tip_mag:2;
  unsigned int nr_mag:13;
  float metrii;
  char nume[20];
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
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
   
}
LIST *citire(LIST *lista)
{
  int tip_mag,nr_mag,tip_haine,karate;
  /* FILE *f=NULL;
  f=fopen("text.in","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
      }*/
  int n;
  printf("INTRODUCETI NUMARUL DE MAGAZINE DIN BAZAR: ");
  scanf("%d",&n);
  MAGAZIN v[n];
  for(int i=0;i<n;i++)
    {
      printf("Tipul de magazin: ");
      scanf("%d",&tip_mag);
      v[i].tip_mag=tip_mag;
      printf("Numele magazinului: ");
      scanf("%19s",v[i].nume);
      printf("Numarul de magazine de acest tip:");
      scanf("%d",&nr_mag);
      v[i].nr_mag=nr_mag;
      printf("Aria magazinului(in m^2): ");
      scanf("%f",&v[i].metrii);

      switch(v[i].tip_mag)
	{
	case 1:
	  {
	    printf("E MAGAZIN DE CEAIURI\nIntrodu tara din care sunt aduse ceaiurile: ");
	    scanf("%14s",v[i].caracteristici.tara);
	    break;
	  }
	case 2:
	  {
	    printf("E MAGAZIN DE IMBRACAMINTE\nIntrodu tipul de haine: ");
	    scanf("%d",&tip_haine);
	    v[i].caracteristici.tip_haine=tip_haine;
	    break;
	  }
	case 3:
	  {
	    printf("E MAGAZIN DE PODOABE\nIntrodu numarul de karate: ");
	    scanf("%d",&karate);
	    v[i].caracteristici.karate=karate;
	    break;
	  }
	case 4:
	  {
	    printf("E MAGAZIN DE SUVENIRURI\nIntrodu pretul celui mai scump prod: ");
	    scanf("%d",&v[i].caracteristici.pretscump);
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
	    printf("%s - %d - %d - %.2f - %s\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.tara);
	    break;
	  }
	case 2:
	  {
	    switch(p->elem.caracteristici.tip_haine)
	      {
	      case 0:
		{
		  printf("%s - %d - %d - %.2f - haine de barbati\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      case 1:
		{
		  printf("%s - %d - %d - %.2f - haine de femei\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      case 2:
		{
		  printf("%s - %d - %d - %.2f - haine de copii\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii);
		  break;
		}
	      }
	    break;
	  }
	case 3:
	  {
	    printf("%s - %d - %d - %.2f - %d\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.karate);
	    break;
	  }
	case 4:
	  {
	    printf("%s - %d - %d - %.2f - %d\n",p->elem.nume,p->elem.tip_mag,p->elem.nr_mag,p->elem.metrii,p->elem.caracteristici.pretscump);
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

  
