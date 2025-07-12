#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char nume[15];
    int valoare;
} Jucator;

int comparareJucatori(const void *a, const void *b)
{
    Jucator *jucator1 = (Jucator *)a;
    Jucator *jucator2 = (Jucator *)b;
    return jucator1->valoare - jucator2->valoare;
}

void p4(char *nume_fisier)
{
  JUCATOR v[1000],aux;
  FILE *f=NULL;
  if((f=fopen(nume_fisier,"r"))==NULL)
    {
      perror("desc");
      exit(-1);
    }
  int n=0,m=0;
  if(fscanf(f,"%d%d",&n,&m)!=2)
    {
      perror("eroare n m");
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      if(fscanf(f,"%15s %d",v[i].nume,&v[i].val)!=2)
	{
	  fprintf(stderr,"eroare la juc %d",i);
	  exit(-2);
	}
    }
  for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
	if(v[i].val<v[j].val)
	  {
	    aux=v[i];
	    v[i]=v[j];
	    v[j]=aux;
	  }
  for(int i=0;i<n;i++)
    {
      printf("%s %d\n",v[i].nume,v[i].val);
    }
  for(int i=0;i<m;i++)
    {
      printf("\nECHIPA %d\n\n",i+1);
      for(int j=i;j<n;j=j+3)
	printf("%s %d\n",v[j].nume,v[j].val);
    }
  if(fclose(f)!=0)
    {
      perror("inch");
      exit(-2);
    }
}
int main()
{

  p4("text.txt");


  return 0;
}
