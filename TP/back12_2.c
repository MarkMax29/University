#include<stdio.h>
#include<stdlib.h>
void afisare(int *v,int n)
{
  for(int i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}
int valid(int *v,int k)
{
  for(int i=0;i<k;i++)
    {
      if(v[k]==v[i])
	return 0;
    }
  return 1;
}

int solutie(int k,int n)
{
  if(k==n-1)
    return 1;
  return 0;
}
void back(int k,int *v,int n)
{
  for(int i=0;i<n;i++)
    {
      v[k]=i;
      if(valid(v,k))
	{
	  if(solutie(k,n))
	    afisare(v,n);
	  else
	    back(k+1,v,n);
	}
    }
}

	 
int main()
{
  int n,*v=NULL;
  scanf("%d",&n);
  v=malloc(n*sizeof(int));
  if(v==NULL)
    {printf("eroare alocare");
      exit(-1);
   
    } 
	
  back(0,v,n);
    
  

  return 0;
}

    
  
