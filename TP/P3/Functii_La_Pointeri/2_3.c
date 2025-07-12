/*Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
și bsearch.*/

#include<stdio.h>
#include<stdlib.h>

int compar(const void *elem1,const void *elem2)
{
  const float *e1=(const float *) elem1;
  const float *e2=(const float *) elem2;
  if(*e1>*e2)
    return 1;
  else if(*e1<*e2)
    return -1;
  return 0;
}

void prb()
{
  int n;
  float *v=NULL,x;
  printf("Introdu n:");scanf("%d",&n);
  v=malloc(n*sizeof(float));
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  printf("Introdu elementele din vector: ");
  for(int i=0;i<n;i++)
    scanf("%f",&v[i]);
  qsort(v,n,sizeof(float),compar);
  printf("Vectorul sortat: ");
  for(int i=0;i<n;i++)
    printf("%.2f ",v[i]);
  printf("\n");
      
  printf("Introdu x: ");
  scanf("%f",&x);
  if(bsearch(&x,v,n,sizeof(float),compar)!=NULL)
    printf("S-a gasit x=%.2f in vector\n",x);
  else
    printf("Nu s-a gasit x=%.2f in vector\n",x);

  free(v);
  
}
int main()
{
  prb();
  return 0;
}
