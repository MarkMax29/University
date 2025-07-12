/*Subiect 8.2: Se citesc de la tastatură un număr n și o matrice pătratică de dimensiune n conținând litere din
alfabet. Pe urmă se citește de la tastatură un cuvânt. Verificați dacă respectivul cuvânt se poate construi
parcurgând literele matricii pe verticală în sus sau în jos sau pe orizontală spre stânga sau spre dreapta. Afișați
toate pozițiile de unde trebuie începută parcurgerea, precum și sensul de parcurgere necesar pentru a construi
cuvântul.
Spre exemplu, dacă de la tastatură se introduce:
5
e r e m a
h e r e b
b m e r e
b a m e r
a e m r e
mere
pe ecran se va afișa:
De la linia 0 coloana 3 spre stânga.
De la linia 0 coloana 3 în jos.
De la linia 2 coloana 1 spre dreapta.
De la linia 3 coloana 2 în sus.
Nu are importanță ordinea în care sunt afișate soluțiile găsite. Dacă nu există soluție, se afișează “Nu există
soluție”.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void eliberare(int **a,int n)
{
  for(int i=0;i<n;i++)
    free(a[i]);
  free(a);
}

void pb()
{
  int n,i,j,ok=0,st,dr,jos,sus,l;
  printf("Introdu numarul n: ");scanf("%d",&n);
  char **a=NULL;
  a=(char**)malloc(n*sizeof(char*));
  if(a==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  for(i=0;i<n;i++)
    {
      a[i]=(char*)malloc(n*sizeof(char));
      if(a[i]==NULL)
	{
	  for(i--;i>=0;i--)
	    free(a[i]);
	  free(a);
	  perror(NULL);
	  exit(-1);
	}
    }
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  scanf(" %c",&a[i][j]);
	}
    }
  char *sir=NULL;
  sir=(char*)malloc(sizeof(char*));
  if(sir==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  scanf("%s",sir);
  for(i=0;i<n;i++)
    {
     
      for(j=0,l=n-1;j<=n-strlen(sir) && l>=strlen(sir)-1;j++,l--)
	{
	  dr=1;
	  st=1;
	  jos=1;
	  sus=1;
	  for(int k=0;k<strlen(sir);k++)
	    {
	      //printf("%c ",a[i][l-k]);
	      if(a[i][j+k]!=sir[k])
		dr=0;
	      
	      if(a[i][l-k]!=sir[k])
		st=0;
	      if(a[j+k][i]!=sir[k])
		jos=0;
	      if(a[l-k][i]!=sir[k])
		sus=0;
		    
	    }
	   if(dr==1)
	    {
	      printf("De la linia %d la coloana %d spre dreapta\n",i,j);
	      ok=1;
	      }
	   if(st==1)
	    {
	      printf("De la linia %d la coloana %d spre stanga\n",i,l);
	      ok=1;
	      }
	   if(jos==1)
	     {
	       printf("De la linia %d la coloana %d in jos\n",j,i);
	       ok=1;
	     }
	   if(sus==1)
	     {
	       printf("De la linia %d la coloana %d in sus\n",l,i);
	       ok=1;
	     }
	}
    }

  if(ok!=1)
    printf("nu exista\n");	  

}
int main()
{
  pb();
  return 0;
}
