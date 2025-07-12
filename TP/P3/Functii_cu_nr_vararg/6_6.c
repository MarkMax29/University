/*Aplicația 6.6: Să se scrie o funcție char *concat(int n,...) care primește un număr de șiruri de caractere și apoi
șirurile propriu-zise. Funcția va concatena într-un nou șir, alocat dinamic, conținuturile tuturor șirurilor date, cu câte
un spațiu între ele și va returna acest șir.
Exemplu: concat(3,”Ion”,”si”,”Ana”) => “Ion si Ana”
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
char *concat(int n,...)
{
  va_list va;
  va_start(va,n);
  char *sir=NULL;
  char *s=NULL;
  int length=0;
  for(int i=0;i<n;i++)
    {
      s=va_arg(va,char*);
      length=length+(sizeof(char)*strlen(s)+1);
    }
  
  sir=malloc(length*sizeof(char));
  if(sir==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  va_end(va);
  va_start(va,n);
  for(int i=0;i<n;i++)
    {
      s=va_arg(va,char*);
      strcat(sir,s);
      if(i!=n-1)
	strcat(sir," ");

    }
  va_end(va);
  return sir;



}

int main()
{
  char *sir;
  sir=concat(3,"Ion","are","mere");
  printf("%s",sir);
    free(sir);
  return 0;
}
