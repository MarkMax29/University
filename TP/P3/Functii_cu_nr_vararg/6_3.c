/*Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y);
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
void absN(int n,...)
{
  va_list va;
  va_start(va,n);
  double *arg=NULL;
  for(int i=0;i<n;i++)
    {
      arg=va_arg(va,double *);
      *arg=fabs(*arg);
    }
  va_end(va);

}
int main()
{
  double x=-2.5,y=-8.4;
  absN(2,&x,&y);
  printf("%.1f %.1f",x,y);
  
  return 0;
}
 
