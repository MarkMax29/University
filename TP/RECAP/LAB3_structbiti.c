#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
/*Aplicația 4.1: Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
pe ecran.

Aplicația 4.2: Cu ajutorul structurii de la problema mai sus să se salveze într-un vector de structuri declarat static
informații despre mai multe fișiere (maxim 10). Să se citească de la tastatură informațiile despre fișiere și să se
salveze în fișierul memorie.txt.

Aplicația 4.3: Modificați problema de mai sus astfel încât vectorul de structuri să fie alocat dinamic.



typedef struct {
  unsigned int dim:11; 
  unsigned int tip_fis:2;
  unsigned int tip:1;
  char nume[16];
}FISIER;
void prob()
{
  int tip1,tip2,dimensiune,i=0,curent_size=0;
  char nume[16];
  FISIER *v=NULL;
  while(scanf("%15s %d %d %d",nume,&tip1,&tip2,&dimensiune)==4)
    {
      
      if(curent_size==i)
	{
	  curent_size=curent_size+MAX;
	  
	  v=(FISIER*)realloc(v,curent_size*sizeof(FISIER));
	  if(v==NULL)
	    {
	      printf("eroare la alocare");
	      exit(-1);
	    }
	 
	}
      strcpy(v[i].nume,nume);
      v[i].tip_fis=tip1;
      v[i].tip=tip2;
      v[i].dim=dimensiune;
      i++;
    }
  FILE *f=NULL;
  f=fopen("memorie.txt","w");
  if(f==NULL)
    {
      printf("nu s-a scris in fisier");
      exit(-1);
    }
  for(int j=0;j<i;j++)
    {
      fprintf(f,"%s - %d -",v[j].nume,v[j].dim);//afisez nume si dimensiune
      
      if(v[j].tip_fis==0) // afisez tipul fisierului 0,1,2 txt/doc/xls
	fprintf(f,".txt-");
      else
	if(v[j].tip_fis==1)
	  fprintf(f,".doc-");
	else
	  fprintf(f,".xls-");

      if(v[j].tip==0)  //afisez tipul 0,1 normal/read-only
	fprintf(f,"normal\n");
      else
	fprintf(f,"read-only\n");
      
	 
    }
  fclose(f);
  free(v);
  
 
}
*/

/*Subiectul 1: Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim
*/

typedef struct {
  unsigned int cod:14;
  unsigned int an:11;
  unsigned int cai:9;
  unsigned int nr_loc:4;
  char culoare[15];
  char marca[15];
}AUTO;

int comp(const void *elem1,const void *elem2)
{
  const AUTO *e1=(const AUTO*)elem1;
  const AUTO *e2=(const AUTO*)elem2;
  if(e1->an>e2->an)
    return 1;
  else if(e1->an<e2->an)
    return -1;
  return 0;
}
void introducere(AUTO *v,int *size)
{
  char marca[15],culoare[15];
  int cod,nr_loc,cai,an;
  int i=*size;
  *size=*size+1;
  scanf("%14s %14s %d %d %d %d",marca,culoare,&cod,&nr_loc,&cai,&an);
  strcpy(v[i].marca, marca);
  strcpy(v[i].culoare, culoare);
  v[i].cod=cod;
  v[i].nr_loc=nr_loc;
  v[i].cai=cai;
  v[i].an=an;
}
void stergere(AUTO *v,int *size)
{
  int cod;
  scanf("%d",&cod);
  for(int i=0;i<*size;i++)
    {
      if(v[i].cod==cod)
	{
	  for(int j=i;j<*(size)-1;j++)
	    v[j]=v[j+1];
	  *size=*size-1;
	}
    }
	
}
void afisare(AUTO *v,int *size)
{
  for(int i=0;i<*size;i++)
    printf("%14s %14s %d %d %d %d\n",v[i].marca,v[i].culoare,v[i].cod,v[i].nr_loc,v[i].cai,v[i].an);
       
}
void afisare_loc(AUTO *v,int *size)
{
  int nr_loc;
  scanf("%d",&nr_loc);
  for(int i=0;i<*size;i++)
    if(v[i].nr_loc==nr_loc)
      printf("%14s %14s %d %d %d %d\n",v[i].marca,v[i].culoare,v[i].cod,v[i].nr_loc,v[i].cai,v[i].an);
       
}	      
void afisare_binar(AUTO *v,int size)
{
  FILE *f=NULL;
  f=fopen("file.bin","wb");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<size;i++)
    fwrite(&v[i],sizeof(AUTO),1,f);

  fclose(f);
  

}
void pb1()
{
  int n;
  scanf("%d",&n);
  char marca[15],culoare[15];
  int cod,nr_loc,cai,an;
  AUTO v[100];
  for(int i=0;i<n;i++) 
    {
      scanf("%15s %15s %d %d %d %d",marca,culoare,&cod,&nr_loc,&cai,&an);
      strcpy(v[i].marca,marca);
      strcpy(v[i].culoare,culoare);
      v[i].cod=cod;
      v[i].nr_loc=nr_loc;
      v[i].cai=cai;
      v[i].an=an;
    }
  qsort(v,n,sizeof(AUTO),comp);
  //afisare(v,&n);
  afisare_binar(v,n);
  /*introducere(v,&n);
  afisare(v,&n);
  stergere(v,&n);
  afisare(v,&n);
  afisare_loc(v,&n);*/
}



int main()
{
  //prob();
  pb1();


  return 0;
}
  
