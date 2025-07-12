#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 150
typedef struct
{
  char text[MAX];
  int rand;
}TEXT;

TEXT v[MAX];//un vector de structuri
int top=-1;
void push(char *sir,int index)
{
  if(top==MAX-1)
    {
      printf("Stiva e plica\n");
      return ;
    }
  strcpy(v[++top].text,sir);
  v[top].rand=index;

}
void pop()//undo
{
  if(top==-1)
    {
      printf("Stiva e goala\n");
      return;
    }
  printf("%s\n",v[--top].text);
}
void display()
{
  if(top==-1)
    {
      printf("Stiva este goala\n");
      return;
    }
  for(int i=top;i>=0;i--)
    {
      printf("%s %d\n",v[i].text,v[i].rand);
      printf("\n");
    }

}

typedef struct
{
  char mesaj[257];
  int transmitator;
} txt;

txt buffer[MAX];
int inceput=-1,final=-1;

void adaugare(char *str,int nr)
{
  if(final==MAX-1)
    {
      printf("Coada e plina\n");
      return ;
    }
  if(inceput==-1)
    inceput=0;
  strcpy(buffer[++final].mesaj,str);
  buffer[final].transmitator=nr;
}
txt stergere()
{
  if(inceput==-1 || inceput>final)
    {
      printf("Coada e goala\n");
      txt aux={"",0};
      return aux;
    }
  return buffer[inceput++];
}
void display_buf()
{
  if(inceput==-1||inceput>final)
    {
      printf("buffer gol\n");
      return ;
    }
  for(int i=inceput;i<=final;i++)
    {
      printf("%s %d\n",buffer[i].mesaj,buffer[i].transmitator);
    }
  printf("\n");

}
 int main()
{
  push("ma",0);
  push("ma duc",1);
  push("ma duc la",2);
  push("ma duc la magazin",3);
  display();
  printf("%s\n",v[top].text);
  pop();


  adaugare("mesaj1",0);
  adaugare("mesaj2",1);
  adaugare("mesaj3",2);
  adaugare("mesaj4",3);
  display_buf();
  txt aux=stergere();
  printf("informatia este eliminata din coada:%s %d\n",aux.mesaj,aux.transmitator);
  display_buf();

  return 0;
}



