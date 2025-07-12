/*Aplicația 10.1: Calculați recursiv cel mai mare divizor comun a două numere.
𝑐𝑚𝑚𝑑𝑐(𝑎, 𝑏) = { 𝑎, 𝑑𝑎𝑐ă 𝑏 = 0
                 𝑐𝑚𝑚𝑑𝑐(𝑏, 𝑎%𝑏), 𝑑𝑎𝑐ă 𝑏 > 0
*/
#include<stdio.h>
#include<stdlib.h>

int cmmdc(int a,int b)
{
  if(b==0)
    return a;
  else
      return cmmdc(b,a%b);
}

int main()
{
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d",cmmdc(a,b));

  return 0;
}
