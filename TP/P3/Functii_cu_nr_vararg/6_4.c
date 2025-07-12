/*Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9))*/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int crescator(int n,char tip,...)
{
  va_list va;
  va_start(va,tip);
  int ok=1;
  switch(tip)
    {
    case 'd':
      {
	int v[n];
	for(int i=0;i<n;i++)
	  {
	    v[i]=va_arg(va,int);
	  }
	for(int i=0;i<n-1 && ok==1;i++)
	  {
	    if(v[i]>v[i+1])
	      ok=0;
	  }
	       
	break;
      }
    case 'f':
      {
       double v[n];
	for(int i=0;i<n;i++)
	  {
	    v[i]=va_arg(va,double);
	  }
	for(int i=0;i<n-1 && ok==1;i++)
	  {
	    if(v[i]>v[i+1])
	      ok=0;
	  }

	break; 
      }
    }
  va_end va;
  if(ok==1)
    return 1;
  return 0;

}

int main()
{
  int val;
  val=crescator(3,'f',-1.3,7.4,9.9);
  if(val==1)
    printf("NUMERELE SUNT CRESCATOARE\n");
  else
    printf("NUMERELE SUNT DESCRESCATOARE\n");

  return 0;
}
