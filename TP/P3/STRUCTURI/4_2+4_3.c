/*Aplicația 4.2: Cu ajutorul structurii de la problema mai sus să se salveze într-un vector de structuri declarat static
informații despre mai multe fișiere (maxim 10). Să se citească de la tastatură informațiile despre fișiere și să se
salveze în fișierul memorie.txt.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct FISIER{

  unsigned int dim:10;
  unsigned int tip:2;
  unsigned int tfis:1;
  char nume[16];
}FISIER;

int main()
{
  int dim,tip,tfis,i=0;
  FISIER *v=NULL;
  v=(FISIER *)malloc(sizeof(FISIER));
  if(v==NULL)
    {
      perror(NULL);
      exit(-1);
      }
  FILE *f=NULL;
  f=fopen("memorie.txt","w");
  if(f==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  while((scanf("%s %d %d %d",v[i].nume,&dim,&tip,&tfis))==4 && i!=10)
    {
      v[i].dim=dim;
      v[i].tip=tip;
      v[i].tfis=tfis;
      i++;
      v=realloc(v,(i+1)*sizeof(FISIER));
      if(v==NULL)
	{
	  perror(NULL);
	  exit(-1);
	}
    }
  for(int j=0;j<i;j++)
    {
      fprintf(f,"nume:%s - dimesiune:%d - tip:%d - tip_fis:%d\n",v[j].nume,v[j].dim,v[j].tip,v[j].tfis);
    }
  free(v);
  fclose(f);
  return 0;
}
