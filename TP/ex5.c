typedef struct {
  unsigned int dim:11; 
  unsigned int tip_fis:2;
  unsigned int tip:1;
  char nume[16];
}FISIER;
void prob()
{
  int tip1,tip2,dimensiune,i=0,curent_size=0;
  char nume[16];
  FISIER *v=NULL;
  while(scanf("%15s %d %d %d",nume,&tip1,&tip2,&dimensiune)==4)
    {
      
      if(curent_size==i)
	{
	  curent_size=curent_size+MAX;
	  
	  v=(FISIER*)realloc(v,curent_size*sizeof(FISIER));
	  if(v==NULL)
	    {
	      printf("eroare la alocare");
	      exit(-1);
	    }
	 
	}
      strcpy(v[i].nume,nume);
      v[i].tip_fis=tip1;
      v[i].tip=tip2;
      v[i].dim=dimensiune;
      i++;
    }
  FILE *f=NULL;
  f=fopen("memorie.txt","w");
  if(f==NULL)
    {
      printf("nu s-a scris in fisier");
      exit(-1);
    }
  for(int j=0;j<i;j++)
    {
      fprintf(f,"%s - %d -",v[j].nume,v[j].dim);//afisez nume si dimensiune
      
      if(v[j].tip_fis==0) // afisez tipul fisierului 0,1,2 txt/doc/xls
	fprintf(f,".txt-");
      else
	if(v[j].tip_fis==1)
	  fprintf(f,".doc-");
	else
	  fprintf(f,".xls-");

      if(v[j].tip==0)  //afisez tipul 0,1 normal/read-only
	fprintf(f,"normal\n");
      else
	fprintf(f,"read-only\n");
      
	 
    }
  fclose(f);
  free(v);
  
 
}

int main()
{

  prob();

  return 0;
}
