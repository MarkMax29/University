/*Subiectul 2: Să se realizeze o aplicaţie pentru gestionarea unei biblioteci folosind struct și union, iar dacă e
posibil și structuri cu câmpuri pe biți.
Se vor memora următoarele informaţii pentru fiecare înregistrare:
 Titlu
 Autor
 Număr de exemplare
 Preț (exprimat în lei, număr întreg, maxim 500 lei)
 Număr de pagini (maxim 1000 pagini)
 Greutate (exprimată în grame, maxim 5000 grame)
 Dacă e Carte sau Revistă
 Dacă e carte se va memora ISBN, sir de 13 caractere, exemplu: 9783161484100, iar dacă e revistă se va
memora anul în care a apărut primul număr.
Folosind un meniu să se realizeze următoarele operaţii:
a) Introduceţi un produs.
b) Afişaţi toate publicaţiile aflate în stoc care sunt cărţi si au preţul peste 100.
c) Afişaţi toate înregistrările.
d) Salvaţi toate publicatiile - Toate produsele se vor salva într-un fişier binar (inventar.bin) folosind structura
creată anterior.
Datele de intrare se vor citi de la tastatură
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef union CARACTERISTICI{
  char sir[13];
  unsigned int primul_nr:11;
}CARACTERISTICI;
typedef struct BIBLIO{
  char titlu[26];
  char autor[20];
  int nr_exemplare;
  unsigned int pret:9;
  unsigned int nr_pag:10;
  unsigned int grame:13;
  unsigned int car_rev:1;//daca e carte sau revista
  CARACTERISTICI caract;

}BIBLIO;
void introducere(int *size,BIBLIO **v)
{
  unsigned int pret,nr_pag,grame,car_rev,primul_nr;
  *v=realloc(*v,(*size+1)*sizeof(BIBLIO));
  if(*v==NULL)
    {
      perror(NULL);
      // free(*v);
      exit(-1);
    }
  printf("Introduceti o data noua: \n");
  printf("Titlu: ");scanf("%25s", (*v)[*size].titlu);
  printf("Autor: "); scanf("%20s", (*v)[*size].autor);
  printf("Nr exemplare: ");scanf("%d",&(*v)[*size].nr_exemplare);
  printf("Pret: ");scanf("%d",&pret);
  printf("Nr. pagini: ");scanf("%d",&nr_pag);
  printf("Grame: ");scanf("%d",&grame);
  printf("Ce e (carte:0 sau revista:1): ");scanf("%d",&car_rev);
  (*v)[*size].pret = pret;
  (*v)[*size].nr_pag = nr_pag;
  (*v)[*size].grame = grame;
  (*v)[*size].car_rev = car_rev;
  
  switch((*v)[*size].car_rev)
    {
    case 0:
      {
	printf("E CARTE: ");scanf("%13s",(*v)[*size].caract.sir);
	break;
      }
    case 1:
      {
	printf("E REVISTA: ");scanf("%d",&primul_nr);
	(*v)[*size].caract.primul_nr=primul_nr;
	break;
      }
    }
 
  *size=*size+1;
	
}
	
void carti_peste_100(int *size,BIBLIO *v)
{
  for(int i=0;i<*size;i++)
    {
      if(v[i].nr_exemplare>0 && v[i].car_rev==0 && v[i].pret>=100)
	printf("Titlu: %s - Autor: %s - Numar Exemplare: %d - Pret: %d - Nr pagini: %d - Grame: %d - E CARTE - Cod ISBN: %s\n",v[i].titlu,v[i].autor,v[i].nr_exemplare,v[i].pret,v[i].nr_pag,v[i].grame,v[i].caract.sir);
    }  

}
void afisare_tot(int *size,BIBLIO *v)
{
  for(int i=0;i<*size;i++)
    {

      if(v[i].car_rev==0) 
	printf("Titlu: %s - Autor: %s - Numar Exemplare: %d - Pret: %d - Nr pagini: %d - Grame: %d - E CARTE - Cod ISBN: %s\n",v[i].titlu,v[i].autor,v[i].nr_exemplare,v[i].pret,v[i].nr_pag,v[i].grame,v[i].caract.sir);
      else
	printf("Titlu: %s - Autor: %s - Numar Exemplare: %d - Pret: %d - Nr pagini: %d - Grame: %d - E REVISTA - Anul in care o aparut primul numar: %d\n",v[i].titlu,v[i].autor,v[i].nr_exemplare,v[i].pret,v[i].nr_pag,v[i].grame,v[i].caract.primul_nr);
	
    }  

}
void salvare_binar(int *size,BIBLIO *v)
{
  FILE *f=NULL;
  if((f=fopen("inventar.bin","wb"))==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<*size;i++)
    {
      fwrite(&v[i],1,sizeof(BIBLIO),f);
    }
  printf("S-A SALVAT IN FISIER !");
  fclose(f);

}
void eliberare(BIBLIO *v)
{
  free(v);
}
int main()
{
  int actiune,n=0;
  BIBLIO *v=NULL;
  while(1)
    { printf("\nMENIU: \n\n\n");
      printf("1.Introducere produs - APASA 1 \n");
      printf("2.Afişaţi toate publicaţiile aflate în stoc care sunt cărţi si au preţul peste 100 - APASA 2 \n");
      printf("3.Afişaţi toate înregistrările - APASA 3 \n");
      printf("4.Salvaţi toate publicatiile - Toate produsele se vor salva într-un fişier binar (inventar.bin) - APASA 4 \n");
      printf("5.EXIT - APASA 5 sau altcv\n");
      printf("6.ELIBERARE MEMORIE - APASA 6\n\n");
      printf("Introduceti actiunea dorita: ");scanf("%d",&actiune);
      switch(actiune)
	{
	case 1:
	  {
	    introducere(&n,&v);
	    break;
	  }
	case 2:
	  {
	    carti_peste_100(&n,v);
	    break;
	  }
	case 3:
	  {
	    printf("Toate inregistrarile:\n");
	    afisare_tot(&n,v);
	    break;
	  }
	case 4:
	  {
	    salvare_binar(&n,v);
	    break;
	  }
	  case 5: {
	    // exit(-1); // Eliberăm memoria alocată înainte de ieșire
	    return 0;
	  }
	case 6:
	  {
	    eliberare(v);
	    break;
	  }
	          
	}
    }
  return 0;
}
