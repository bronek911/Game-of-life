#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <ncurses.h>
//#include "func.h"

int size = 10;
int tab[10][10];
int tab2[10][10];
int tab3[10][10];
int BuildTab();
int SetCel();
int Graj();
int Reset();
int x,z;
int SetDef();
int SetRan();

//---------------------MAIN------------------------


int main(){

    int n;
    SetDef();
    do
    {
	
	system("CLS");
        
        BuildTab();
        printf("WHAT YOU WANNA DO?\n\n");
        printf("1 - Flip values of the cells\n");
        
        printf("2 - Start\n");
        
        printf("3 - Reset\n");
        
        puts("4 - Set default values");
        
        puts("5 - Set random values");
        
        printf("7 - Exit\n");
        
        scanf("%d", &n);
	switch(n)
        {    
	    case 1:
		SetCel();
	        break;
	    case 2:
	        Graj();
	        getchar();
	        break;
	    case 3:
	        Reset();
	        getchar();
	        break;
	    case 4:
		SetDef();
		break;
	    case 5:
		SetRan();
		break;
	    case 7:
	        
    	        system("CLS");
	        return 0;
	        break;
	    default:
	        break;
	}
    }
    while(n=7);
return 0;
}

//-----------------------END OF MAIN----------------------

//-----------------------BUILD THE TAB--------------------

int BuildTab(){
    int i,j;
    printf("   ");
    
    for(i=0;i<size;i++)
    {
	printf("_%d",i+1);
    }
    
    printf("\n");
    
    for(i=0;i<size;i++)
    {
	if(i<9)
	{
	    printf(" %d ",i+1);
	}
	else
	    printf("%d ",i+1);
        for(j=0;j<size;j++)
        {
		if(tab[i][j]==0)
		{
		    printf("|_");
		}
		else if(tab[i][j]==1)
		{
		    printf("|%d", tab[i][j]);
		}
	}
        printf("|\n");
    }

    for(i=0;i<(2*size);i++)
    {
	printf("-");
    }
    printf("\n");
    
    
    
return 0;
}

//-----------------------END OF BUILDING----------------

//-----------------------RESET--------------------------

int Reset()
{
    int k,l;
    for(k=0;k<size;k++){
	for(l=0;l<size;l++){
	    tab[k][l]=0;
	}
    }
    
    system("CLS");
    printf("XXX");
    BuildTab();
    
}

//---------------------END OF RESET---------------------

//---------------------SET THE VALUE OF CELLS-----------

int SetCel(){
    int k,l;
    int a;
    while (a>0){
    
        
        system("CLS");
        printf("Which column and row you want to flip?\n");
        printf("Row: ");
        scanf("%d", &k);
        printf("\nColumn: ");
        scanf("%d", &l);
        
        if(tab[k-1][l-1]==0)
        {
    	    tab[k-1][l-1]=1;
        }
        else if(tab[k-1][l-1]==1)
        {
    	    tab[k-1][l-1]=0;
        }
        
        BuildTab();
        printf("Do you want to continue? (0 - no)\n");
        scanf("%d", &a);
    }
return 0;
}

//--------------------END OF SETCEL-----------------------

//--------------------PLAY - ENGINE-----------------------

int Graj()
{
    int h;
    printf("\nHow many generation you want to see?\n");
    scanf("%d", &h);
    int g;
    for(g=0;g<h;g++)
    {
        int q,w;
        for(q=0;q<size;q++)
        {
        	for(w=0;w<size;w++)
		{
		    int sum;//cen,up,left,right,down,cor1,cor2,cor3,cor4;
		    //cen=(tab[q-1][w-1]+tab[q-1][w]+tab[q-1][w+1]+tab[q][w-1]+tab[q][w+1]+tab[q+1][w-1]+tab[q+1][w]+tab[q+1][w+1]);
		    if((q>0)&&(q<(size-1))&&(w>0)&&(w<(size-1)))
			sum=(tab[q-1][w-1]+tab[q-1][w]+tab[q-1][w+1]+tab[q][w-1]+tab[q][w+1]+tab[q+1][w-1]+tab[q+1][w]+tab[q+1][w+1]);
		    if((q==0)&&(w>0)&&(w<(size-1)))
			sum=(tab[size-1][w-1]+tab[size-1][w]+tab[size-1][w+1]+tab[q][w-1]+tab[q][w+1]+tab[q+1][w-1]+tab[q+1][w]+tab[q+1][w+1]);
		    if((q==(size-1))&&(w>0)&&(w<(size-1)))
			sum=(tab[0][w-1]+tab[0][w]+tab[0][w+1]+tab[q-1][w-1]+tab[q-1][w]+tab[q-1][w+1]+tab[q][w-1]+tab[q][w+1]);
		    if((w==0)&&(q>0)&&(q<(size-1)))
			sum=(tab[q-1][size-1]+tab[q][size-1]+tab[q+1][size-1]+tab[q-1][w]+tab[q-1][w+1]+tab[q][w+1]+tab[q+1][w]+tab[q+1][w+1]);
		    if((w==(size-1))&&(q>0)&&(q<(size-1)))
			sum=(tab[0][w-1]+tab[0][w]+tab[0][w+1]+tab[q-1][w-1]+tab[q-1][w]+tab[q][w-1]+tab[q+1][w-1]+tab[q+1][w]);
		    if((q==0)&&(w==0))
			sum=(tab[size-1][0]+tab[size-1][1]+tab[0][size-1]+tab[1][size-1]+tab[size-1][size-1]+tab[q][w+1]+tab[q+1][w]+tab[q+1][w+1]);
		    if((q==0)&&(w==(size-1)))
			sum=(tab[0][0]+tab[1][0]+tab[size-1][size-2]+tab[size-1][size-1]+tab[size-1][0]+tab[q][w-1]+tab[q+1][w-1]+tab[q+1][w]);
		    if((q==(size-1))&&(w==0))
			sum=(tab[0][0]+tab[0][1]+tab[0][size-1]+tab[size-2][size-1]+tab[size-1][size-1]+tab[q-1][w-1]+tab[q-1][w]+tab[q][w-1]);
		    if((q==(size-1))&&(w==(size-1)))
			sum=(tab[0][0]+tab[0][size-2]+tab[0][size-1]+tab[size-2][0]+tab[size-1][0]+tab[q-1][w]+tab[q-1][w+1]+tab[q][w+1]);
		if((tab[q][w]==0)&&(sum==3)) tab2[q][w]=1;
		if((tab[q][w]==0)&&((sum<3)||(sum>3))) tab2[q][w]=0;
		if((tab[q][w]==1)&&((sum==2)||(sum==3))) tab2[q][w]=1;
		if((tab[q][w]==1)&&((sum<2)||(sum>3))) tab2[q][w]=0;

		}
	}
	int y,u;
	for(y=0;y<size;y++)
	{
	    for(u=0;u<size;u++)
	    {
		tab[y][u]=tab2[y][u];
		
	    }
	}
	for(y=0;y<size;y++)
	{
	    for(u=0;u<size;u++)
	    {
		tab2[y][u]=0;
		
	    }
	}
	
	system("CLS");
	printf("\n\nGeneration No. %d\n\n", g+1);
	BuildTab();
	
	//getchar();
	sleep(1);
	}
return 0;
}

//-------------------------END OF PLAY-----------------------

//-------------------------SET DEFAULT VALUES----------------

int SetDef(){

    FILE *file;
    file=fopen("tab.txt", "r");
    int a3, a4;
    
    for(a3=0;a3<size;a3++)
    {
	for(a4=0;a4<size;a4++)
	{
	    fscanf(file,"%d", &tab[a3][a4]);
	}
    } 
    fclose(file);
    BuildTab();
}


//------------------------END OF SETDEF----------------------

//------------------------SET RANDOM VALUES------------------

int SetRan(){
    
    
    system("CLS");
    BuildTab();
    int percent;
    int random;
    
    printf("Enter how many percent of the board should be filled: ");
    scanf("%d", &percent);
    printf("%d", percent);
    srand(time(NULL));
    
    int a1,a2;
    for(a1=0;a1<size;a1++)
    {
	for(a2=0;a2<size;a2++)
	{
	    random = rand()%100;
	    if(random<percent)
	    {
		tab[a1][a2]=1;
	    }
	    else
	    {
		tab[a1][a2]=0;
	    }
	}
    }
    
    return 0;
}

//------------------------END OF SETRAN-------------------------

//------------------------SAMPLES-------------------------------


//xxxx

//------------------------END OF SAMPLES------------------------
