/*
	PROGRAM OF PLACING OF N CHESS QUEENS ON NxN CHESSBOARD 
	SO THAT NO TWO QUEENS THREATEN EACH OTHER ON THE BOARD. 
*/
#include<stdio.h> 
#include<string.h> 
#define N 8
  
void printSolution(int board[N][N]) 
{ 
	char N_Queens[N][N];
	int i,j;
	
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++) 
        	if(board[i][j])
        		N_Queens[i][j]='Q';
        	else
        		N_Queens[i][j]='-';
    
    printf("\n\n  The positions of queens Q in the board are - : \n\n\n");
    
    for(i=0;i<N;i++)
    {
    	printf("		");
    	for(j=0;j<N;j++)
    		printf("   %c",N_Queens[i][j]);
    	
    	printf("\n\n");
	}
} 
  
bool isSafe(int row, int col, int slashCode[N][N], 
            int backslashCode[N][N], bool rowLookup[], 
            bool slashCodeLookup[], bool backslashCodeLookup[] ) 
{ 
    if (slashCodeLookup[slashCode[row][col]] || 
        backslashCodeLookup[backslashCode[row][col]] || 
        rowLookup[row]) 
    return false; 
  
    return true; 
} 
  
bool solveNQueensUtil(int board[N][N], int col, 
    int slashCode[N][N], int backslashCode[N][N], bool rowLookup[N], 
    bool slashCodeLookup[], bool backslashCodeLookup[] ) 
{ 
    if (col >= N) 
        return true; 
  
    for (int i = 0; i < N; i++) 
    { 
        if ( isSafe(i, col, slashCode, backslashCode, rowLookup, 
                    slashCodeLookup, backslashCodeLookup) ) 
        { 
            board[i][col] = 1; 
            rowLookup[i] = true; 
            slashCodeLookup[slashCode[i][col]] = true; 
            backslashCodeLookup[backslashCode[i][col]] = true; 
  
            if ( solveNQueensUtil(board, col + 1, slashCode, backslashCode, 
                    rowLookup, slashCodeLookup, backslashCodeLookup) ) 
                return true; 
  
            board[i][col] = 0; 
            rowLookup[i] = false; 
            slashCodeLookup[slashCode[i][col]] = false; 
            backslashCodeLookup[backslashCode[i][col]] = false; 
        } 
    } 
  
    return false; 
} 
  
bool solveNQueens() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof board); 
  
    int slashCode[N][N]; 
    int backslashCode[N][N]; 
  
    bool rowLookup[N] = {false}; 
  
    bool slashCodeLookup[2*N - 1] = {false}; 
    bool backslashCodeLookup[2*N - 1] = {false}; 
  
    for (int r = 0; r < N; r++) 
        for (int c = 0; c < N; c++) 
        {
        	slashCode[r][c] = r + c, 
            backslashCode[r][c] = r - c + 7; 
		}
  
    if (solveNQueensUtil(board, 0, slashCode, backslashCode, 
      rowLookup, slashCodeLookup, backslashCodeLookup) == false ) 
    { 
        printf("\n\n	Solution does not exist for N = %d \n\n",N); 
        return false; 
    } 
  
    printSolution(board); 
    return true; 
} 
  
main() 
{
    solveNQueens(); 
}
