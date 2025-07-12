#include<stdio.h>
#include<stdlib.h>
//11.1: Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan. Fiecare punct reprezintă
//poziția unde va trebui dată o gaură într-o placă. Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de
//dat găuri, astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea.

///SE REZOLVA CU GREEDY
/*
int origine[2][1];

int comparare (const void *a,const void *b)//pt sortarea a 2 pct 
{
  int x1,y1,x2,y2,dist1,dist2;
  x1=((int *)a)[0];
  y1=((int *)a)[1];
  x2=((int *)b)[0];
  y2=((int *)b)[1];
  dist1=(x1-origine[0][0])*(x1-origine[0][0])+(y1-origine[1][0])*(y1-origine[1][0]);//distanta dintre a si origine
  dist2=(x2 - origine[0][0]) * (x2 - origine[0][0]) + (y2 - origine[1][0]) * (y2 - origine[1][0]);
  if(dist1>dist2)
    return dist1-dist2;
  return dist2-dist1;
 
}

void p1()
{
  int n,coordonate[2][100];
  scanf("%d",&n);//citesc n puncte
  for(int i=0;i<n;i++)
    {
      scanf("%d %d",&coordonate[0][i],&coordonate[1][i]);//citesc pt fiecare punct x,y
    }
  qsort(coordonate,n,2*sizeof(int),comparare);
  for(int i=0;i<n;i++)
    {
      printf("%lf %lf\n",coordonate[0][i],coordonate[1][i]);
    }
  
}
*/
///11.4 La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int).
//Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor, astfel
//încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și ei în
//grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe, pentru
//valori citite dintr-un fișier.

//SE REZOLVA CU GREEDY
typedef struct
{
  char nume[16];
  int valoare;
}Jucator;

int comparareJucatori(const void *a,const void *b)
{
  Jucator *jucator1=(Jucator *)a;
  Jucator *jucator2=(Jucator *)b;
    return jucator1->valoare - jucator2->valoare;
  
}

void p4()
{
  int n,m,count=0;
  Jucator *jucatori=NULL;
  scanf("%d %d",&n,&m);
  jucatori=malloc(sizeof(Jucator)*n);
  if(jucatori==NULL)
    {
      printf("eroare la alocare");
      exit(-1);
    }
  for(int i=0;i<n;i++)
    {
      scanf("%15s %d",jucatori[i].nume,&jucatori[i].valoare);
    }
  qsort(jucatori,n,sizeof(Jucator),comparareJucatori);
  for(int i=n-1;i>=0;i--)
    {
      if(count==n/m)
	{
	  printf("\n");
	  count=0;
	}
      printf("%s %d\n",jucatori[i].nume,jucatori[i].valoare);
      count++;
    }
}

int main()
{
  p4();
  return 0;
}
