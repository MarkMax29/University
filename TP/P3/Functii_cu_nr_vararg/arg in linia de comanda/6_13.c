#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int total(int arg,char ** sir)
{
  int nr_lit=0;
  for(int i=2;i<arg;i++)
    {
      for(int j=0;j<strlen(sir[i]);j++)
	{
	  nr_lit++;
	}
    }
  return nr_lit;
}
void frecventa(int arg,char ** sir)
{
  int frecv[26];
     for (int i = 0; i < 26; i++) {
        frecv[i] = 0;
    }
  for(int i=2;i<arg;i++)
    {
      for(int j=0;j<strlen(sir[i]);j++)
	{
	  frecv[sir[i][j]-'a']++;
	}
    }
  for(int i=0;i<26;i++)
    {
      if(frecv[i]>0)
	printf("%c: %d\n",'a'+i,frecv[i]);
    }


}
int main(int argc,char ** argv)
{
  int cod=atoi(argv[1]);

      switch(cod)
	{
	case 0:
	  {
	    int nr=total(argc,argv);
	    printf("sunt %d litere in total\n",nr);
	    break;
	  }
	case 1:
	  {
	    frecventa(argc,argv);
	    break;
	  }
	}
	   

  return 0;
}
