#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
și bsearch.*/
/*
int compar(const void *elem1,const void *elem2)
{
  const float *e1=(const float*)elem1;
  const float *e2=(const float*)elem2;
  if(*e1>*e2)
    return 1;
  if(*e1<*e2)
    return -1;
  return 0;

}
void pb2_3()
{
  int n;
  float x;
  scanf("%d",&n);
  scanf("%f",&x);
  float v[n];
  for(int i=0;i<n;i++)
    scanf("%f",&v[i]);
  qsort(v,n,sizeof(float),compar);
  for(int i=0;i<n;i++)
    printf("%.2f ",v[i]);
  printf("\n");
  if(bsearch(&x,v,n,sizeof(float),compar)!=NULL)
    printf("SA GASIT x IN VECTORUL SORTAT");
  else
    printf("NU SA GASIT x IN VECTORUL SORTAT");
  
}
*/
/*Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
negativ și să se afișeze vectorul rezultat*/
/*
int negativ(int n)
{
  if(n<0)
    return 1;
  return 0;
}
void pb2_2(int *v,int *size, int(*negativ)(int))
{
  for(int i=0;i<*size;i++)
    {
      if(negativ(v[i]))
	{
	  for(int j=i;j<*(size)-1;j++)
	    {
	      v[j]=v[j+1];
	    }
	  *size=*(size)-1;
	  i--;
	}
    }
  for(int i=0;i<*size;i++)
    printf("%d ",v[i]);
  printf("\n");

}
*/


/*Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca
argument. Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double. Funcția
de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat, n - un număr
întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de
tabelat. Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs
din math.h

*/
/*
double f(double x)
{

  return fabs(x);
}
void tabelare(int a,int b,int n,double(*f)(double))
{
  double pas=(b-a)/n;
  while(a<=b)
    {
      printf("f(%d)=%0.lf\n",a,f(a));
      a=a+pas;
    }
}

void pb2_4()
{
  int a,b,n;
  scanf("%d %d %d",&a,&b,&n);
  tabelare(a,b,n,f);
}
*/


/*Subiectul 2.1 Să se scrie un program pentru tabelarea unor funcţii matematice. Programul trebuie să tabeleze
funcţiile (x*x*x+4)/(x*x+5), x+10 şi 2*x*x-1.
Tabelarea se va realiza pe intervalul [A,B] cu pasul P. Valorile A, B şi P se vor citi de la tastatură. Programul va
afişa valorile funcţiilor sub formă de tabel.
Trebuie să se folosească pointeri la funcţii. Scrieţi o funcţie generică pentru tabelarea unei funcţii matematice
oarecare. Această funcţie generică va avea un parametru de tip pointer la funcţie.
Folosind funcţia generică, tabelaţi cele patru funcţii matematice amintite mai sus.

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

void tabelare(int a,int b,int p,int (*funct)(int))
{

  while(a<=b)
    {
      printf("f(%d)=%d\n",a,funct(a));
      a=a+p;
    }
}

void pb2_1exam()
{
  int a,b,p;
  scanf("%d %d %d",&a,&b,&p);
  tabelare(a,b,p,f1);
  printf("\n");
  tabelare(a,b,p,f2);
  printf("\n");
  tabelare(a,b,p,f3);
  }
*/
/*Subiectul 2.2 Se citesc mai multe cuvinte din linia de comandă. Cu ajutorul pointerilor la funcții (un vector de
pointeri la funcții) să se apeleze într-o structură repetitivă următoarele funcții. Să se afișeze rezultatele pentru
fiecare cuvânt pe ecran și în fișierul text CUVINTE.TXT.
a) Primește parametru un șir de caractere și returneză lungimea șirului.
b) Primește parametru un șir de caractere și returneză numărul de vocale din text.
c) Primește parametru un șir de caractere și returneză numărul de litere mari din text.
Primește parametru un șir de caractere și returneză diferența codurilor ASCII ale primului caracter și al ultimului
caracter.*/

int lungime(char *sir)
{
  return strlen(sir);
}
int vocale(char *sir)
{
  int count=0;
  for(int i=0;i<strlen(sir);i++)
    if(strchr("AEIOUaeiou",sir[i]))
      count++;
  return count;
}
int litere_mari(char *sir)
{
  int count=0;
  for(int i=0;i<strlen(sir);i++)
    if(sir[i]>='A' && sir[i]<='Z')
      count++;
  return count;
}
int diferenta(char *sir)
{
  return sir[strlen(sir)-1]-sir[0];
}


int main(int argc,char **argv)
{
  //pb2_3();
  /*int n;
  scanf("%d ",&n);
  int v[n];
   for(int i=0;i<n;i++)
    scanf("%d",&v[i]);
   pb2_2(v,&n,negativ);
  */
  //pb2_4();
  //pb2_1exam();

  if(argc!=4)
    return 0;
  int i,j;
  int (*v[4])(char*);
  v[0]=lungime;
  v[1]=vocale;
  v[2]=litere_mari;
  v[3]=diferenta;
  for(i=0;i<argc;i++)
    {
      printf("pentru %s:", argv[i]);
	for(j=0;j<=3;j++)
	  printf("%d ",v[j](argv[i]));
      printf("\n");
    }
  return 0;
}
