/*Subiectul 2.2 Se citesc mai multe cuvinte din linia de comandă. Cu ajutorul pointerilor la funcții (un vector de
pointeri la funcții) să se apeleze într-o structură repetitivă următoarele funcții. Să se afișeze rezultatele pentru
fiecare cuvânt pe ecran și în fișierul text CUVINTE.TXT.
a) Primește parametru un șir de caractere și returneză lungimea șirului.
b) Primește parametru un șir de caractere și returneză numărul de vocale din text.
c) Primește parametru un șir de caractere și returneză numărul de litere mari din text.
d) Primește parametru un șir de caractere și returneză diferența codurilor ASCII ale primului caracter și al ultimului
caracter.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int f1(char *sir)
{
  return strlen(sir);
}
int f2(char *sir)
{
  int voc=0;
  for(int i=0;i<strlen(sir);i++)
    {
      if(strchr("aeiou",sir[i]))
	 voc++;
    }
  return voc;
}

int f3(char *sir)
{
  int mare=0;
  for(int i=0;i<strlen(sir);i++)
    {
      if(isupper(sir[i]))
	mare++;
    }
  return mare;
}

int f4(char *sir)
{
  return abs(sir[0]-sir[strlen(sir)-1]);
}

      
int main(int argc,char **argv)
{
  int (*v[4])(char*);
  v[0]=f1;
  v[1]=f2;
  v[2]=f3;
  v[3]=f4;
  for(int i=1;i<argc;i++)
    {
      printf("Pentru cuv %s: \n",argv[i]);
      for(int j=0;j<=3;j++)
	{
	  printf("functia %d afiseaza :%d\n",j+1,v[j](argv[i]));
	}
      printf("\n");
    }
     
  return 0;  
}
     
  
  
