#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<string.h>
#define MAX 4
int contor;
int *p0(int n,...)
{
  va_list p;
  va_start(p,n);
  int *vect=NULL,aux=0,ok=1,i=0;
  if((vect=malloc(n*sizeof(int)))==NULL)
    { perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {ok=1;
      aux=va_arg(p,int);
      for(int j=0;j<i;j++)
	{if(aux==vect[j])
	    ok=0;
	}
      if(ok)
	vect[contor++]=aux;
    }
  va_end(p);
  return vect;
}
void p6_3(int n,...)
{
  va_list p;
  va_start(p,n);
  double *adr=NULL;
  for(int i=0;i<n;i++)
    {
      adr=va_arg(p,double *);
      *adr=fabs(*adr);
    }
  va_end(p);
}
int p6_4(char tip,int n,...)
{
  va_list p;
  va_start(p,n);
  if(tip=='d')
    {
      int a=0,b=0;
      b=va_arg(p,int);
      for(int i=0;i<n-1;i++)
	{
	  a=va_arg(p,int);
	  if(b>=a)
	    return 0;
	  b=a;
	  
	}
      va_end(p);
      return 1;
    }
  else if(tip=='f')
    {
      double a=0.0,b=0.0;
      b=va_arg(p,double);
      for(int i=0;i<n-1;i++)
	{
	  a=va_arg(p,double);
	  if(b>=a)
	    return 0;
	  b=a;
	  
	}
      va_end(p);
      return 1;
    }
  else
    {
      perror("eroare tip");
      return -1;
    }
  
}
void p6_5(char *fmt,...)
{
  va_list p;  //(”n=%dch=%c”,&n,&ch)
  va_start(p,fmt);
  char aux[3]="aa",a=0,b=0,*ch=NULL;
  int *nr=NULL;
  double *k=NULL;
  b=fmt[0];
  if(b!='%')
    printf("%c",b);
  for(int i=1;i<strlen(fmt);i++)
    {
      a=fmt[i];
      aux[0]=b;
      aux[1]=a;
      aux[2]='\0';
      if(strcmp(aux,"%d")==0)
	{
	  
	  nr=va_arg(p,int*);
	  if(scanf("%d",nr)!=1)
	    {
	      perror("error int");
	      exit(-1);
	    }
	}
      else if(strcmp(aux,"%f")==0)
	{
	  k=va_arg(p,double*);
	  if(scanf("%lf",k)!=1)
	    {
	      perror("error double");
	      exit(-1);
	    }
	}
      else if(strcmp(aux,"%c")==0)
	{
	  ch=va_arg(p,char*);
	  if(scanf(" %c",ch)!=1)
	    {
	      perror("error char");
	      exit(-1);
	    }
	}
      else if(a!='%')
	printf("%c",a);
      b=a;
    }
  va_end(p);
}
char *p6_6(int n,...)
{
  va_list p;
  va_start(p,n);
  char *str=NULL,a[101]="";
  int size=0;
  if((str=malloc(n*101*sizeof(char)))==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      strcpy(a,va_arg(p,char *));
      strcat(str,a);
      strcat(str," ");
      size+=strlen(a)+1;
    }
  str[size-1]='\0';
  va_end(p);
  return str;
}
int p6_7(int n,...)
{
  va_list p;
  va_start(p,n);
  int **array=NULL;
  int *size=NULL;
  n=n/2;
  if((size=malloc(n*sizeof(int)))==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  if((array=malloc(n*sizeof(int *)))==NULL)
  {
    perror(NULL);
    exit(-1);
  }
  for(int i=0;i<n;i++)
    {
      array[i]=va_arg(p,int *);
      size[i]=va_arg(p,int);
    }
  int contor=0,frecv=1;
  for(int i=0;i<size[0];i++)
    {
      frecv=1;
      for(int j=1;j<n;j++)
	for(int k=0;k<size[j];k++)
	  {
	    if(array[0][i]==array[j][k])
	      {
		frecv++;
		break;
	      }
	  }
      if(frecv==n)
	contor++;
    }
  free(array);
  free(size);
  va_end(p);
  return contor;
}
void p6_8(int n,...)
{
  va_list p;
  va_start(p,n);
  int **a=NULL,aux=0;
  if((a=malloc(n*sizeof(int *)))==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(int i=0;i<n;i++)
    a[i]=va_arg(p,int *);
  for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
      if(*a[i]>*a[j])
	{
	  aux=*a[i];
	  *a[i]=*a[j];
	  *a[j]=aux;
	}
  free(a);
  va_end(p);
}
int main() 
{
  //p0
  int *array=NULL;
  array=p0(12,1,0,2,3,2,2,0,5,5,3,6,8);
  for(int i=0;i<contor;i++)
    {
      printf("%d ",array[i]);
    }
  printf("\n");
  free(array);
  //p6_3;
  double x=-2.0,y=-5.0;
  p6_3(2,&x,&y);
  printf("%.3f %.3f\n",x,y);
  //p6_4;
  int yu=p6_4('f',5,1.0,2.0,5.0,5.1,6.0);
  printf("%d\n",yu);
  //p6_5
  
  //in t n;
  //char ch;
  //double g;
  //p6_5("n=%dch=%cand the double is%f",&n,&ch,&g);
  //printf("%d %c %f\n",n,ch,g);
  
  //p6_6
  char *linie=p6_6(3,"Ana","are","visine");
  printf("%s\n",linie);
  free(linie);
  //p6_7
  int v1[4]={5,8,1,0},v2[4]={8,3,0,5},v3[3]={5,0,8};
  int nr_elem_comune=p6_7(6,v1,4,v2,4,v3,3);
  printf("p6_7:%d\n",nr_elem_comune);
  //p6_8
  int i=2,j=3,k=1,l=4,m=6,n=5;
  p6_8(6,&i,&j,&k,&l,&m,&n);
  printf("%d %d %d %d %d %d\n",i,j,k,l,m,n);
  return 0;
}
