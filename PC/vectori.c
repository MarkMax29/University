#include<stdio.h>
#include<stdint.h>
#define MAX 100
void citire(int *v,int size)
{
  for(int i=0;i<=size-1;i++)
    scanf("%d",&v[i]);
   
}
void afisare(int *v,int size)
{
  for(int i=0;i<=size-1;i++)
    printf("%d ",v[i]);
}
void EX2_minim(int *v,int size,int minim)
{
  minim=9999999;
  for(int i=0;i<=size-1;i++)
    {
      if(v[i]<minim)
	minim=v[i];
    }
  printf("%d",minim);
}
void EX3_pare(int *v,int size)
{
  int ok=1;
  for(int i=0;i<=size-1 && ok==1;i++)
    {
      if(v[i]>0 && v[i]%2!=0)
	ok=0;
    }
  if(ok==1)
    {
      afisare(v,size);
    }
  else
    {
      printf("Nu sunt toate pare");

    }
}

void EX4_nrk(int *v,int size,int k)
{
  int ok=0;
  for(int i=0;i<=size-1 && ok==0;i++)
    {
      if(v[i]>k)
	ok=1;
    }
  if(ok==1)
    printf("Exista cel putin un numar >k\n");
  else
    printf("Nu exista niciun numar >k\n");
}
void EX5_miniinterval(int*v,int size,int x,int y)
{
  int minim=9999999,ok=0;
  for(int i=0;i<=size-1;i++)
    {
      if(v[i]>=x && v[i]<=y)
	{
	  ok=1;
	  if(v[i]<minim)
	    minim=v[i];
	}	
    }
  if(ok==0)
    printf("Nu exista numere care sa fie din interval");
  else
    printf("%d\n",minim);
}
void EX6_valabs(int *v,int size)
{ int ok=0;
  for(int i=0;i<=size-1;i++)
    {
      if(v[i]<0)
	{
	  if(-v[i]>10)
	    {   printf("%d ",v[i]);
	      ok=1;}
	}
      else
	{
	  if(v[i]>10)
	    {printf("%d ",v[i]);
	      ok=1;}
	}
    }
  if(ok==0)
    printf("Nu exista valori absolute mai mari ca 10");
}
void EX7_sortare(int *a,int size)
{
  int aux=0;
  for(int i=0;i<size-1;i++)
    {
      for(int j=i+1;j<size;j++)
	{
	  if(a[i]%2==0 && a[j]%2!=0)
	    {
	      aux=a[i];
	      a[i]=a[j];
	      a[j]=aux;
	    }
	}
    }
  afisare(a,size);
  
}
void EX8_stergere(int *v,int size)
{
  for(int i=0;i<size;i++)
    {
      if(v[i]<v[i+1])
	{
	  for(int j=i+1;j<size;j++)
	    {
	      v[j-1]=v[j];
	    }
	   size--;
	   i--;
	}
    }
  afisare(v,size);

}

void EX9_inserare(int *v,int size)
{
  for(int i=size-1;i>=0;i--)
   {
    if(v[i]%2!=0)
      {
	size++;
	for(int j=size-2;j>=i;j--)
	  {
	    v[j+1]=v[j];
	  }
	v[i]=0;
      }
  }
  afisare(v,size);
 

}

void EX10_sortare(int *a,int size)
{
  int aux=0;
  for(int i=0;i<size-1;i++)
    {
      for(int j=i+1;j<size;j++)
	{
	  if(a[i]<0 && a[j]>0)
	    {
	      aux=a[i];
	      a[i]=a[j];
	      a[j]=aux;
	    }
	}
    }
  afisare(a,size);
  
}
int main()
{
  int minim=9999999,v[MAX],n=0,k=0,x=0,y=0,a[MAX],h[MAX];
  /*
  //exercitiul 2
  printf("Numarul de elemente (<=%d):",MAX);
  scanf("%d",&n);
  printf("Elemenetele vectorului:");citire(v,n);
  printf("Minimul:");EX2_minim(v,n,minim);
  printf("\n");

  //exercitiul 3
  EX3_pare(v,n);

  //exercitiul 4
  printf("\nIntroduceti k: ");
  scanf("%d",&k);
  EX4_nrk(v,n,k);

  //exercitiul 5
  printf("Introduceti x:");
  scanf("%d",&x);
  printf("Introduceti y:");
  scanf("%d",&y);
  printf("Minimul din interval este:");
  EX5_miniinterval(v,n,x,y);

  //exercitiul 6
  printf("Valorile absolute sunt:");
  EX6_valabs(v,n);
  printf("\n");

  //exercitiul 8
  printf("Dupa stergere: ");
  EX8_stergere(v,n);
  printf("\n");
  
  //exercitiul 7
  printf("Numarul de elemente (<=%d):",MAX);
  scanf("%d",&n);
  printf("Elemenetele vectorului:");citire(a,n);
  printf("Dupa sortare: ");
  EX7_sortare(a,n); 
  printf("\n");

  //exercitiul 9

  printf("Dupa inserare: ");
  EX9_inserare(a,n);
  printf("\n");
  */
  //exercitiul 10

  printf("Numarul de elemente (<=%d):",MAX);
  scanf("%d",&n);
  printf("Elemenetele vectorului:");citire(h,n);
  printf("Dupa sortare ex10: ");
  EX10_sortare(h,n);
  printf("\n");
 
 return 0;
}
