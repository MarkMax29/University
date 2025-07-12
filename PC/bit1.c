#include<stdio.h>
#include<stdint.h>
void afis(uint64_t n)
{
  // uint8_t  count=0;                                                          
  for(int i=(sizeof(n)*8)-1;i>=0;i--)
    {
      printf("%d",(n&(1<<i))>>i);
      if(i%4==0)
        printf(" ");
    }
}
void adunare(uint16_t a, uint16_t b)
{
  uint16_t carry=0x0,suma=0x0;
  int ok,c;
  ok=1;
  while(ok==1)
    {
      carry=0x0;c=0;
      for(int i=0,j=0;i<=(sizeof(a)*8)-1 && j<=(sizeof(b)*8)-1;i++,j++)
	{
	  if(((a&(1<<i))>>i)==1 && ((b&(1<<j))>>j)==1)
	    { carry=carry|(1<<(i+1));
	      c++;
	    }
	}
      if(c==0)
	{
	  ok=0;
	  suma=(a^b)^carry;
	}
      else
	{
	  suma=a^b;
	  a=suma;
	  b=carry;
	}
    }
  printf("%d\n",suma);
  afis(suma);
}
int numara(uint8_t n)
{
  int c=0;
  for(int i=7;i>=0;i--)
    {
      if(((n&(1<<i))>>i)==1)
	c++;
    }
  return c;
}
int  nibble(uint8_t n)
{
  uint8_t aux=0x0;
  aux=0xF&n;
  n=(aux<<4)|(n>>4);
  return n;
}
int segm_pr15(uint8_t x)
{
  int k=1,a,b;
  a=x&1;
  for(int i=0;i<=(sizeof(x)*8)-1;i++)
    {
      b=(x&(1<<i))>>i;
      if(a!=b)
	{
	  k++;
	  a=b;
	}
    }
  return k;
}
void schimb_pr_18(uint64_t nr,uint8_t l,int p)
{
  uint64_t copy;
  copy=(nr>>(p*8))&0xFF;
  copy=l;
  for(int j=p*8;j<p*8+8;j++)
  {
    nr=nr&~(1<<j);
  }
  nr=nr|(copy<<(p*8));
  afis(nr);
} 
int main()
{
  uint64_t nr;
  // unt16_t a,b;
  uint8_t n;
  int p;
  /* printf("introduceti a: ");
  scanf("%hd",&a);
  printf("introduceti b: ");
  scanf("%hd",&b);
  afis(a);
  printf("\n");
  afis(b);
  printf("\n");
  adunare(a,b);
  printf("\nintroduceti n:");
  scanf("%hhx",&n);
  // printf("%d\n",numara(n));
  // afis(nibble(n));
  printf("%d",segm_pr15(n));*/
  printf("introduceti nr:");
  scanf("%ld",&nr);
  afis(nr);
  printf("\nintroduceti n:");
  scanf("%hhx",&n);
  afis(n);
  printf("\nintroduceti p:");
  scanf("%d",&p);
  schimb_pr_18(nr,n,p);
  return 0;
}
