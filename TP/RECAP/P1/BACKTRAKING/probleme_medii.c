#include <stdio.h>
#include <stdlib.h>

/*1. Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din n cifre care contin exact k cifre de 1.*/
/*
int valid(int v[], int k) {
    if (k == 0 && v[k] == 0) {
        return 0; // Prima cifră nu poate fi zero.
    }
    return 1;
}

int solutie(int v[], int c, int k, int n) {
    int unu = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            unu++;
        }
    }
    return (unu == c);
}

void afisare(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
    }
    printf("\n");
}

void back(int v[], int k, int c, int n) {
    if (k == n) {
        if (solutie(v, c, k, n)) {
            afisare(v, n);
        }
        return;
    }

    for (int i = 0; i <= 9; i++) {
        v[k] = i;
        if (valid(v, k)) {
            back(v, k + 1, c, n);
        }
    }
}

int main() {
    int n, c;
    printf("Introduceti n si k: ");
    scanf("%d %d", &n, &c);

    if (c > n) {
        printf("Nu este posibil să ai mai multe cifre de 1 decât numărul total de cifre.\n");
        return -1;
    }

    int v[n];
    back(v, 0, c, n);

    return 0;
}
*/

/*2.Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare*/
/*
int valid (int k,int v[])
{
  int i;
  for(i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  return 1;
}
int solutie(int k,int v[],int n)
{
  if(k!=n-1)
    return 0;
  int mij=n/2;
  for(int i=0;i<mij;i++)
    for(int j=i+1;j<=mij;j++)
      if(v[i]>v[j])
	return 0;
  for(int i=mij;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(v[i]<v[j])
	return 0;
  return 1;
}
void afis(int n,int v[])
{
  for(int i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}
void back(int k,int v[],int n)
{
  int i;
  for(i=1;i<=n;i++)
    {
      v[k]=i;
      if(valid(k,v))
	{
	  if(solutie(k,v,n))
	    {
	      afis(n,v);
	    }
	  else
	    back(k+1,v,n);
	}
    }
}
  
  

int main()
{
  int n;
  scanf("%d",&n);
  int v[n];
  back(0,v,n);

  return 0;
}
*/

/*3.Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru. Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii: - orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc. - culorile din fiecare steag trebuie sa fie distincte
//alb-0, galben-1, rosu-2, verde-3, albastru-4, negru-5
//sol[1]=3 || sol[1]=1, permutari de culori
*/
/*
int valid(int v[],int k)
{
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  return 1;
}

int solutie(int v[],int k)
{
  if(k!=2)
    return 0;
  if(v[1]==1 || v[1]==3)
    return 1;
  else
    return 0;

}
void afisare(int v[])
{
  for(int i=0;i<3;i++)
    printf("%d ",v[i]);
  printf("\n");
}
void back(int v[],int k)
{
  int i;
  for(i=0;i<6;i++)
    {
      v[k]=i;
      if(valid(v,k))
	{
	  if(solutie(v,k))
	    afisare(v);
	  else
	    back(v,k+1);
	}
    }
}

int main()
{
  int v[10];
  back(v,0);
  return 0;
}
 

      


//5.De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini,ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini și ateliere. Să se determine toate variantele în care acestea pot fi aranjate

//{casa-0, bloc-1, gradina-2, atelier-3}
//COND 1: se poate 00 11 22 33
//COND 2: 01 sau 10 + 02 sau 20 + 32 sau 23
*/

int valid(int v[],int k)
{
  if(k==0)
    return 1;
  switch(v[k])
    {
    case 0:
      {
	if(v[k-1]==0 || v[k-1]==1 || v[k-1]==2)//daca vecinu e casa/bloc sau gradina
	  {  return 1;
	    break;
	  }
      }
    case 1:
      {
	if(v[k-1]==1 || v[k-1]==0)
	  {
	    return 1;
	    break;
	  }
      }
    case 2:
      {
	if(v[k-1]==2 || v[k-1]==0 || v[k-1]==3)
	  {
	    return 1;
	    break;
	  }
      }
    case 3:
      {
	if(v[k-1]==3 || v[k-1]==2)
	  {
	    return 1;
	    break;
	  }
      }
    }
  return 0;
}
void afisare(int total,int v[])
{
  for(int i=0;i<total;i++)
    {
      switch(v[i])
	{
	case 0:
	  {
	    printf("casa ");
	    break;
	  }
	case 1:
	  {
	    printf("bloc ");
	    break;
	  }
	case 2:
	  {
	    printf("gradina ");
	    break;
	  }
	case 3:
	  {
	    printf("atelier ");
	    break;
	  }
	}
    }
  printf("\n");
}
void back(int k,int v[],int total,int c,int b,int g,int a,int curent_c,int curent_b,int curent_g,int curent_a)
{
  if(curent_c>c ||curent_b>b||curent_g>g||curent_a>a)
    return;
  if(k==total)
    {
      if(curent_c==c && curent_g==g && curent_b==b && curent_a==a)
	afisare(total,v);
      return;
    }
  for(int i=0;i<4;i++)
    {
      v[k]=i;
      if(valid(v,k))
	{
	  int cnou=curent_c+(i==0);
	  int bnou=curent_b+(i==1);
	  int gnou=curent_g+(i==2);
	  int anou=curent_a+(i==3);
	  back(k+1,v,total,c,b,g,a,cnou,bnou,gnou,anou);
	}
    }    
}

int main()
{
  int total,c,b,a,g;
  scanf("%d %d %d %d",&c,&b,&g,&a);
    total=c+b+g+a;
  int v[total];
  back(0,v,total,c,b,g,a,0,0,0,0);
  
  return 0;
       
}
