#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
void citire(int *v,int *size)
{
  int value;
  for(int i=0;i<*size;i++)
    {
      scanf("%d",&value);
      *(v+i)=value;
    }
}
void egal(int *v1,int *v2,int size)
{
  int ok=1;
  for(int i=0;i<size && ok==1;i++)
    {
      if(*(v1+i)!=*(v2+i))
	  ok=0;
    }
  if(ok==1)
    printf("sunt toate egale");
  else
    printf("nu sunt egale");
}
int main ()
{
  int tab1[1000],tab2[1000],n;
  /*scanf("%d%d",&a,&b);
  if(a>b)
    p=&a;
  else
    p=&b;
  printf("%d",*p);
  */
  scanf("%d",&n);
  citire(tab1,&n);
  citire(tab2,&n);
  egal(tab1,tab2,n);

  return 0;
}
