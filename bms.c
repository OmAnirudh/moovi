#include<stdio.h>
#include "C:/Users/user/Documents/movie/movie1.h"


void bookshow(SCREEN*);

int main()
{
	SCREEN sc;
	initialize(&sc);
	bookshow(&sc);
}

void bookshow(SCREEN* sc)
{
	int num;
	printf("Enter the number of seats you want\n");
	scanf("%d",&num);
	printscreen(sc);
	printf("\n\nEnter the rowNumber  of your first seat\n");
	int row,col;
	scanf("%d",&row);
	printf("\n ENter the colnum of your first seat\n");
	scanf("%d",&col);
	locktkts(sc,num,row,col);
	printscreen(sc);
	TICKET tk;
	
	
}
	
