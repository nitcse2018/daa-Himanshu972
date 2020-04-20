/*
		PROGRAM TO FIND ALL POSSIBLE PATHS 
		FROM TOP LEFT TO BOTTOM RIGHT OF A 2D MATRIX 
		WHERE ONLY RIGHT AND TOP MOVES ARE ALLOWED
		IN THE PATH.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//  Outta  LEFT, RIGHT, UP and DOWN  moves, only RIGHT and DOWN moves are allowed. 

int count_path=0;

void print_paths(int *matrix, int i, int j, int m, int n, int *path, int pi) 
{ 
    if (i == m - 1) 
    { 
        for (int k = j; k < n; k++) 
            path[pi + k - j] = *((matrix + i*n) + k); 
            
        printf("\n	Path %d -:",++count_path);
        for (int l = 0; l < pi + n - j; l++) 
        	printf("  %d",path[l]);

        printf("\n\n");
        return; 
    } 
  
    if (j == n - 1) 
    { 
        for (int k = i; k < m; k++) 
            path[pi + k - i] = *((matrix + k*n) + j); 
            
        printf("\n	Path %d -:",++count_path);
        for (int l = 0; l < pi + m - i; l++) 
        	printf("  %d",path[l]);
        	
        printf("\n\n");
        return; 
    } 
    
    path[pi] = *((matrix + i*n) + j); 
  
    print_paths(matrix, i+1, j, m, n, path, pi + 1); 
  
    print_paths(matrix, i, j+1, m, n, path, pi + 1); 
} 
  
void all_paths(int *matrix, int m, int n) 
{ 
	int *path;
	path= (int*)malloc((m+n)*sizeof(int));
	
    print_paths(matrix, 0, 0, m, n, path, 0); 
} 
  
main() 
{ 
	srand(time(0));
	
	printf("\n\n  Enter dimensions of matrix  : -  \n");
	int m,n;
	
	printf("\n		Rows  :  ");
	scanf("%d",&m);
	printf("\n		Columns  :  ");
	scanf("%d",&n);
	
	int matrix[m][n];
	
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=rand()%100;
			
	printf("\n	The matrix entered is  : - \n\n\n");
	
	for(i=0;i<m;i++)
	{
		printf("		");
		for(j=0;j<n;j++)
			printf("	%d",matrix[i][j]);
		printf("\n\n");
	}
	printf("\n\n");
	all_paths(*matrix,m,n);		
}
