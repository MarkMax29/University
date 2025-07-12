/*Aplicația 8.7: Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă dintre
ele. Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct. Să se afișeze perechea de orașe
cele mai apropiate între ele în mod direct.*/
#include<stdio.h>
#include<stdlib.h>
void pb()
{
  int n;
  printf("n=");scanf("%d",&n);
  if(n>10)
    exit(-1);
  int a[n][n],A=-1,B=-1,mini=9999999;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d",&a[i][j]);
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  if(mini>=a[i][j] && a[i][j]!=0)
	    {
	      mini=a[i][j];
	      A=i;
	      B=j;
	    }
	}
    }
  if(A!=-1 && B!=-1)
    printf("Perechea de orase cu distanta cea mai mica este: orasul %d si orasul %d, cu o distanta de %d km\n",A,B,mini);
  else
    printf("Nu exista niciun drum direct intre 2 orase");
   

}
int main()
{
  pb();

  return 0;
}
