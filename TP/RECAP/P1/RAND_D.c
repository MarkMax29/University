#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*Se citesc din fișierul text nr.txt un număr natural n și apoi n litere.
a) Să se creeze lista simplu înlănțuită ordonată care să rețină literele în ordine alfabetică. Se va folosi doar o
funcție de adaugare de elemente noi în listă în ordine.
b) Să se scrie o funcție care primește o listă simplu înlănțuită de litere și schimbă ordinea a două elemente care
sunt consecutive doar dacă primul e vocală și al doilea e consoană, altfel le lasă în ordinea găsită. Să se
aplice această funcție pe lista creată la punctul a) de atâtea ori până lista rezultată este aceeași cu lista primită ca
parametru (nu se mai modifică lista prin aplicarea funcției).
Exemplu: intrare: 7 e f c a d b i
a) Lista inițială în ordine alfabetică: a b c d e f i
b) iteratia 1: b a c d f e i
iteratia 2: b c a d f e i
iteratia 3: b c d a f e i
iteratia 4: b c d f a e i
iteratia 5: b c d f a e i (e la fel lista ca si la iteratia 4, ne oprim si afisam lista finala
*/
typedef struct LIST{
  char elem;
  struct LIST *next;
}LIST;

LIST *creare_nod(LIST *next,char elem)
{
  LIST *aux=NULL;
  aux=(LIST*)malloc(sizeof(LIST));
  if(aux==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  aux->elem=elem;
  aux->next=next;
  return aux;
}

LIST *inserare_sfarsit(LIST *lista,char elem)
{
  LIST *aux=creare_nod(NULL,elem);
  if(lista==NULL)
    lista=aux;
  else
    {
      LIST *p=lista;
      while(p->next!=NULL)
	{
	  p=p->next;
	}
      p->next=aux;
    }
  return lista;
	
}

void afisare(LIST *lista)
{
  LIST *p=lista;
  while(p!=NULL)
    {
      printf("%c ",p->elem);
      p=p->next;
    }
}
void eliberare(LIST *lista)
{
  LIST *aux=NULL;
  while(lista!=NULL)
    {
      aux=lista->next;
      free(lista);
      lista=aux;
    }

}
int cmp(const void *e1,const void *e2)
{
  const char *elem1=(const char*)e1;
  const char *elem2=(const char*)e2;
  if(*elem1>*elem2)
    return 1;
  else if(*elem2>*elem1)
    return -1;
  return 0;

}
LIST *inversare(LIST *lista)
{
  LIST *lista1=lista,*lista2=NULL;
  LIST *p=lista1;
  while(p!=NULL )
    {
      if(p->next !=NULL && strchr("aeiou",p->elem) && !(strchr("aeiou",p->next->elem)))
	{
	  lista2=inserare_sfarsit(lista2,p->next->elem);
	  lista2=inserare_sfarsit(lista2,p->elem);
	  p=p->next->next;
	}
      else
	{
	  lista2=inserare_sfarsit(lista2,p->elem);
	  p=p->next;
	}
    }
  return lista2;
  

}
int comparare_liste(LIST *lista1,LIST *lista2)
{
  while(lista1!=NULL && lista2!=NULL)
    {
      if(lista1->elem!=lista2->elem)
	return 0;
      lista1=lista1->next;
      lista2=lista2->next;
    }
  return (lista1 == NULL && lista2 == NULL);
}

 
void pb()
{
  FILE *f=NULL;
  f=fopen("litere.txt","r");
  if(f==NULL)
    {
      perror(NULL);
      exit(-2);
    }
  int n,i=0;
  char ch;
  fscanf(f,"%d",&n);
  char v[n];
  while(i!=n)
    {
      fscanf(f,"%c",&ch);
      if(isalpha(ch))
	{
	  v[i]=ch;
	  i++;
	}
    }
  qsort(v,n,sizeof(char),cmp);
  LIST *lista=NULL;
  for(int i=0;i<n;i++)
    {
      lista=inserare_sfarsit(lista,v[i]);
    }
  afisare(lista);
  printf("\n");
  LIST *lista1=NULL,*lista2=NULL;
  int j=1;
  lista1=lista;
  // afisare(lista1);
  
 while (1) {
        lista2 = inversare(lista1);
        printf("Iterația %d: ", j);
        afisare(lista2);
	printf("\n");
        if (comparare_liste(lista1, lista2)) {
            eliberare(lista1);
            break;
        }
        eliberare(lista1);
        lista1 = lista2;
        j++;
    }
}

int main()
{
  pb();
  return 0;
}
