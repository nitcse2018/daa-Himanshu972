/*  
		PROGRAM TO COLLECT ALL THE STARS IN MINIMUM 
		NUMBER OF STEPS ( REPRESENTED BY STRAIGHT LINES ).
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int min(int a,int b)
{
	int mini=a;
	
	if(b<mini)
		mini=b;
		
	return mini;
}
int steps_calc(int height[], int l, int r, int h) 
{ 
    if (l >= r) 
        return 0; 
  
    int m = l; 
    for (int i = l; i < r; i++) 
        if (height[i] < height[m]) 
            m = i; 
  
    return min(r - l, 
               steps_calc(height, l, m, height[m]) +  
               steps_calc(height, m + 1, r, height[m]) +  
               height[m] - h); 
} 

int min_steps(int height[], int n) 
{ 
    return steps_calc(height, 0, n, 0); 
} 

main()
{
	srand(time(0));
	
	int n;
	printf("\n How many stacks do you want : ");
	scanf("%d",&n);
	
	int height[n];
	int i,j;
	for(i=0;i<n;i++)
		height[i]=(rand()%10)+1;
	
	char a[10][n];
	for(j=0;j<n;j++)
	{
		for(i=0;i<height[j];i++)
			a[9-i][j]='*';
		while(i<10)
			a[9-i++][j]=' ';
	}
	
	printf("\n\n");
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<n;j++)
			if(a[i][j]=='*')
				printf("	%c",a[i][j]);
			else
				printf("	 ");
		printf("\n\n");
	}
	
	printf("\n\n	Minimum lines needed to join all stars   =   %d \n\n",min_steps(height,n));		
}
