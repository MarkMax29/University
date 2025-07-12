#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
int segm(uint8_t n)//ex1
{
  int bitant=-1,seg=-0;
  for(int i=7;i>0;i--)
    {
      int bitcurent=n&(1<<i);
      if(bitcurent!=bitant)
	seg++;
      bitant=bitcurent;
    }
  return seg;
}

void citire(int *nr, int *v)
{
  int value;
  for(int i=0;i<*nr;i++)
    {
      scanf("%d",&value);
      *v=value;
      v++;
    }
}

void verif(int nr,int *v)//ex4
{
  int ok=1;
  for(int i=0;i<nr && ok==1;i++)
    {
      if(*v>0 && *v%2!=0)
	ok=0;
    }
  if(ok==1)
    printf("Ex3:Sunt toate pare\n");
  else
    printf("Ex3:Nu sunt toate pare\n");

}
void absolut(int nr,int *v)//ex6
{
  for(int i=0;i<nr;i++)
    {
      if(*v<0)
	{
	  if((abs(*v))>10)
	    printf("%d ",*v);
	}
      else
	  {
	    if(*v>10)
	      printf("%d ",*v);
	  }
      v++;
    }
}

int main()
{
  /* uint8_t n=0b000100;
  int v[]={7, -5, 4, 3, -9, 2, -8},nr,tab[1000],k,count=0;
  int size=sizeof(v)/sizeof(v[0]),mini=v[0];
  int x,y,nr2;
  printf("Ex1:%d\n",segm(n));


  scanf("%d%d%d",&k,&x,&y);
  for(int i=0;i<size;i++)
    {
      if(v[i]>k)
	count++;
      if(v[i]<mini)
	mini=v[i];
    }

 printf("Ex2:%d\n",mini);
 mini=v[0];
  for(int i=0;i<size;i++)
    {

      if(v[i]<mini && v[i]>x && v[i]<y)
	mini=v[i];
    }
 printf("Ex5:%d\n",mini);
  
   if(count!=0)
     printf("Ex4:Existaaaaa baaani");
   else
     printf("Ex4:Nu existaaa baaani");

   
 scanf("%d",&nr);
 citire(&nr,tab);
 verif(nr,tab);
  */
  int nr2,tab[1000];
 scanf("%d",&nr2);
 citire(&nr2,tab);
 absolut(nr2,tab);



 
  return 0;
}
