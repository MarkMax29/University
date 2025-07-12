#include<stdio.h>
#include<string.h>
#include<ctype.h>
void ex1(char c)
{
  int k=0,space=0;
  c=0;
  while((c=getchar())!=EOF)
    {
      if(isspace(c))
	  space++;
      else
	space=0;
	  
      if(space==1)
	  k++;
	
     putchar(c);
      }
  printf("\nIn stdint sunt: %d cuvinete\n",k);
}
/*void ex2(char c)
{
  int bara=0,ok=1;
  while((c=getchar())!=EOF)
    {
      if(ok==0)
	{ if(c=='/')
	     ok=1;
	  else
	    putchar(c);
	}
      else
	{
	  if(c=='\n')
	    {
	      ok=0;
	      putchar(c);
	    }
	}
    }
    }*/
void p2()
{
  char ch;
  int comentariu=0;
  while((ch = getchar())!=EOF)
    {
      if(comentariu == 0)
	{
	  if(ch!='/')
	    putchar(ch);
	  else
	    comentariu = 1;
        }
      else
	{
	  if(ch == '\n')
	    {
	      comentariu = 0;
	      putchar(ch);
	    }
      	}
		
    }
}

int main(void)
{
  char c=0;
  ex1(c);
  p2();


  return 0;
}
