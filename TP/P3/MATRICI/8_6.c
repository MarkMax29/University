/*Aplicația 8.6: Se citește un număr n<=10 de persoane, fiecare persoană fiind identificată printr-un număr între
0..n-1. O persoană poate fi prietenă cu oricare alte persoane. După ce s-a citit n, se vor citi pentru fiecare persoană
prietenii ei pe rând. Să se afișeze pentru fiecare persoană câți prieteni are.*/

#include<stdio.h>
#include<stdlib.h>
void pb()
{

  int n;
  printf("n=");scanf("%d",&n);
  if(n>10)
    exit(-1);
  int a[n][n];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  for(int i=1;i<=n;i++)
    {
      int cnt=0;
      for(int j=1;j<=n;j++)
	{
	  if(a[i][j]==1)
	    cnt++;
	}
      printf("Persoana %d are: %d prieteni\n",i,cnt);
    }
	  
}
int main()
{
  pb();

  return 0;
}
