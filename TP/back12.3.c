#include<stdio.h>
#include<stdlib.h>

int valid(int *v,int k)
{
  for(int i=0;i<k;i++)
    {
      if(v[i]==v[k])
	return 0;//verifica daca culorile sunt distincte pana la pozitia k
    }
  if(k>=1 && v[1]!=1 && v[1]!=3)
    return 0;//verifica daca k este cel putin 1 adica daca am ajuns sa setam a 2a culoare si daca acesta e diferit de galben sau verde returneaza 0 adica nu e valid aranjamentul
  return 1;//altfel daca conditiile sunt indeplinite se returneaza 1 adica aranjamentul e valid
}
int solutie(int k)//verifica daca k=2 adica a ajuns la 3 steaguri 
{

  if(k+1==3)
    return 1;
  return 0;
}

void afisare(int k,int *v,char **INIT)
{
  for(int i=0;i<k;i++)
    {
      printf("%s ",INIT[v[i]]);
	}
  printf("\n");
}

void back(int k,int *v,char **INIT)
{
  for(int i=0;i<6;i++)
    {
      v[k]=i;
      if(valid(v,k))
	{
	  if(solutie(k))
	    afisare(k+1,v,INIT);
	  else
	    back(k+1,v,INIT);
	}
    }
}

int main()
{
  char *INIT[]={"alb","galben","rosu","verde","albastru","negru"};
  int v[]={0,0,0,0,0,0};
  back(0,v,INIT);
  
  return 0;
  
}
  
