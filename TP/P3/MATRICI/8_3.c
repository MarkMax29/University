/*Aplicația 8.3: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program care
generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor utiliza
pointeri.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m;
  printf("m=");scanf("%d",&m);
  printf("n=");scanf("%d",&n);
  int a[20][10];
  int cnt=1;
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  *(&a[0][0]+i*10+j)=cnt;
	  cnt++;
	  
	}
    }
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%3d ",*(&a[0][0]+i*10+j));
	}
      printf("\n");
    }
  
	  
  return 0;
}
