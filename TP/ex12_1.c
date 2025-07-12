#include<stdio.h>
int n,k,v[100],contor;
void afisare()
{
  for(int i=0;i<n;i++)
    printf("%d ",v[i]);
  printf("\n");
}
int valid(int p)
{
  if(p==0 && v[p]==0)
    return 0;
  return 1;
}
int solutie(int p)
{
  contor=0;
  for(int i=0;i<=p;i++)
    {
      if(v[i]==1)
	contor++;
    }
  if(contor==k && (p+1)==n)
    return 1;
  return 0;
  
}
void back(int p)
{
  if(p==n)
    return;
  for(int i=0;i<10;i++)
    {
      v[p]=i;
      if(valid(p))
	{
	  if(solutie(p))
	    afisare();
	  else
	    back(p+1);
	}
    }
}

int main()
{
  scanf("%d %d",&n,&k);
  back(0);
  return 0;
}
