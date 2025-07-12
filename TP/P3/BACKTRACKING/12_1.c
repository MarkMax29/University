/*Aplicația 12.1: Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din
n cifre care contin exact k cifre de 1.
*/
#include<stdio.h>
#include<stdlib.h>
/*int valid(int *sol,int poz)
{
  for(int i=0;i<poz;i++)
    {
      if(sol[i]==sol[poz])
	return 0;
    }
  return 1;
  }*/
int solutie(int *sol,int poz,int n,int k)
{
  
  if(poz!=n)
    return 0;
  if(sol[0]==0 && n>1)
    return 0;
  
  int c=0;
  for(int i=0;i<n;i++)
    {
      
      if(sol[i]==1)
	c++;
      
    }
  if(c!=k)
    return 0;
  return 1;
}
void afis(int *sol,int n)
{
  for(int i=0;i<n;i++)
    printf("%d",sol[i]);
  printf("\n");

}
void back(int *sol,int n,int poz,int k)
{
   if(solutie(sol,poz,n,k))
     afis(sol,n);
   else if(poz<n)
     {
       for(int i=0;i<=9;i++)
	 {
	   sol[poz]=i;
	   back(sol,n,poz+1,k);
	   
	 }
     }
}

int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  int sol[n];
  for (int i = 0; i < n; i++) {
        sol[i] = 0;
    }
  back(sol,n,0,k);


  return 0;
}
