/*Aplicația 6.10: Să se scrie un program denumit criptare, care criptează/decriptează un text primit în linia de
comandă. Programul va fi apelat în felul următor: ./criptare operatie cheie cuvant1 cuvant2 ...
Operația poate fi enc pentru criptare sau dec decriptare. Cheia este un număr întreg. Algoritmul de criptare este
următorul: pentru fiecare literă din cuvinte se consideră codul său ASCII, la care se adună cheia specificată,
rezultând un nou cod ASCII, cel al literei criptate. Adunarea este circulară, adică ‘z’ incrementat cu 1 devine ‘a’.
Decriptarea este inversă: din cuvintele criptate se scade circular cheia specificată. Literele mari se transformă la
început în litere mici.
Exemple:
./criptare enc 1 zaraza -> absbab
./criptare dec 1 bcfdfebs -> abecedar
./criptare enc 10 vine VINE primavara PRImaVAra -> fsxo fsxo zbswkfkbk zbswkfkbk
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char *operatie(int op,char *cuv,int cheie)
{
  switch(op)
    {
    case 1:
      {
	for(int i=0;i<strlen(cuv);i++)
	  {
	    if(isupper(cuv[i]))
	      cuv[i]=tolower(cuv[i]);
	    cuv[i]='a'+(cuv[i]-'a'+cheie)%26;
	  }
	break;
      }
    case 2:
      {
	for(int i=0;i<strlen(cuv);i++)
	  {
	    if(isupper(cuv[i]))
	      cuv[i]=tolower(cuv[i]);
	    cuv[i]='a'+(cuv[i]-'a'-cheie+26)%26;
	  }
	break;
      }
     
	    
    }
  return cuv;
}
int main(int argc,char **argv)
{
  char *sir;
  int cheie=atoi(argv[2]);
  int op;
  if(strcmp(argv[1],"enc")==0)
    op=1;
  else
    op=2;
  for(int i=3;i<argc;i++)
    {
      sir=operatie(op,argv[i],cheie);
      printf("%s ",sir);
    }
  printf("\n");

  return 0;
}
  
