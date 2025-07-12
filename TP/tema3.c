#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void spirala()
{
  int a[MAX][MAX],v[MAX],n=0,k=0;
  scanf("%d",&n);
  for(int i=0;i<n*n;i++)
    scanf("%d",&v[i]);
  for(int i=0;i<n;i++)
    {
      for(int j=i;j<n-i;j++)
	a[j][i]=v[k++];
      for(int j=i+1;j<n-i;j++)
	a[n-1-i][j]=v[k++];
      for(int j=n-i-2;j>i;j--)
	a[j][n-1-i]=v[k++];
      for(int j=n-1-i;j>i;j--)
	a[i][j]=v[k++];
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%d ",a[i][j]);
	}
      printf("\n");
    }
}
           
int main()
{
  spirala(); 

  return 0;
}
  
