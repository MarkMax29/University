#include<stdio.h>
#include<stdlib.h>
int valid(float *v,int k,float vol)
{
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  float suma=0.0;
  for(int i=0;i<=k;i++)
    suma=suma+v[i];
  if(suma>vol)
    return 0;
  return 1;
 
}

float solutie(float *v,int k,float vol)
{
  float suma=0.0;
  for(int i=0;i<=k;i++)
    suma=suma+v[i];
  if(suma>vol)
    return 0;
  return suma;
  
}

void afisare(int k,float *v)
{
  for(int i=0;i<=k;i++)
    printf("%.2f ",v[i]);
  printf("\n");
}

void back(int k,float *cutie,int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      cutie[k]=i;
      if(valid(k))
	{
	  if(solutie(k,cutie))
	    afisare(k);
	  else
	    back(k+1,cutie,n);
	}
    }
}

void pb()
{
  int n;
  float vol,*v;
  scanf("%d &f",&n,&vol);
  for(int i=0;i<n;i++)
    scanf("%.2f",v[i]);
  back(0,v,n);
    

}

int main()
{

  pb();
}
