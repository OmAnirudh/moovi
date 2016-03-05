#include<stdio.h>

#define totrows 20
#define totcols 20
#define notbookd 1
#define bookd 0
typedef struct
{
	int status;
	//char row; //unable to do this 
	int row;
	int col;
}SEAT;

typedef struct
{   
    int scno;
	SEAT seat[20][20];
}SCREEN;

typedef struct
{
	SCREEN screen[5];
	char name[50];
	char movies[][5];
}THEATER;

typedef struct
{   
    int scno;
	SEAT seat;
	char time[20];
}TICKET;

SEAT next(SEAT);// prototype of next funtion (it acts on a <SEAT>)

SCREEN sc;//just a screen

void initialize(SCREEN*);//prototype of initialize function

void initialize(SCREEN *sc)
{
	/* This function assigns row and col numbers and statuses
	to each seat 
	to have a working screen structure */
	
	int i,j;
	sc->scno = 2;
	for(i=0;i<totrows;i++)
	{
		for(j=0;j<totcols;j++)
		{
			sc->seat[i][j].status = notbookd;
			sc->seat[i][j].row = i;
			sc->seat[i][j].col = j;
			
		}
	}
	printf("\n%d\n",sc->scno);
}
			
			



SEAT next(SEAT current)
{
	/*This function returns a SEAT structure
	  INPUT  you must input a seat properly initialized(row&col)
	  OUPUT The next seat in the screen
    */
SEAT next;
	if(current.col>=20)
	{
		next.col = (current.col)%20;
		next.row = current.row +1;
	}
	else if(current.col<20)
	{
		next.col = current.col +1;
	}

return next;
}

//void booktkts(movie);

int checktkts(SCREEN*,int);

int checktkts(SCREEN *sc,int num)
/*this function  returns true if there are enought empty seats as per 
INPUT : number of seats required by customer
*/

//NOTE: DUPLICATION ISSUE :: the code is exactly similar to testinitialize function of tests.c
	
{

	int i,j,count=0;
	printf("checking tickets inSCREEN %d\n\n",sc->scno);
	for(i=0;i<totrows;i++)
	{
		for(j=0;j<totcols;j++)
		{
			if(sc->seat[i][j].status == notbookd)
			    {//printf("%d-%d ",sc.seat[i][j].row,sc.seat[i][j].col);
                     count++;
			         if(count>=num)
			         {
			     	     //printf("%d\n",count);
			     	     printf("\ncool! %d seats are available\n",count);
			             return 1;
			         }
				}
			    
             
		
		}
        //printf("\n");
	}
	printf("Oops only %d seats are available\n",count);
	return 0;
     
}
int locktkts(SCREEN*,int,int,int);

int locktkts(SCREEN *sc,int num,int row,int col)
{
	//if(request =="buy" or "BUY" or "Buy")
	 {  
	    printf("\n\n Booking tickets....\n"); 
		int count,i,j;
		if(checktkts(sc,num))
		{   
            //for(count=0;count<num;count++)
		   	{   count=0;
		   		for(i=row;i<totrows;i++)
	            {
	            	if(i==row)
	            	{
	            		
				        for(j=col;j<totcols;j++)
                        {
			                if(sc->seat[i][j].status == notbookd)
			                   {
			           	          sc->seat[i][j].status = bookd;
					              printf("%d-%d\n ",sc->seat[i][j].row,sc->seat[i][j].col);
			                      count++;
						       }
                            if(count>=num)
						       {
						          return 1;
						       }
		                 }
		                 
	            	}
	            	for(j=0;j<totcols;j++)
	            	{
	            		if(sc->seat[i][j].status)
	                    {
	                    	sc->seat[i][j].status=bookd;
	                    	printf("%d-%d\n ",sc->seat[i][j].row,sc->seat[i][j].col);
				            count++;
	                    }
				        if(count>=num)
				        {
				        	return 1;
				        }
	            	}
	            }
				
		   	}
	            	
		}
	    return 0;    
	        
	}
		
	
}
void printseat(SEAT*);
void printseat(SEAT *seat)
{
char row1;
switch(seat->row)
{
    case 1 : row1 = 'A';
	         break;
	case 2 : row1 = 'B';
	         break;
	case 3 : row1 = 'C';
	         break;
	case 4 : row1 = 'D';
	         break;
	case 5 : row1 = 'E';
	         break;
    case 6 : row1 = 'F';
             break;
	case 7 : row1 = 'G';
	         break;
	case 8 : row1 = 'H';
	         break;
	case 9 : row1 = 'I';
	         break;
	
	case 10 : row1 = 'J';
	          break;
    case 11 : row1 = 'K';
              break;
    case 12 : row1 = 'L';
              break;
    case 13 : row1 = 'M';
	          break;
    case 14 : row1 = 'N';
              break;
	case 15 : row1 = 'O';
              break;
	case 16 : row1 = 'P';
	          break;
	case 17 : row1 = 'Q';
	          break;
	case 18 : row1 = 'R';
	          break;
	case 19 : row1 = 'S';
	          break;
    default : row1 = 'X';
             break;
}      
if(seat->status)
{
	printf("  %c-%d  ",row1,seat->col);
}
else
{
   printf("  [N]  ");
}

}



void printscreen(SCREEN*);

void printscreen(SCREEN *sc)
{//INPUT: properly initialized SCREEN
	int i=0,j=0;
	
	for(i=0;i<totrows;i++)
	{
	printf("\n");
	if(i<10)
	{
	  printf("%d. ",i);
	}
	if(i>=10)
	{
	   printf("%d.",i); 
	}
	for(j=0;j<totcols;j++)
	{
	printseat(&sc->seat[i][j]);
	}
	
	}
}

    			


	
	
	

		
    	
    	
    	
    	
    	
    	
    
