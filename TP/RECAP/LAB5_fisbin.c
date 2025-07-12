/*Aplicația 5.3: Se citesc m și n din fisier text, iar apoi o matrice a[m][n] cu elemente de tip întreg. Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele, așa cum sunt dispuse ele în memorie. Să se citească matricea din fișier într-o variabilă b și să se afișeze.*/
#include<stdio.h>
#include<stdlib.h>
void pb5_3()
{
  FILE *f=NULL;
  f=fopen("matrice.txt","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  int m,n;
  //printf("m=");
  fscanf(f,"%d",&m);
  //printf("n=");
  fscanf(f,"%d",&n);
  int a[m][n];
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      fscanf(f,"%d",&a[i][j]);

  FILE *g=NULL;
  g=fopen("scriere.bin","wb");
  if(g==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  char buffer[1];
  //buffer[0]=32;//pentru a pune spatiu in fisier binar
  fwrite(&m,sizeof(int),1,g);
  //fwrite(buffer,sizeof(buffer),1,g);
  fwrite(&n,sizeof(int),1,g);
  //buffer[0]=10;//pentru a pune new line in fisier binar
  //fwrite(buffer,sizeof(buffer),1,g);
  
  // buffer[0]=32;
  //printf("%d %d\n",m,n);
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  fwrite(&a[i][j],sizeof(int),1,g);
	  //printf("%d ",a[i][j]);
	  //  fwrite(buffer,sizeof(buffer),1,g);
	}
      // printf("\n");
      // buffer[0]=10;
      // fwrite(buffer,sizeof(buffer),1,g);
    }
  fclose(g);
  if((g=fopen("scriere.bin","rb"))==NULL)
    {
      perror(NULL);
      exit(-1);
    }

  fread(&m,sizeof(int),1,g);
  fread(&n,sizeof(int),1,g);
  int b[m][n];
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  fread(&b[i][j],sizeof(int),1,g);
	}
    }
  printf("%d %d\n",m,n);
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%d ",b[i][j]);
	}
      printf("\n");
    }
  fclose(g);
  fclose(f);
  

}
int main()
{
  pb5_3();
  return 0;
}
