#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdint.h>

void pr1()
{
  char sir[100];
  int lungime=0;
  fgets(sir,100,stdin);
  for(int i=0;sir[i];i++)
    {
      if(isalpha(sir[i]))
	 lungime++;
      else
	{
	   sir[i-lungime]=toupper(sir[i-lungime]);
	   lungime=0; 
	}
    }
   printf("%s\n",sir);
   }
void  pr2()
{
  char nume[10][100],nume_max[100];
  int n,lung=0,max=0;
  scanf("%d",&n);//scanf foloseste in buffer un newline astfel daca citesc dupa cu fgets va citi caracterul newline si nume[0] ramane gol
  getchar();//folosim sa consumam elementul newline din buffer 
  for(int i=0;i<n;i++)
    {
      if(fgets(nume[i],100,stdin)!=NULL)
      {
	lung=strlen(nume[i])-1;//cum fgets citeste si newline se adauga si asta la lungime ceea ce noi nu vrem
	if(lung>max)
	  {
	    max=lung;
	    strcpy(nume_max,nume[i]);
	  }
      }
      else
	{printf("nu se poate");
	  break;
	}
    }
  printf("Lungimea maxima:%d, pentru numele:%s",max ,nume_max);
  }


typedef struct
{
  char nume[50];
  int frecv;
}Data;
Data vector[11];

void pr3()//nu merge
{
  int n;
  char NUME[10][50];
  scanf("%d",&n);
  getchar();
  for(int i=0;i<n;i++)
    {scanf("%s",NUME[i]);
  getchar();
    }
  for(int i=0;i<11;i++)
    vector[i].frecv=0;

  for(int i=0;i<n;i++)
    {
      int gasit=0;
      for(int j=0;j<11;i++)
	{
	  if(strcmp(NUME[i],vector[j].nume)==0)
	    {
	      vector[j].frecv++;
	      gasit=1;
	      break;
	    }
	}
      if(!gasit)
	{for(int j=0;j<11;j++)
	    { if(vector[j].frecv==0)
		{strcpy(vector[j].nume,NUME[i]);
		  vector[j].frecv=1;
		  break;
		}
	    }
	}
    }
  for(int i=0;i<n;i++)
    if(vector[i].frecv!=0)
      printf("%s - %d\n",vector[i].nume,vector[i].frecv);
}
	      
void pr4()
{
  char str[100];
  int j,frecv[30]={0};
  fgets(str,100,stdin);
  for(int i=0;str[i];i++)
    {
      j=str[i]-'a';
      frecv[j]++;
    }
  for(j=0;j<27;j++)
    {
      if(frecv[j]!=0)
       {
	 char litera='a'+j;
	 printf("%c-%d\n",litera,frecv[j]);
       }
    }
}
void pr5()
{
  char nume[10][30];
  char sir[300];
  int n;
  scanf("%d",&n);
  getchar();
  scanf("%s",nume[0]);
  getchar();
  strcpy(sir,nume[0]);
  for(int i=1;i<n-1;i++)
    {
      scanf("%s",nume[i]);
      getchar();
      strcat(sir,", ");
      strcat(sir,nume[i]);
    }
  scanf("%s",nume[n-1]);
  getchar();
      strcat(sir," si ");
      strcat(sir,nume[n-1]);
      strcat(sir," invata");
      

      printf("%s\n",sir);
}

typedef struct
{
  char nume[50];
  float cantitate,pret;
}prod;
prod produs [11];

void pb6()
{ int n,index=0;
  float suma_totala=0;
  char NUME[10][50];
  
  scanf("%d",&n);
  getchar();
  for(int i=0;i<11;i++)
    {
      produs[i].pret=0;
      produs[i].cantitate=0;
    }
  for(int i=0; i<n; i++)
    {
      scanf("%s %g %g", produs[i].nume, &produs[i].cantitate, &produs[i].pret);
    }
  for(int i=0;i<n;i++)
    {
      int gasit=0;
      for(int j=0;j<index;j++)
	{
	  if(strcmp(NUME[j],produs[i].nume)==0)
	    gasit=1;
	}
      if(gasit==0)
	{strcpy(NUME[index],produs[i].nume);
	  index++;
	}
    }
  for(int i=0;i<index;i++)
    {
      printf("%s: ",NUME[i]);
      float cant=0,pret_total=0;
      for(int j=0;j<n;j++)
	{if(strcmp(NUME[i],produs[j].nume)==0)
	    {
	      cant=cant+produs[j].cantitate;
	      pret_total=pret_total+produs[j].pret*produs[j].cantitate;
	    }
	}
	  printf("%g %g\n",cant,pret_total);
	  suma_totala=suma_totala+pret_total;
    }
  printf("Pret Global: %g",suma_totala);
}


uint32_t upper_sub_string(char *string,char *substring)
{
  uint32_t c=0;
  char *p;
  while((p=strstr(string,substring))!=NULL)
    {
      for(int i=0;substring[i];i++)
	{
	  p[i]=toupper(p[i]);
	}
      c++;
    }
  return c;
}

  
int main(void)
{
  // pr1();
  //  pr2();
  //pr3();
  // pr4() ;
  //  pr5();
  //pb6();
  char s1[100],s2[20];
  fgets(s1,100,stdin);
  fgets(s2,20,stdin);
  s2[strlen(s2)-1]='\0';
  uint32_t c=upper_sub_string(s1,s2);
  printf("%s",s1);
  printf("%d\n",c);
  
  return 0;
  
}
