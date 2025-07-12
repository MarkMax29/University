#include<stdio.h>
#include<stdint.h>
#define MAX 100
void citire(int *v,int *size)
{
  int value;
  for(int i=0;i<*size;i++)
    {
      scanf("%d",&value);
      *(v+i)=value;
    }
}
void afisare(int *v,int size)
{
  int value;
  for(int i=0;i<size;i++)
    {
      value=*(v+i);
      printf("%d ",value);
    }
}
  

void ex1(int *a,int*b)
{
  int *p=NULL;
  if(*a>*b)
    p=a;
  else
    p=b;
  printf("%d",*p);

}

void ex2_egal(int *v1,int *v2,int size)
{
  int ok=1;
  for(int i=0;i<size && ok==1;i++)
    {
      if(*(v1+i)!=*(v2+i))
	ok=0;
    }
  if(ok==1)
    printf("Toate sunt egale");
  else
    printf("Nu toate sunt egale");
}
void ex4_interschimbare(int *a,int *b)
{
  int aux=*a;
  *a=*b;
  *b=aux;
  printf("%d %d",*a, *b);
}
void ex5si6_nrneg(int *v,int size)
{
  int nr=0,mini=9999999;
  for(int i=0;i<size;i++)
    {
      if(*(v+i)<0)
	nr++;
      if(mini>*(v+i))
	mini=*(v+i);
    }
  printf("%d\n",nr);
  printf("%d\n",mini);
  
}
void ex7_sortare(int *v,int size)
{
  citire(v,&size);
  int aux;
  for(int i=0;i<size;i++)
    {
      if(*(v+i)<*(v+i+1))
	{
	  aux=*(v+i);
	  *(v+i)=*(v+i+1);
	  *(v+i+1)=aux;
        }
    }
  printf("Vectorul sortat este: ");
  afisare(v,size);
  printf("\n");
  
}
void ex8_stergere(int*v,int size)
{
  citire(v,&size);
  for(int i=0;i<size;i++)
    {
      if(*(v+i)%2==0)
	{
	  for(int j=i+1;j<size;j++)
	    {
	      *(v+j-1)=*(v+j);
	      
	    }
	  size--;
	  i--;
	}
    }
  printf("Vectorul sters: ");
  afisare(v,size);
  printf("\n");
}
void ex9_inserare(int *v,int size)
{
  citire(v,&size);
  for(int i=size-1;i>=0;i--)
     {
       size++;
       for(int j=size-2;j>=i;j--)
	 {
	   *(v+j+1)= *(v+j);
	 }
       *(v+i)=-(*(v+i));
     }
  printf("Vectorul inserat: ");
  afisare(v,size);
  printf("\n");
}


int main(void)
{
  //  int a,b;
  int tab1[MAX],n;
  // double nr1,nr2;
  /*
  //ex1
  printf("Introdu a: ");
  scanf("%d",&a);
  printf("Introdu b: ");
  scanf("%d",&b);
  printf("Cel mai mare este: ");
  ex1(&a,&b);
  printf("\n");

  //ex2
  scanf("%d",&n);
  citire(tab1,&n);
  citire(tab2,&n);
  ex2_egal(tab1,tab2,n);
  

  //ex3
  printf("Introduceti nr1: ");
  scanf("%lf",&nr1);
  printf("Introduceti nr2: ");
  scanf("%lf",&nr2);
  if(nr1>nr2)
    printf("nr2");
  else
    printf("nr1");

  //ex4
  printf("\nIntroduceti a: ");
  scanf("%d",&a);
  printf("Introduceti b: ");
  scanf("%d",&b);
  ex4_interschimbare(&a,&b);

  //ex5 si ex6
  printf("\nIntrodu nr de elemente: ");
  scanf("%d",&n);
  printf("Vectorul: ");
  citire(tab1,&n);
  ex5si6_nrneg(tab1,n);
  
  //ex 7
   printf("Introdu nr de elemente: ");
   scanf("%d",&n);
   printf("Elementele vectorului: ");
   ex7_sortare(tab1,n);
  
   //ex 8
   printf("Introdu nr de elemente: ");
   scanf("%d",&n);
   printf("Elementele vectorului: ");
   ex8_stergere(tab1,n);
  */
  //ex 9
   printf("Introdu nr de elemente: ");
   scanf("%d",&n);
   printf("Elementele vectorului: ");
   ex9_inserare(tab1,n);
   
   
   
  return 0;
}
