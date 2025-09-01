#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int drum[MAX];

void dfs(int curent,int y,int lung)
{
    drum[lung]=curent;//pun pe x in stiva
    if(curent==y)//daca am ajuns la y afisez drumul si ma intorc pein backtracking la poz de dinainte ca sa nu se repete nodurile si drumurile 
    {
        for(int i=0;i<=lung;i++)
        {
            if(i!=lung)
                printf("%d -> ",drum[i]);
            else
                printf("%d\n",drum[i]);
        }
        return;
    }

    for(int next=curent+1;next<=y;next++)//apelez functia cu urmatorul nod pentru ca pentru aceasta problema sa epresupune ca exista muchii intre toate i si j unde i>j
    {
        dfs(next,y,lung+1);
    }
}

int main()
{

    int x,y,n;
    FILE *f=fopen("in.txt","r");
    if(f==NULL)
    {
        perror("not ok at openning\n");
        exit(-1);
    }

    fscanf(f,"%d %d %d",&n,&x,&y);

    if(x>=y||x<0||y>=n||n>MAX)    
    {   
        printf("Valori invalide trebe x<y\n");
        return -1;
    }

    dfs(x,y,0);

    return 0;
}