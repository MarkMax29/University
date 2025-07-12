#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
  uint16_t picioare:10;
  uint16_t varsta:11;
  uint8_t pericol:1;
  float greutate;
  char abrv[9];
}ANIMAL;

typedef struct
{
  uint8_t val,um:2,mul:6;

}MASURATOARE;
void pb4_4()
{
  ANIMAL v[MAX];
  uint16_t auxpicioare,auxvarsta,n;
  uint8_t auxpericol;
  float auxgreutate;
  char auxabr[9];

  printf("Introduceti numarul de animale:");
  scanf("%hd",&n);
  for (int i=0;i<n;i++)
    {
      if(scanf("%hd %hd %hhd %f %8s",&auxpicioare,&auxvarsta,&auxpericol,&auxgreutate,auxabr)!=5)
	{
	  perror(NULL);
	  exit(-1);
	}
      v[i].picioare=auxpicioare;
      v[i].varsta=auxvarsta;
      v[i].pericol=auxpericol;
      v[i].greutate=auxgreutate;
      strcpy(v[i].abrv,auxabr);
    }
  for(int i=0;i<n;i++)
    {
      printf("picioare:%hd varsta:%hd pericol:%hhd greutate:%.3f abreviere:%s\n",v[i].picioare,v[i].varsta,v[i].pericol,v[i].greutate,v[i].abrv);
    }

}
void pb4_6()
{
  uint64_t x;
  uint8_t unit;
  printf("pico-0\nnano-1\nmili-2\ncenti-3\ndeci-4\ndeca-5\nhecto-6\nkilo-7\nmega-8\ngiga-9\n\ngram-0\nmetru-1\nlitru-2\n");
  if(scanf("%ld",&x)!=1)
    {
      perror(NULL);
      exit(-1);
    }
  printf("unitatea de masura:");
  if(scanf("%hhd",&unit)!=1 || unit>2)
    {
      perror(NULL);
      exit(-1);
    }
  MASURATOARE mas_x;
  mas_x.um=unit;
  mas_x.mul=0;
  while(x/10)
    {
      x=x/10;
      mas_x.mul=mas_x.mul+1;
      if(mas_x.mul>9)
	break;
      
    }
  if(x>999)
    printf("numarul e prea mare\n");
  else
    {mas_x.val=x;
      printf("%hhd\n",mas_x.mul);
      printf("valoare:%hhd ",mas_x.val);
      switch(mas_x.mul)
	{
	case 0:
	  {
	    printf("pico\n");
	    break;
	  }
	case 1:
	  {printf("nano\n");
	    break;
	      }
	case 2:
	  {
	    printf("mili\n");
	    break;
	  }
	case 3:
	  {
	    printf("centi\n");
	    break;
	  }
	case 4:
	  {
	    printf("deci\n");
	    break;
	  }
	case 5:
	  {
	    printf("default(metru/gram/litru)\n");
	    break;
	  }
	case 6:
	  {
	    printf("deca\n");
	    break;
	  }
	case 7:
	  {
	    printf("hecto\n");
	    break;
	  }
	case 8:
	  {
	    printf("kilo\n");
	    break;
	  }
	case 9:
	  {
	    printf("mega\n");
	    break;
	  }
	case 10:
	  {
	    printf("giga\n");
	    break;
	  }
	default :
	  break;
	}
      if( mas_x.um==0)
	{
	  printf("unitate de masura:gram\n");
	}
      else if(mas_x.um==1)
	{
	  printf("unitate de masura:metru\n");
	}
      else if(mas_x.um==2)
	{
	  printf("unitate de masura:litru\n");
	}
    }
}
	  
int main()
{
  //  pb4_4();
  pb4_6();
  return 0;
}
   
