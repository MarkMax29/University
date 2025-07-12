/* Să se scrie un program pentru tabelarea unor funcţii matematice. Programul trebuie să tabeleze
funcţiile (x*x*x+4)/(x*x+5), x+10 şi 2*x*x-1.
Tabelarea se va realiza pe intervalul [A,B] cu pasul P. Valorile A, B şi P se vor citi de la tastatură. Programul va
afişa valorile funcţiilor sub formă de tabel.
Trebuie să se folosească pointeri la funcţii. Scrieţi o funcţie generică pentru tabelarea unei funcţii matematice
oarecare. Această funcţie generică va avea un parametru de tip pointer la funcţie.
Folosind funcţia generică, tabelaţi cele patru funcţii matematice amintite mai sus
*/

#include<stdio.h>
#include<stdlib.h>


int f1(int x)
{
  return (x*x*x+4)/(x*x+5);
}
int f2(int x)
{
  return x+10;
}
int f3(int x)
{
  return 2*x*x-1;
}

void tabelare(int a,int b,int p,int(*func)(int))
{
  for(int i=a;i<=b;i=i+p)
    {
      printf("f(%d)=%d\n",i,func(i));
    }
  printf("\n");
}

int main()
{
  int a,b,p;
  int (*pf)(int);
  printf("Introdu a: ");scanf("%d",&a);
  printf("Introdu b: ");scanf("%d",&b);
  printf("Introdu p: ");scanf("%d",&p);

  pf=f1;
  tabelare(a,b,p,pf);
  pf=f2;
  tabelare(a,b,p,pf);
  pf=f3;
  tabelare(a,b,p,pf);
                  

  return 0;

}
