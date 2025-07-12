/*Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ELEV{
  int nota;
  char nume[15];
}ELEV;

int compar(const void *e1, const void *e2)
{

  const ELEV *elem1=(const ELEV *) e1;
  const ELEV *elem2=(const ELEV *) e2;

  if(elem1->nota<elem2->nota)
    return 1;
  else if(elem1->nota>elem2->nota)
    return -1;
  else
    {
      if(strcmp(elem1->nume,elem2->nume)==1)
	return -1;
      else
	return 1;
    }   

}

void prb()
{
  int n;
  printf("Introdu n: ");scanf("%d",&n);
  ELEV *v=NULL;
  v=malloc(n*sizeof(ELEV));
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
      scanf("%s %d",v[i].nume,&v[i].nota);
  qsort(v,n,sizeof(ELEV),compar);
  for(int i=0;i<n;i++)
    {
      printf("%s %d\n",v[i].nume,v[i].nota);
    }
  
}

int main()
{

  prb();
  return 0;
}
  
