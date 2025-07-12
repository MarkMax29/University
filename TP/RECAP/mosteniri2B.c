#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int valid(int n,int k)
{
  if(k+1>n)
    return 0;
  return 1;
     
}

int solutie(int v[],int n,int k)
{
  if(k+1!=n)//k porneste de la 2 de aia e k+1
    return 0;
  int i,x,y;
  for(i=0;i<k;i++)
    {
      x=v[i];
      y=v[i+1];
      int s1=0,s2=0;
      while(x!=0)
	{
	  s1=s1+x%10;
	  x=x/10;
	}
      while(y!=0)
	{
	  s2=s2+y%10;
	  y=y/10;
	}
      if(s1+s2!=10)
	return 0;
    }
  return 1;
}

void afisare(FILE *f,int v[],int n)
{
  for(int i=0;i<n;i++)
    fprintf(f,"%d ",v[i]);
  fprintf(f,"\n");
}
void back(int v[],int n,int k,int a,int b,FILE *f)
{

  for(int i=a;i<b;i++)
    {
      v[k]=i;
      if(valid(n,k))
	{
	  if(solutie(v,n,k))
	    afisare(f,v,n);
	  else
	    back(v,n,k+1,a,b,f);
	}
    }
}

int main(int argc,char **argv)
{
  clock_t t;
  double cpu_time_used;
  t=clock();
  
  FILE *f=NULL;
  f=fopen("fisier.txt","w");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  if(argc!=4)
    return 0;
  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  int n=atoi(argv[3]);
  int v[n];

  back(v,n,0,a,b,f);
  fclose(f);

  t=clock()-t;
  cpu_time_used=((double)t)/CLOCKS_PER_SEC;
  printf("timpul de executie: %lf",cpu_time_used);
  return 0;
}
  
