/*Aplicația 6.9: Scrieți un program care calculează suma parametrilor primiți din linia de comandă (numere reale).
  Exemplu: execuția fără parametri va fișa 0, iar execuția cu parametrii 1.1 6.57 99.122 va afișa 106.792*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char ** argv)
{
  float suma=0,n;
  //if(argc==1)
  // return 0;
  for(int i=1;i<argc;i++)
    {
      n=atof(argv[i]);
      suma=suma+n;
    }
  printf("%.3f",suma);

  return 0;
  
}
