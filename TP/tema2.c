#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


///ex 2.1
/*typedef struct {
  int nota;
  char nume[30];
}student;
int conditie(const void *el1,const void *el2)
{
  student *elem1=(student *)el1;
  student *elem2=(student *)el2;
  if(elem1->nota > elem2->nota)
    return -1;
  if(elem1->nota == elem2->nota)
    {
      if(strcmp(elem1->nume,elem2->nume)<0)
	return -1;
      if(strcmp(elem1->nume,elem2->nume)<0)
	return 1;
      return 0;
    }
  return 1;
}
*/
void citire(float *v,int *size)
{
  float value;
  for(int i=0;i<*size;i++)
    {
      scanf("%f",&value);
      *(v+i)=value;
    }
}
void afisare(float *v,int size)
{
  float value;
  for(int i=0;i<size;i++)
    {
      value=*(v+i);
      printf("%.1f ",value);
    }
}
///exercitiul 2.2
int negativ(int el)
{
  return el<0;
}
void stergere(int *v,int *size,int(*conditie)(int))
{
  for(int i=0;i<*size;i++)
    {
      if(conditie(v[i])==1)
	{
	  for(int j=i+1;j<*size;j++)
	    {
	      v[j-1]=v[j];
	    }
	  *size=*size-1;
	  
	}
    }
}
///exercitiul 2.3
int cond(const void *a,const void *b)
{
  float *elem1=(float *) a;
  float *elem2=(float *) b;
  if(*elem1>*elem2)
    return 1;
  if(*elem1==*elem2)
    return 0;
  return -1;
}
/*  
///exercitiul 2.4??? nu iese

// Funcție pentru tabelare
void tabelare(double a, double b, int n, double (*f)(double)) {
    double step = (b - a) / n; // Calculează lungimea fiecărui segment
    double x = a;
    for (int i = 0; i <= n; ++i) {
        printf("f(%.2f)=%.2f\n", x, f(x));
        x += step; // Avansăm la următorul punct din interval
    }
}

double wrapper_fabs(double x) {
    return fabs(x);
}
double *wrapper_cos(double x)
{
  return cos(x);
}
double wrapper_sqrt(double x)
{
  return sqrt(x);
  }*/

/// exercitiul 2.1-examen
int f1(int x)
{
  return (x*x*x)+4;
}
int f2(int x)
{
  return (x*x)+5;
}
int f3(int x)
{
  return x+10;
}
int f4(int x)
{
  return (2*(x*x))-1;
}



/// exercitiul 2.2-examen

int fc1(char *s)
{
  return strlen(s);
}
int fc2(char *s)
{
  int c=0;
  for(int i=0;i<strlen(s);i++)
    {
      if(strchr("AEIOUaeiou",s[i]))
	 c++;
	 
    }
  return c;
}
int fc3(char *s)
{
  int c=0;
  for(int i=0;i<strlen(s);i++)
    if(isupper(s[i]))
       c++;
 return c;
 }
       
int fc4(char *s)
{
  return (int)s[0]-(int)s[strlen(s)-1];
}

       
int main(int argc, char **argv)
{//ex 2.1
  /*int n;
  scanf("%d",&n);
  student s[n];
  for(int i=0;i<n;i++)
    {
      scanf("%s %d",s[i].nume,&s[i].nota);
    }
  qsort(s,n,sizeof(student),conditie);
  for(int i=0;i<n;i++)
    {
      printf("%s %d\n",s[i].nume,s[i].nota);
    }
  */
  //exercitiul 2.2
  /* { int n,v[100];
  scanf("%d",&n);
  citire(v,&n);
  stergere(v,&n,negativ);
  afisare(v,n);
  }*/

  //exercitiul 2.3
  /*  int n;
  float v[100],x;
  scanf ("%d",&n);
  citire(v,&n);
  qsort(v,n,sizeof(float),cond);
  afisare(v,n);
  printf("\n");
  scanf("%f",&x);
  float *ptr=(float*)bsearch(&x,v,n,sizeof(float),cond);
  if(ptr!=NULL)
    printf("S-a gasit x=%.1f si este la adresa %p",*ptr,ptr);
  else
    printf("Nu s-a gasit");

  
//ex2.4???
  double a, b;
    int n;

    printf("Introduceti capatul stang al intervalului: ");
    scanf("%lf", &a);

    printf("Introduceti capatul drept al intervalului: ");
    scanf("%lf", &b);

    printf("Introduceti numarul de segmente: ");
    scanf("%d", &n);

     printf("\nTabelare pentru functia cos:\n");
     tabelare(a, b, n,wrapper_cos(a));

    printf("\nTabelare pentru functia sqrt:\n");
    tabelare(a, b, n,wrapper_sqrt(a));
    
    printf("\nTabelare pentru functia fabs:\n");
     tabelare(a, b, n, wrapper_fabs);

  */

  ///exercitiul 2.1
  /*
  int (*vf[4])(int);
  vf[0]=f1;
  vf[1]=f2;
  vf[2]=f3;
  vf[3]=f4;
  int a,b,p,j=0,v[10];
  scanf("%d %d %d",&a, &b, &p);
  // int nr=(b-a)/p+1;
  for(int i=a;i<=b;i=i+p)
    {
      v[j]=i;
      printf("%4d ",v[j]);
      j++;
    }
  printf("\n");
  for(int i=0;i<4;i++)
    {
      for(int k=0;k<j;k++)
	{
	  printf("%4d ",vf[i](v[k]));
	  
	}
      printf("\n");
    }
  */

  ///exercitiul 2.2
    
  int (*f[4])(char*);
  f[0]=fc1;
  f[1]=fc2;
  f[2]=fc3;
  f[3]=fc4;
  FILE *out;
  out=fopen("out.txt","w");
  if(out==NULL)
    {printf("eroare");
      exit(-1);
    }
  for(int i=1;i<argc;i++)
    {
      printf("%s",argv[i]);
      fprintf(out,"%s ",argv[i]);
    }
  printf("\n");
  fprintf(out,"\n");
  for(int i=0;i<4;i++)
    {
      for(int j=1;j<argc;j++)
	{
	  printf("%d ",f[i](argv[j]));
	  fprintf(out,"%d ",f[i](argv[j]));
	}
      printf("\n");
      fprintf(out,"\n");
    }
  
  fclose(out);
  return 0;
}
