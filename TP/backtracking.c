#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ok(int *v,int size,int n)
{
  for(int i=0;i<size-1;i++)
    { for(int j=i+1;j<size;j++)
	{	if(v[i]==v[j])
	    {
	      return 0;
	    }
	}
    }
  
  int mij=(n+1)/2;
  for(int i=1;i<mij && i<size;i++)
    {
      if(v[i-1]<v[i])
	return 0;
    }
  int i=0;
  if(n%2==0)
    i=mij+1;
  else
    i=mij;
  for(;i<size;i++)
    if(v[i-1]>v[i])
      return 0;
  return 1;

}
void afisare(int *v,int n)
{
  for(int i=0;i<n;i++)
    {printf("%d ",v[i]);
    }
      printf("\n");
}

int solutie(int k,int n)
{
  if(k+1==n)
    return 1;
  return 0;
 

}
void back(int k,int n, int *v)
{
  for(int i=1;i<=n;i++)
    {
      v[k]=i;
      if(ok(v,k+1,n))
	{
	  if(solutie(k,n))
	    afisare(v,n);
	  else
	    back(k+1,n,v);
	}
    }
}
int main()
{

  int *v=NULL,n;
  scanf("%d",&n);
  v=malloc(n*sizeof(int));
  if(v==NULL)
    {
      printf("eroare la alocare");
      exit(-1);
    }
  back(0,n,v);//k=poz de la care pornesc 
  free(v);
  

  return 0;
}

  

  
