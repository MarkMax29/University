/*Subiect 8.1: Se citesc de la tastatură două numere n și m, n>=m. Pe urmă se citesc două matrici pătratice de
dimensiuni n, respectiv m, conținând numere întregi. Afișați toate pozitiile unde a doua matrice apare în prima
matrice. Afișarea se va face pe ecran sub forma unor perechi de forma (linie, coloană). Dacă a doua matrice nu
apare în prima matrice, se va afișa textul “Nu apare”.
Spre exemplu dacă se introduce:
5 3
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1
0 1 0 1 1
1 0 1 1 1
0 1 1
1 0 1
0 1 1
se va afișa pe ecran:
(0,1) (2,1)

*/

#include<stdio.h>
#include<stdlib.h>

void eliberare(int **a,int n)
{
  for(int i=0;i<n;i++)
    free(a[i]);
  free(a);
}
void pb()
{
  int n,m,i,j,ok=0;
  printf("Introduceti nr de elem pt matricea 1. :");scanf("%d",&n);
  printf("Introduceti nr de elem pt matricea 2. :");scanf("%d",&m);
  ///ALOCAREA DINAMICA PT CELE 2 MATRICI
  int **a=NULL,**b=NULL;
  a=(int**)malloc(n*sizeof(int*));
  if(a==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(i=0;i<n;i++)
    {
      a[i]=(int*)malloc(n*sizeof(int));
      if(a[i]==NULL)
	{
	  for(i--;i>=0;i--)
	    free(a[i]);
	  free(a);
	  perror(NULL);
	  exit(-1);
	}
    }
  ///CITESC MATRICEA A 
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       scanf("%d",&a[i][j]);
   
   b=(int**)malloc(m*sizeof(int*));
   if(b==NULL)
     {
       perror(NULL);
       exit(-1);
     }
   for(j=0;j<m;j++)
     {
       b[j]=(int*)malloc(m*sizeof(int));
      if(b[j]==NULL)
	{
	  for(j--;j>=0;j--)
	    free(b[j]);
	  free(b);
	  perror(NULL);
	  exit(-1);
	}
     }
   ///SE TERMINA AICI ALOCAREA

   ///CITIREA MATRICEAI B
   for(i=0;i<m;i++)
     for(j=0;j<m;j++)
       scanf("%d",&b[i][j]);
   
    
   for(i=0;i<=n-m;i++)
     {
       for(j=0;j<=n-m;j++)
	 {
	   ok=1;
	   for(int k=0;k<m;k++)
	     {
	       for(int l=0;l<m;l++)
		 {
		   if(a[i+k][j+l]!=b[k][l])
		     {
		       ok=0;
		       break;
		     }
		 }
	       if (!ok)
		 break;
	     }
	   if(ok)
	     {
	       printf("(%d, %d) ",i,j);
	       ok=1;
	     }
	 }
     }
   if(ok!=0)
     printf("nu apare");   
	    
   eliberare(a,n);
   eliberare(b,m);
  
	      

}
int main()
{
  pb();
  return 0;
}
