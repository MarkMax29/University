/*Aplicația 4.5: Să se codifice următoarele informații despre un medicament, astfel încât ele să ocupe în total un
singur octet. Să se scrie un program care să citească datele unui medicament și ulterior să le afișeze.
● gradul de periculozitate: scăzută, medie, mare
● dacă se eliberează doar pe bază de rețetă: da, nu
● vârsta minimă de administrare: 1...18 ani inclusiv
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct  MEDICAMENT{
  
    unsigned int eliberare:1;
     unsigned int pericol:2;
    unsigned int varsta_min:5;
   
}MEDICAMENT;

int main()
{
  MEDICAMENT x;
  unsigned int eliberare,pericol,varsta_min;
  printf("size:%ld\n",sizeof(MEDICAMENT));
  printf("Introduceti date medicament:");scanf("%d %d %d",&eliberare,&pericol,&varsta_min);
  x.eliberare=eliberare;
  x.pericol=pericol;
  x.varsta_min=varsta_min;
  switch(x.pericol)
    {
    case 0:
      {
	switch(x.eliberare)
	  {
	  case 0:
	    {
	      printf("grad de pericol: SCAZUTA - eliberare pe baza de reteta: NU - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  case 1:
	    {
	      printf("grad de pericol: SCAZUTA - eliberare pe baza de reteta: DA - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  }
	break;
      }
    case 1:
      {
	switch(x.eliberare)
	  {
	  case 0:
	    {
	      printf("grad de pericol: MEDIE - eliberare pe baza de reteta: NU - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  case 1:
	    {
	      printf("grad de pericol: MEDIE - eliberare pe baza de reteta: DA - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  }
	break;
      }
       case 2:
      {
	switch(x.eliberare)
	  {
	  case 0:
	    {
	      printf("grad de pericol: MARE - eliberare pe baza de reteta: NU - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  case 1:
	    {
	      printf("grad de pericol: MARE - eliberare pe baza de reteta: DA - varsta minima de administratie: %d",x.varsta_min);
	      break;
	    }
	  }
	break;
      }
    }
      
		     
	 

  
  return 0;
}
