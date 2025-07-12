/*Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
negativ și să se afișeze vectorul rezultat.
*/
#include<stdio.h>
#include<stdlib.h>
int negativ(int nr)
{
  if(nr<0)
    return 1;
  return 0;
}

void pb(int *v,int *size,int (*func)(int))
{
  for(int i=0;i<*size;i++)
    {
      if(negativ(v[i])==1)
	{
	  for(int j=i;j<*size;j++)
	    {
	      v[j]=v[j+1];
	    }
	  *size=*size-1;
	}
    }
  for(int i=0;i<*size;i++)
    printf("%d ",v[i]);
      
}
int main()
{
  int n;
  printf("Introdu n: ");scanf("%d",&n);
  int *v=NULL;
  v=malloc(sizeof(int)*n);
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    scanf("%d",&v[i]);
  pb(v,&n,negativ);
    	 

  return 0;
}
