#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define MAX 5
#define SIZE1 3
#define SIZE2 4
#define SIZE3 2
#define PERSOANE 10
#define INF 999999
#define ORAS 10
void ex8_3()
{
  int n,m,k=1;
  printf("Numarul de linii : ");
  scanf("%d",&m);
  printf("Numarul de coloane: ");
  scanf("%d",&n);
  int v[10][20];
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  *(&v[0][0]+i*20+j)=k;
	  k++;
	}
    }
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%3d",*(&v[0][0]+i*20+j));
	}
      printf("\n");
    }

}
void ex8_4()
{
 int n,aux=0,v[50][50];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        {
	  scanf("%d",&v[i][j]);
	}
    }
  for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
	{
	      aux=v[i][j];
	      v[i][j]=v[j][i];
	      v[j][i]=aux;	   
	}
    }
   for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  printf("%3d",v[i][j]);
	}
      printf("\n");
      }

}
void ex8_5()
{
  int l=0,c=0;
  int sl[SIZE],sc[SIZE],a[SIZE][SIZE];
  for(int i=0;i<SIZE;i++)
    {
      for(int j=0;j<SIZE;j++)
	{
	  scanf("%d",&a[i][j]);
       	}
    }
  for(int i=0;i<SIZE;i++)
    {
      for(int j=0;j<SIZE;j++)
	{
	  *(sl+l)=*(sl+l)+*(&a[0][0]+i*SIZE+j);
	}
      l++;
    }
  for(int j=0;j<SIZE;j++)
    {
      for(int i=0;i<SIZE;i++)
	{
	  *(sc+c)=*(sc+c)+*(&a[0][0]+i*SIZE+j);
	}
      c++;
    }
  printf("Vectorul cu suma elementelor pe linie: ");
  for(int i=0;i<l;i++)
    {
      printf("%d ",*(sl+i));
    }
  printf("\n");
  printf("Vectorul cu suma elementelor pe coloana: ");
  for(int i=0;i<c;i++)
    {
      printf("%d ",*(sc+i));
    }

}
void ex8_6()
{
  int n;
  int prieteni[PERSOANE][PERSOANE];
  //citesc numarul de persoane 
  printf("Introdu numarul de persoane (n <= %d): ",PERSOANE);
  scanf("%d",&n);

  for(int i=0;i<n;i++)
    {
      //citesc pentru fiecare persoana numarul de prieteni
      printf("Introdu numarul de prienteni pentru persoane %d: ",i);
      int nr_prieteni;
      scanf("%d",&nr_prieteni);

      printf("Introdu prietenii persoanei %d:\n",i);
      for(int j=0;j<nr_prieteni;j++)
	{
	  int index_prieten;
	  scanf("%d",&index_prieten);
	  prieteni[i][index_prieten]=1;
	}
    }
  printf("Numarul de prieteni pentru fiecare persoana:\n");
  for(int i=0;i<n;i++)
    {
      int nr_prieteni=0;
      for(int j=0;j<n;j++)
	{
	  nr_prieteni=nr_prieteni+prieteni[i][j];
	}
       printf("Persoana %d: %d prieteni\n", i, nr_prieteni);
    }
  
}

void ex8_7()
{
  int n,dist_minim=INF,distanta[ORAS][ORAS],oras1=0,oras2=0;
  printf("Introdu numarul de orase (n <= %d): ", ORAS);
  scanf("%d", &n);

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  scanf("%d",&distanta[i][j]);
	}
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  if(distanta[i][j]!=0 && distanta[i][j]<dist_minim)
	    {
	      dist_minim=distanta[i][j];
	      oras1=i;
	      oras2=j;
	    }
	}
    }
  if(dist_minim !=INF)
      printf("Cele mai apropiate orase sunt %d si %d, cu distanta %d\n",oras1,oras2,dist_minim);
  else
    printf("Nu exista drum direct intre orase\n");
     
}
void ex8_8()
{
  int m,n,p;
  int a[SIZE1][SIZE2],b[SIZE2][SIZE3],c[SIZE1][SIZE3];
  printf("Introduceti m:");
  scanf("%d",&m);
  printf("Introduceti n:");
  scanf("%d",&n);
  printf("Introduceti p:");
  scanf("%d",&p);
  printf("Introduceti matricea a:\n");
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }
   printf("Introduceti matricea b:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<p;j++)
	{
	  scanf("%d",&b[i][j]);
	}
    }
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<p;j++)
	{
	  c[i][j]=0;
	}
    }
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<p;j++)
	{
	  for(int k=0;k<n;k++)
	    {
	      c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
	    }
	}
    }
  printf("Matricea c este:\n");
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<p;j++)
	{
	  printf("%d ",c[i][j]);
	}
      printf("\n");
    }
    
}
void ex8_1()
{
  int n,m,a[SIZE][SIZE],x[MAX][MAX],ok=0;
  printf("Introdu numarul de elemente pt a: ");
  scanf("%d",&n);
  printf("Introdu numarul de elemente pt x: ");
  scanf("%d",&m);

  printf("Introdu matricea a:\n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }
  printf("Introdu matricea x:\n");
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<m;j++)
	{
	  scanf("%d",&x[i][j]);
	}
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	{
	   ok=1;
	  for(int k=0;k<m;k++)
	    {
	      for(int l=0;l<m;l++)
		{
		  if(a[i+k][j+l]!=x[k][l])
		    {
		      ok=0;
		      break;
		    }
		}   
	    }
      if(ok)
	{
	  printf("(%d, %d)\n",i,j);
	  ok=1;
	}
    }
   }
  if(ok!=0)
    {
      printf("Nu apare\n");
    }
}
		     
int main()
{
  //ex8_3();
  // ex8_4();
  // ex8_5();
  //ex8_6();
  //ex8_7();
  // ex8_8();
  ex8_1();
  return 0;
}
