/*Aplicația 4.6: Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și multiplicatorul
acesteia (pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga).
● Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval
cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia. O măsurătoare va ocupa exact 2
octeți.
● Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. Să se determine
multiplicatorul astfel încât valoarea stocată să fie cât mai mică, fără a se pierde precizie, iar apoi să se
stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile
măsurătorii.


Exemplu: valoare=147000, unitate:gram => 147 kilogram

*/

#include<stdio.h>
#include<stdlib.h>
typedef struct MASURARE{
  unsigned int um:2;
  unsigned int mul:4;
  unsigned int valoare:11;
}MASURARE;
  
int main()
{
  printf("%ld",sizeof(MASURARE));
  return 0;
}
