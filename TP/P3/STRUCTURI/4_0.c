/*Aplicația 4.0: Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct ELEV{
  char nume[21];
  int nota;
}ELEV;


int main()
{
  ELEV x;
  printf("Introdu date elev: ");scanf("%19s %d",x.nume,&x.nota);
  printf("%s - %d\n",x.nume,x.nota);
  

  return 0;
}
	   
