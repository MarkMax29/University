/*Aplicația 6.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente
iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele.
Exemplu: allocVec(3,7.2,-1,0) => {7.2, -1, 0}
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
float *allocVec(int n,...)
{
  va_list va;
  va_start(va,n);
  float *v=NULL;
  v=malloc(n*sizeof(double));
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      v[i]=va_arg(va,double);
    }
  va_end(va);
  return v;
}

int main()
{
  float *v;
  v=allocVec(3,1.2,3.2,4.6);
  for(int i=0;i<3;i++)
    {
      printf("%.1f ",v[i]);
    }
  free(v);
  return 0;
}
  
