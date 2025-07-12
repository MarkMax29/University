#include<stdio.h>
#include<string.h>
#include<ctype.h>
int ex1(char c)
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
      }
  return k;
  //printf("\nIn stdint sunt: %d cuvinete\n",k);
}
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
void ex3()
{
  char ch=0;float procent;
  int v[30]={0},i,contor=0;
  while((ch=getchar())!=EOF)
    {
      i=ch-'a';
      v[i]++;
      contor++;
    }
  printf("\n");
  for(int i=0;i<26;i++)
    {
      char litera='a'+i;
      if(v[i]!=0)
	{
	  procent=v[i]*100/(float)contor;
	  printf("%c - %.2f%%\n",litera,procent);
	}
    }
}
void ex4()
{
  char ch=0;
  while((ch=getchar())!=EOF)
    {
      if(islower(ch))
	putchar(toupper(ch));
      else
	putchar(tolower(ch));
    }
}
void ex5()
{
  char ch=0,caract=0,linii=0,cuvinte=0,space=0;
  while((ch=getchar())!=EOF)
    {
      if(isspace(ch))
	  space++;
      else
	space=0;
	  
      if(space==1)
	  cuvinte++;
      caract++;
      if(ch=='\n')
	linii++;
      putchar(ch);
    }
  if(space)
    cuvinte++;
  printf("%7d\n%7d\n%7d\n",linii, cuvinte, caract);
}

void prob6()
{
  char ch=0,linii=0,cuv=0,space=0;
  while((ch=getchar())!=EOF)
    {
      if(ch=='\n')
      	linii++;
	  
      if(isspace(ch))
	space++;
      else
	space=0;
      if(space==1)
	cuv++;
      putchar(ch);
    }
  if(space)
    cuv++;

  printf("\n%d %d",linii,cuv);

}

void prb7()
{
  char ch=0;
  int  space=0,ok=0,cuv=0;
  if((ch=getchar())!=EOF)
    { ch=ch-32;
      ok=1;
      putchar(ch);
    }
  while((ch=getchar())!=EOF)
    {
      if(isalpha(ch) && space==1)
	{ch=ch-32;
	  space=0;
	  cuv++;
	  
	}
      else
	{
	  if(isspace(ch))
	    space=1;
	  else
	    space=0;
	}
      putchar(ch);
    }
  if(space)
    cuv++;
  printf("%d",cuv);
}
void prb8()
{
char ch;
	int tag=0, start=0, end=0; // ?!?!?!??!?!
	
	
	while((ch = getchar())!=EOF)
	{
		if(ch == '<')
			tag = 1;
		else if(ch == '>')
			tag = 0;
	        if(tag!=0)
		{
			if(ch == '/')
				end++;
			else if(ch !=' ' && ch!='\n')
				start++;
		}
	}
	
	printf("start - %d\n end - %d", start, end);
}
        
	
int main()
{ char c=0;
  //ex1(c);//ca sa mearga 2 nu stiu dc trb pus comentariu apelul asta
  //p2(c);
  // ex3();
  //printf("\n");
  //ex4(c);
  //ex5(c);
  // prob6(c);
  //prb7();
  prb8();
 return 0;
}
