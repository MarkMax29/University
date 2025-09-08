#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
                                                                                
#define MAX 20   
#define INF 999999                                                               
int graf[MAX+1][MAX+1],vizitat[MAX+1];   
int D[MAX+1][MAX+1],traseu[MAX+1][MAX+1];    


void Floyd(int n)// afiseaza matricea de distante minime
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                D[i][j]=0;
            else if(graf[i][j]==0)
                D[i][j]=INF;
            else
                D[i][j]=graf[i][j];
            traseu[i][j]=-1;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(D[i][j]>D[i][k]+D[k][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    traseu[i][j]=k;
                }

            }
        }
    }

 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(D[i][j]==INF)
                printf("INF ");
            else
                printf("%3d ",D[i][j]);
        }
        printf("\n");
    }
}

void drum(int i,int j)//imi construieste drumul recursiv dintre 2 noduri(doar cele dintre i si j ,i si j trebe afisat separat)
{
    if(traseu[i][j]!=-1)
    {
        drum(i,traseu[i][j]);
        printf("%d ",traseu[i][j]);
        drum(traseu[i][j],j);
    }
}

void Univ_date(int a,int b)
{
    printf("Drumul dintre %d si %d este : %d ",a,b,a);
    drum(a,b);
    printf("%d\n",b);
}
void drum_minim_MAX(int n)//cauta drumul minim cel mai lung si il afiseaza cu cost cu tot
{
    int maxim=0,maxi=-1,maxj=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(D[i][j]>maxim && D[i][j]!=INF)
               {
                maxim=D[i][j];
                maxi=i;
                maxj=j;
               }
        }
    }

    if(maxi!=-1 && maxj !=-1)
    {
        printf("Drumul minim cel mai lung e de la %d la %d : %d ",maxi,maxj,maxi);
        drum(maxi,maxj);
        printf(" %d | cu costul : %d\n",maxj,D[maxi][maxj]);
    }
    
}
void afisare_drumuri(int n)// afiseaza absolut toate drumurile 
{
    printf("TOATE DRUMURILE: \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j && D[i][j]!=INF)
            {
                printf("Drum de la %d la %d: %d ",i,j,i);
                drum(i,j);
                printf("%d \n",j);
            }
        }
    }
}
int main(int argc,char **argv)                                                  
{                                                                               
                                                                                
    if(argc!=2)                                                                 
    {                                                                           
        perror("pl\n");                                                         
        exit(-1);                                                               
    }                                                                           
                                                                                
    FILE *f=fopen(argv[1],"r");                                                 
    if(f==NULL)                                                                 
    {                                                                           
        perror("pz\n");                                                         
        exit(-1);                                                               
    }                                                                           
                                                                                
    int n;                                                                      
    fscanf(f,"%d",&n);   

    int a,b,cost;
    while(fscanf(f,"%d %d %d",&a,&b,&cost)==3)
    {
        graf[a][b]=cost;
    }


    Floyd(n);
    Univ_date(1,7);
    drum_minim_MAX(n);
    afisare_drumuri(n);
    return 0;
}
