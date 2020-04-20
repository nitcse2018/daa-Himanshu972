/*
		FIND THE MINIMUM NUMBER OF SQUARES
		NEEDED TO CUT THE RECTANGULAR SHEET OF PAPER
*/

#include<stdio.h>
swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int min_square(int len,int brd)
{
	int squares = 0, rem = 0; 
  
    if (len<brd) 
        swap(len,brd); 
  
    while (brd>0) 
    { 
        squares = squares + len/brd; 
  
        int rem = len % brd; 
        len = brd; 
        brd = rem; 
    } 
  
    return squares;
}

main()
{
	int l,b;
	printf("\n\n Enter dimensions of the paper  - : \n");
	
	printf("\n		Length  :  ");
	scanf("%d",&l);
	
	printf("\n		Breadth  :  ");
	scanf("%d",&b);
	
	printf("\n\n	Minimum no. of squares for  %dx%d  paper  =   %d \n\n",l,b,min_square(l,b));
}
