/*Aplicația 9.3: Se considera o lista liniara simplu inlantuita care memoreaza valori intregi. Sa se scrie o functie care
primeste ca parametru adresa primului nod al listei si insereaza dupa fiecare nod care memoreaza o valoare para
un nod care sa memoreze jumatate din valoare acestuia.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    int elem;
    struct LIST *next; 
} LIST;

LIST *creare_nod(LIST *next, int elem) {
    LIST *aux = NULL;
    aux = (LIST*)malloc(sizeof(LIST));
    if (aux == NULL) {
        perror(NULL);
        exit(-1);
    }
    aux->elem = elem;
    aux->next = next;
    return aux;
}

LIST *inserare_inceput(LIST *lista, int elem) {
    return creare_nod(lista, elem);
}

LIST *inserare_sfarsit(LIST *lista, int elem) {
    LIST *p = NULL, *aux = creare_nod(NULL, elem);
    if (lista == NULL)
        lista = aux;
    else {
        p = lista;
        while (p->next != NULL)
            p = p->next;
        p->next = aux;
    }
    return lista;
}
/*
LIST *inserare_mij(LIST *lista, int elem) {
    LIST *p = lista;
    while (p != NULL && p->elem != dupa) {
        p = p->next;
    }
    if (p == NULL)
        return lista;
    LIST *nou = creare_nod(p->next, elem);
    p->next = nou;
    return lista;
}
*/
void afis(LIST *lista) {
    LIST *p = lista;
    while (p != NULL) {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n");
}

LIST *pb(LIST *lista) {
  LIST *p = lista,*copy=NULL;
    while (p != NULL) {
        if (p->elem % 2 == 0) 
	  copy = inserare_sfarsit(copy,p->elem/2);
           
        p = p->next;
    }
    LIST *q=copy;
    /*  while(p!=NULL && q!=NULL)
      {
	if(p->elem%2==0)
	  {  lista=inserare_mij(lista,q->elem);
	    q=q->next;
	  }
	p=p->next;
      }
    */

    LIST *tot=NULL;
    while(p!=NULL && q!=NULL)
      {
	if(p->elem%2==0)
	  {
	    tot=inserare_sfarsit(tot,p->elem);
	    tot=inserare_sfarsit(tot,q->elem);
	    q=q->next;
	  }
	tot=inserare_sfarsit(tot,p->elem);
	p=p->next;
      }
    lista=tot;
    return lista;

}

int main()
{
  LIST *list = NULL;//*altc=NULL;
    list = inserare_sfarsit(list, 4);
    list = inserare_sfarsit(list, 2);
    list = inserare_sfarsit(list, 6);
    list = inserare_sfarsit(list, 4);
    list = inserare_sfarsit(list, 5);
    list = inserare_sfarsit(list, 6);

    list= pb(list);
    afis(list);

    return 0;
}
