#include<stdio.h>
#include "C:/Users/user/Documents/movie/movie1.h"
void testinitialize();
void testnext();
void testchecktkts();
void testlocktkts();
int main()
{
testnext();
testinitialize();
testchecktkts();
testlocktkts();


return 0;

}
void testnext()
{
	SEAT current,nxt;
	current.status =0;
    current.row = 'a';
    current.col = 20;

    nxt=next(current);
    printf("\n%c\t%d\n",current.row,current.col);
    printf("\n next's: %c\t%d\n\n\n",nxt.row,nxt.col);
}
	
void testinitialize()
{
	printf("Testing initialize() function......\n");
	SCREEN sc;
	initialize(&sc);
	//sc.seat[2][3].status=0;
	int i,j,count=0;
	printf("========SCREEN %d ==========\n\n",sc.scno);
	for(i=0;i<totrows;i++)
	{
		for(j=0;j<totcols;j++)
		{
			if(sc.seat[i][j].status == notbookd)
			    {printf("%d-%d ",sc.seat[i][j].row,sc.seat[i][j].col);
			     count++;
			    }
			    
		}
        printf("\n");
	}
	printf("Total no of seats = %d\n",count);
	printf("Checking statuses of seats.....\n\n");
	for(i=0;i<totrows;i++)
	{
		for(j=0;j<totcols;j++)
		{
			printf("%d  %d  %d\n",sc.seat[i][j].status,sc.seat[i][j].row,sc.seat[i][j].col);
		}
	}
	printf("End of testinitialize() function......\n\n");
	
}

void testchecktkts()
{   printf("Testing checktkts()....\n\n");
	SCREEN sc;
	initialize(&sc);
	if(checktkts(&sc,500))
	{
		printf("\nHow can you sell more seats than there are!");
		printf("\ncheck the checktkts function in movie1.h\n");
	}
	if(checktkts(&sc,99))
	{
		printf("okay! checktkts works!\n");

	}
    printf("ENd of testchecktkts().....\n\n");
     
}   

void testlocktkts()
{
//this test function is very weak 

printf("\n\n testing locktkts()......\n");
SCREEN sc;int num=5,row=3,col=6;
initialize(&sc);
locktkts(&sc,num,row,col);
  int i=3,j=6;
    for(j=6;j<num+5;j++) //here;I mean the seats need not be in the same row
    {
    if(sc.seat[i][j].status!=bookd)
       {
         printf(" failed one simple case\n check the locktkts function\n");
       }
     }
     
  printf("\n\n%d\n",sc.seat[3][6].status);
  printf("%d\n",sc.seat[3][5].status);
  printf("%d\n",sc.seat[3][10].status
  );
  
  printf("end of testlocktkts()......\n");
     

}
