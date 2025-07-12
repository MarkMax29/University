#include<stdio.h>
#include<stdlib.h>

int valid(int v[],int k,int suma,int cnt[])
{
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  int s=0;
  for(int i=0;i<=k;i++)
    s=s+(v[i]*cnt[i]);
  if(s<=suma)
    return 1;
  return 0;
}

int solutie(int k,int suma,int v[],int cnt[],int n)
{
  int s=0;
  if(k==n)
    return 0;
  for(int i=0;i<=k;i++)
    s=s+(v[i]*cnt[i]);
  if(s==suma)
    return 1;
  return 0;
}
void afisare(int k,int cnt[],int v[])
{
  FILE *out=fopen("text.out","a");
  if(out==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<=k;i++)
    {
      if(cnt[i]>0)
	fprintf("%d * %d",cnt[i],v[i]);
    }
  fprintf(out,"\n");
  fclose(out);
}

void back(int k,int v[],int n,int suma,int bani[],int cnt[])
{
  for(int i=0;i<n;i++)
    {
      v[k]=bani[i];
      for(int j=1;;j++)
	{
	  cnt[k]=j;
	  if(valid(v,k,suma,cnt))
	    {
	      if(solutie(k,suma,v,cnt,n))
		  afisare(sol,k,cnt);
	      else
		back(k+1,v,n,suma,bani,cnt);
	    }
	  else
	    break;
	}
      cnt[k]=0;
    }
  
}

void ex1()
{
  FILE *f=fopen("in.txt","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  int n;
  fscanf(f,"%d",&n);
  int bani[n];
  for(int i=0;i<n;i++)
    fscanf(f,"%d",bani[i]);
  int suma;
  fscanf(f,"%d",&suma);
  int v[100],cnt[100];
  for(int i=0;i<100;i++)
    cnt[i]=0;
  back(0,v,n,suma,bani,cnt);
  fclose(f);
}

int main()
{

  ex1();
  return 0;
}
