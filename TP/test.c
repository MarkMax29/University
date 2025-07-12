#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#define MAX 100
typedef struct
{
  char nume[36];
  uint16_t an:11;
  uint8_t premii:1;
}FILME;

int comp(const void *e1, const void *e2)
{
  FILME *elem1= (FILME*) e1;
  FILME *elem2= (FILME*)e2;
  if(elem1->premii==0 && elem2->premii==1)
    return 1;
  else
    return 0;
}
void prob1()
{
  FILME *v;
  uint64_t n;
  uint16_t auxan;
  uint8_t auxprem;
  char aux[36];
  printf("Introduceti numarul de filme:");
  scanf("%ld",&n);
  if((v=malloc(n*sizeof(FILME)))==NULL)
    {
      printf("eroare la alocare");
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      scanf("%36s %hd %hhd",aux,&auxan,&auxprem);
      strcpy(v[i].nume,aux);
      v[i].an=auxan;
      v[i].premii=auxprem;
    }
  int (*p)(const void*,const void*);
  p=&comp;
  qsort(v,n,sizeof(FILME),p);
  for(int i=0;i<n;i++)
    {
      printf("%s-%d-%d\n",v[i].nume,v[i].an,v[i].premii);
    }
  free(v);
}
int prob2(int m[MAX][MAX],int n,int m2,int v[MAX],int lg_vector)
{
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m2-lg_vector;j++)
	{
	  int ok=1;
	  for(int k=0;k<lg_vector;k++)//parcurge vectrul
	    {
	      if(m[i][j+k]!=v[k])
		{ok=0;
		  break;
		}
	    }
	  if(ok==1)
	    return 1;
	}
    }
  for(int i=0;i<n;i++)
    {
      for(int j=m2-1;j>=lg_vector-1;j--)
	{
	  int ok=1;
	  for(int k=0;j<lg_vector;k++)
	    {
	      if(m[i][j-k]!=v[k])
		{
		  ok=0;
		  break;
		}
	    }
	  if(ok==1)
	    return 1;
	}
    }
  return 0;
	 
}

int main()
{
  //prob1();
  int n,m[MAX][MAX],m1,v[MAX];
  printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    printf("Introduceti matricea patratica n x n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    printf("Introduceti lungimea vectorului: ");
    scanf("%d", &m1);
    
    printf("Introduceti vectorul:\n");
    for (int i = 0; i < m1; i++) {
        scanf("%d", &v[i]);
    }
    if(prob2(m,n,n,v,m1)==1)
	printf("apare");
    else
      printf("nu apare");
  return 0;
}
