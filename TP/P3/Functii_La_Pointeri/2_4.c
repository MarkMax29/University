/*Aplicația 2.4: Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca
argument. Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double. Funcția
de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat, n - un număr
întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de
tabelat. Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs
din math.h
Exemplu: tabelare(-10,10,20,fabs) va afișa pe câte o linie valori de forma f(-10)=10 f(-9)=9 ... f(10)=10

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double elem)
{
  double result=fabs(elem);// pt cos si sqrt apelam cu gcc -o prg ex.c -lm
  return result;      // pt fabs apelam simplu cu gcc -lm -Wall -o prg ex.c
}

void tabelare(double a,double b,int n,double(*func)(double))
{
  double x;
  x=(b-a)/n;
  for(double i=a;i<=b;i=i+x)
    {
      printf("f(%.1lf)=%.1lf\n",i,func(i));
    }
	     
}

int main()
{
  int n;
  double a,b;
  printf("Introdu a: ");scanf("%lf",&a);
  printf("Introdu b: ");scanf("%lf",&b);
  printf("Introdu n: ");scanf("%d",&n);
  tabelare(a,b,n,func);
  return 0;
}
    
