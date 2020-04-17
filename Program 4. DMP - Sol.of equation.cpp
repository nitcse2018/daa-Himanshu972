/*
		PROGRAM TO FIND THE NUMBER OF NON-NEGATIVE 
		SOLUTIONS OF A LINEAR EQUATIONS
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int no_solutions(int coefficient[], int n, int RHS) 
{  
   int dp[RHS+1];
   memset(dp, 0, sizeof(dp)); 
   dp[0] = 1; 
   
	for (int i = 0; i < n; i++) 
		for (int j = coefficient[i]; j <= RHS; j++) 
    		dp[j] = dp[j] +  dp[j - coefficient[i]]; 
  
    return dp[RHS]; 
} 

main()
{
	srand(time(0)); 
	printf("\n\n  No. of terms in the LHS : ");
	int n;
	scanf("%d",&n);
	
	int coefficient[n];
	int variable[n];
    int i;
    
    char var='a';
    for(i=0;i<n;i++)
    	variable[i]=var++;
    
    for(i=0;i<n;i++)
    	coefficient[i]=rand()%100;
    
    int RHS;
	RHS=rand()%200;
    
    printf("\n\n	The linear equation is :-	");
    for(i=0;i<n-1;i++)
		printf(" %d%c +",coefficient[i],variable[i]);
	
	printf(" %d%c  =  %d",coefficient[i],variable[i],RHS); 
	
	printf("\n\n\n	The no. of non-negative solutions of the linear equation  =  %d \n\n",no_solutions(coefficient,n,RHS));  	
}
