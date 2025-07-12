/*Aplicația 6.12: Un program primește în linia de comandă o serie de opțiuni și de cuvinte, mixate între ele. Opțiunile
specifică operații care se execută asupra cuvintelor. Opțiunile încep cu - (minus) și pot fi: u-transformă toate literele
cuvintelor în majuscule; f-transformă prima literă în majusculă și următoarele în minuscule; r-inversează literele din
cuvinte. După fiecare cuvânt se resetează toate opțiunile anterioare. Să se afișeze cuvintele primite în linia de
comandă cu transformările aplicate.
Exemplu: ./procesare -f mAria -r -u abac va afișa: Maria CABA
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void maj(char *sir)
{
  for(int i=0;i<strlen(sir);i++)
    {
      sir[i]=toupper(sir[i]);
    }
}
void prim_maj(char *sir)
{
  sir[0]=toupper(sir[0]);
  for(int i=1;i<strlen(sir);i++)
    {
      sir[i]=tolower(sir[i]);
    }
	
}
void inversare(char *sir)
{
  char *cuv=NULL;
  cuv=malloc(sizeof(char)*strlen(sir));
  if(cuv==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int j=0,i=strlen(sir)-1;i>=0;i--,j++)
    {
      cuv[j]=sir[i];
    }
  strcpy(sir,cuv);

}
int main(int argc,char **argv)
{
  int u=0,f=0,r=0;
  for(int i=1;i<argc;i++)
    {
      if(argv[i][0]=='-')
	{
	  for(int j=1;argv[i][j];j++)
	    {
	      switch(argv[i][j])
		{
		case 'u':
		  {
		    u=1;
		    break;
		  }
		case 'f':
		  {
		    f=1;
		    break;
		  }
		case 'r':
		  {
		    r=1;;
		    break;
		  }
		}
	    }
	}
      else
	{
	  if(u==1)
	    maj(argv[i]);
	  if(f==1)
	    prim_maj(argv[i]);
	  if(r==1)
	    inversare(argv[i]);
	  printf("%s ",argv[i]);
	  u=0;
	  f=0;
	  r=0;
	}

    }


  return 0;
}

	 
