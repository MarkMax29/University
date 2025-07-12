/*Aplicația 4.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre
animale:
● numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
● greutatea în kg: număr real
● periculos pentru om: da/nu
● abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
● vârsta maximă în ani: număr întreg, minim 0, maxim 2000
Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1,
“nu”=0. Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. Afişaţi spaţiul de memorie
ocupat, folosind operatorul sizeof. Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar
pe urmă afişaţi-le pe ecran.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ANIMAL{
  float kg;
  char abrev[9];
  unsigned int pericol:1;
  unsigned int picior:10;
  unsigned int varsta:11;
}ANIMAL;


int main()
{

  ANIMAL x;
  printf("Dimensiunea structurii este: %ld\n",sizeof(ANIMAL));
  int pericol,picior,varsta;
  printf("informatii despre un animal: ");scanf("%s %f %d %d %d",x.abrev,&x.kg,&pericol,&picior,&varsta);
  x.pericol=pericol;
  x.picior=picior;
  x.varsta=varsta;

  if(x.pericol==0)
    printf("abrev:%s - greutate:%.1f kg - varsta:%d - picioare:%d - pericol: nu\n",x.abrev,x.kg,x.varsta,x.picior); 
  else
     printf("abrev:%s - greutate:%.1f kg - varsta:%d - picioare:%d - pericol: da\n",x.abrev,x.kg,x.varsta,x.picior); 
					    
  return 0;
}

