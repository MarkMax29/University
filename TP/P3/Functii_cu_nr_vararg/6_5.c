/*Aplicația 6.5: Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice
în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe
ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
Exemplu: input(”n=%dch=%c”,&n,&ch);
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
void input(const char *fmt,...)
{
  va_list va;
  va_start(va,fmt);

  while(*fmt!='\0')
    {

      if(*fmt=='%')
	{
	  fmt++;
	  switch(*fmt)
	    {
	    case 'd':
	      {
		int *iadr=va_arg(va,int*);
		scanf("%d",iadr);
		//printf("%d",*iadr);
		break;
	      }
	    case 'f':
	      {
		float *fadr=va_arg(va,float*);
		scanf("%f",fadr);
		//printf("%lf",*fadr);
		break;
	      }
	    case 'c':
	      {
		char *cadr=va_arg(va,char*);
		scanf(" %c",cadr);
		//printf("%c",*cadr);
		break;
	      }
	    }
	}
      else
	{
	  putchar(*fmt);
	}
      fmt++;
    }
  va_end(va);
  
}


int main()
{
  int n;
  char ch;
  float f;
  input("n=%df=%fch=%c",&n,&ch,&f);
  printf("%c\n",ch);
  printf("%.1f\n",f);

  return 0;
}
