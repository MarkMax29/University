#include<stdio.h>
#include<stdlib.h>
/*
//1.Fie n un număr natural nenul. Să se genereze permutările de n elemente.
int valid(int k,int v[])
{
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  return 1;
}
int solutie(int k,int n)
{
  if(k==n-1)
    return 1;
  return 0;
}
void afisare(int n,int v[])
{
  for(int i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}
void back(int k,int n,int v[])
{
  int i;
  for(i=0;i<n;i++)
    {
      v[k]=i;
      if(valid(k,v))
	{
	  if(solutie(k,n))
	    afisare(n,v);
	  else
	    back(k+1,n,v);
	}
    }
}

int main()
{
  int n;
  scanf("%d",&n);
  int v[n];
  back(0,n,v);

  return 0;
}
*/

//2.Fie n şi m două numere naturale nenule, m <= n. Să se genereze aranjamentele de n elemente luate câte m

int valid(int k,int v[])
{
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  return 1;

}

int solutie(int m,int k)
{
  if(k==m-1)
    return 1;
  return 0;
}
void afisare(int m,int v[])
{
  for(int i=0;i<m;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}
void back(int n,int m,int k,int v[])
{
  int i;
  for(i=1;i<=n;i++)
    {
      v[k]=i;
      if(valid(k,v))
	{
	  if(solutie(m,k))
	    afisare(m,v);
	  else
	    back(n,m,k+1,v);
	}
    }

}
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  int v[m];
  back(n,m,0,v);
  return 0;
}
