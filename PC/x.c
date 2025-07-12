#include<stdio.h>

int func(int x)
{
  return x=x+1;
}
int main()
{
  int x=1;
  printf("%d",func(x));
  return 0;
  

}
