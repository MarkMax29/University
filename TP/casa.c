#include <stdio.h>
void container (int lat,int lung)
{
  for(int i=1;i<=lat;i++)
    {
      for(int j=1;j<=lung;j++)
	{
	  if(i==1 || i==lat || j==1 || j==lung)
	    printf("*");
	  else
	    printf(" ");
	}
      printf("\n");
    }
   printf("\n");
}
void acoperis(int inalt,int lung)
{
  for(int i=1;i<=inalt;i++)
    {
      for(int j=1;j<=lung;j++)
	{
	  if(i+j==lung/2+1)
	    printf("/");
	  else if(j-i==lung/2)
	    printf("\\");
	  else
	    printf(" ");
	}
      printf("\n");
    }
}
int main (void)
{
   acoperis(7,15);
   container(6,15);
  
  return 0;
}
