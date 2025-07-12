#include<stdio.h>
#include<stdint.h>
void afis(uint8_t  n)
{
  // uint8_t  count=0; 
  for(int i=7;i>=0;i--)
    {
      printf("%d",(n&(1<<i))>>i);
      
      if(i%4==0)
	printf(" ");
    }
}
void schimbare(uint8_t n)
{

  for(int i=7;i>=0;i--)
    {
       if(i==0 || i==2|| i==3)
	 n=n|(1<<i);//n|masca de fapt mutat cu i pozitii la stanga
       if(i==1|| i==5|| i==6)
	 n=n&~(1<<i);
       else  if(i==4 || i==7 )
	 n=n^(1<<i);
      
    }
   afis(n);
}

int main()
{
  uint8_t n;
  scanf("%x",&n);
    afis(n);
    printf("\n");
    schimbare(n);
    printf("\n");

  return 0;
}
