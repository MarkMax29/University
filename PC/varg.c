#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define NR 3
//ex6.2
double *allocVec(int n,...)
{
  va_list va;
  double *v=NULL;
  v=malloc(n*sizeof(double));
  if(v==NULL)
    {
      printf("eroare la alocare");
      exit(-1);
    }
  va_start(va,n);
  for(int i=0;i<n;i++)
    {
      v[i]=va_arg(va,double);
    }
  
  va_end(va);
  return v;

}
//ex6.3

void absN(int n,...)
{
  va_list va;
  va_start(va,n);
  for(int i=0;i<n;i++)
    {
      double *ptr=va_arg(va,double *);
      *ptr=fabs(*ptr);
    }
  va_end(va);
  
}
//ex6.4
int crescator(int n,char tip,...)
{
  va_list va;
  va_start(va,tip);
  int ok=1;
  switch(tip)
    { case 'd':
	int a=va_arg(va,int);
	while(--n && ok!=0)
	  {
	    int b=va_arg(va,int);
	    if(a>b)
	      ok=0;
	    a=b;
	  }
	break;
    case 'f':
      double c=va_arg(va,double);
	while(--n && ok!=0)
	  {
	    double d=va_arg(va,double);
	    if(c>d)
	      ok=0;
	    c=d;
	  }
	break;
    }
  if(ok==1)
    return 1;
  return 0;
	
}
//ex6.5?
void input(const char *fmt,...)
{
  va_list va;
  va_start(va,fmt);
  int *adrint;
  double *adrdouble;
  char *adrchar;
  for(;;fmt++)
    {
      if(*fmt+1=='%')
	{if(*fmt+2=='d')
	    {adrint=va_arg(va,int*);
	      scanf("%d",adrint);
	    }
	  else if(*fmt+2=='f')
	    {
	      adrdouble=va_arg(va,double*);
	      scanf("%lf",adrdouble);
	    }
	  else if(*fmt+2=='c')
	    {
	      adrchar=va_arg(va,char*);
	      scanf("%s",adrchar);
	    }
	}
      if(*fmt=='\0')
	{  va_end(va);
	  return;}
    }

		
}

//ex6.6
char *concat(int n,...)
{
  va_list va;
  va_start(va,n); 
  char *str1=NULL;
  str1=va_arg(va,char*);
  char *str=NULL;
  str=malloc(strlen(str1)*sizeof(char)+2);
   if(str==NULL)
     {
       printf("eroare la alocare");
       exit(-1);
     }
  for(int i=0;i<n;i++)
    {
      if(i==0)
	{
	  strcpy(str,str1);
	  strcat(str," ");
	}
      else
	{
	  str1=va_arg(va,char*);
	  str=realloc(str,sizeof(char)*strlen(str1)+2);
	  if(str==NULL)
	    {
	      printf("eroare la alocare");
	      free(str);
	      exit(-1);
	    }
	  strcat(str,str1);
	  strcat(str," ");
	}
       
    }
  return str;
  va_end(va);

}
//ex 6.7
int comune(int nVec,...)
{
  va_list va;
  va_start(va,nVec);

  int c=0;
  int *primul_vect=va_arg(va,int *);
  int size1=va_arg(va,int);
 

  for(int i=0;i<size1;i++)
    {
      int val_curenta=primul_vect[i];
      int j;

      for(j=1;j<nVec;j++)
	{
	  int *vect_curent=va_arg(va,int*);
	  int size_curent=va_arg(va,int);

	  int ok=0;

	  for(int k=0;k<size_curent;k++)
	    {
	      if(val_curenta==vect_curent[k])
		{
		  ok=1;
		  break;
		}
	    }
	  if(ok==0)
	    break;
	}

      if(j==nVec)
	c++;
      

    }

  return c;
  va_end(va);

  
}
void sortare(int n, ...)
{
  va_list va;
  va_start(va,n);
  int *v=va_arg(va,int*);
  for(int i=0;i<n;i++)
    {
      scanf("%d",&v[i]);
    }
  for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
	{
	  if(v[i]>v[j])
	    {
	      int aux=v[i];
	      v[i]=v[j];
	      v[j]=aux;
	    }
	}
    }

  for(int i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
  va_end(va);
}
int main()
{
  /*double *v=NULL;
  v=allocVec(NR,7.2,-1.0,0.0);
  for(int i=0;i<NR;i++)
    {
      printf("%.1f ",v[i]);
    }
  free(v);
  
  double x=-5.8,y=-9.6;
  printf("x initial: %.1f\n", x);
  printf("y initial: %.1f\n", y);
  absN(2,&x,&y);
  printf("x final: %.1f\n", x);
  printf("y final: %.1f\n", y);
   */
  //printf("%d ",crescator(NR,'d',9,7,2));
  /* int n;
  char ch;
  input("n=%dch=%c",&n,&ch);
  printf("n=%dch=%c\n",n,ch);
  
  char *str=NULL;
  str=concat(5,"Ion","si","Ana","si","Mark");
  printf("%s",concat(5,"Ion","si","Ana","si","Mark"));
  free(str);

  int v1[]={5,8},v2[]={8,3,5},v3[]={5,0,8},x;
  x=comune(3,v1,2,v2,3,v3,3);
  printf("nr=%d\n", x);*/

  int i,k,j;
  sortare(3,&i,&j,&k);
  return 0;
}
