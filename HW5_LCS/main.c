#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>


void GenSeq(char* s, int n);
const int num_alphabet = 5;
void PrintSeq(char* s, int n);
int LCS(char* X, char* Y, int i, int j);
int LCS_Length(char* X, char* Y, int i, int j);
int** c;
int** b; // 0: '↖', -1: '↑', 1: '←'
void PRINT_LCS(char* X, int i, int j);
void PRINT_LCS_ALL(char* X, char* Y, int i, int j, char* lcs, int k, char** lcs_list);
int FindMax(int a, int b);
int GetCurrentUsec();

int count_lcs = 0;


int main(void) { 
	int i = 10; // length of X
	int j = 10; // length of Y
	
	char* X, * Y; // sequences
	X = (char*)malloc(sizeof(char)*i);
	Y = (char*)malloc(sizeof(char)*j);
	
	c = (int**)malloc(sizeof(int*)*(i+1));
	for (int k=0; k<i+1; k++) c[k] = (int*)malloc(sizeof(int)*(j+1));
	b = (int**)malloc(sizeof(int*)*(i+1));
	for (int k=0; k<i+1; k++) b[k] = (int*)malloc(sizeof(int)*(j+1));
	
	srand(time(NULL));
	GenSeq(X, i);
	GenSeq(Y, j);
	
	PrintSeq(X, i);
	PrintSeq(Y, j);
	
	int t1, t2, result;
	
	// Divide and Conquer
	t1 = GetCurrentUsec();
	result = LCS(X, Y, i, j);
	t2 = GetCurrentUsec();
	printf("Then length of LCS is %d.\n", result);
	printf("Divide and Conquer took %d usec.\n", t2-t1);
	
	// Dynaic Programming
	t1 = GetCurrentUsec();
	result = LCS_Length(X, Y, i, j);
	t2 = GetCurrentUsec();
	printf("Then length of LCS is %d.\n", result);
	printf("Dynamic Programming took %d usec.\n", t2-t1);

	char* lcs = (char*)malloc(sizeof(char)*(result+1));
	char** lcs_list = (char**)malloc(sizeof(char*)*30);
	for(int temp=0 ; temp<30 ; temp++){
		lcs_list[temp] = (char*)malloc(sizeof(char)*(result+1));
	}
	
	printf("the only one LCS is : <");
	PRINT_LCS(X, i, j);
	printf(">\n\n");
	
	printf("every LCS are : \n");
	PRINT_LCS_ALL(X,Y, i, j, lcs, result, lcs_list);
	return 0;
}

//////////////////////////////
//  write your answer below //
//////////////////////////////
/*

for i = 2, j = 2
Divide and Conquer took : [ 0 ] usec.
Dynamic Programming took : [ 0 ] usec.

for i = 5, j = 5
Divide and Conquer took : [ 1 ] usec.
Dynamic Programming took : [ 1 ] usec.

for i = 10, j = 10
Divide and Conquer took : [ 73 ] usec.
Dynamic Programming took : [ 1 ] usec.

for i = 15, j = 15
Divide and Conquer took : [ 22664 ] usec.
Dynamic Programming took : [ 2 ] usec.

*/
//////////////////////////////

int LCS(char* X, char* Y, int i, int j)
{
	int c;
	// your code here, Divide and Conquer method using recursion
	if(i==0 || j==0){
		c = 0;
	}
	else if( (i>0 && j>0) && (X[i-1]==Y[j-1]) ){
		c = LCS(X,Y,i-1,j-1) + 1;
	}
	else{
		c = FindMax(LCS(X,Y,i,j-1) , LCS(X,Y,i-1,j));
	}
	
	return c;
}

int FindMax(int a, int b)
{
  if (a >= b) 
    return a;
  else
    return b;
}

// 0: '↖', -1: '↑', 1: '←'
int LCS_Length(char* X, char* Y, int m, int n)
{
	for (int k=0; k<m+1; k++) c[k][0] = 0;
	for (int k=0; k<n+1; k++) c[0][k] = 0;
	
	for (int i=1; i<m+1; i++){
		for (int j=1; j<n+1; j++)
		{
			// your code here
			if(X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 0;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = -1;
			}
			else{ 
				c[i][j] = c[i][j-1];
				b[i][j] = 1;
			}
			
		}
	}
	return c[m][n];
}

// 0: '↖', -1: '↑', 1: '←'
void PRINT_LCS(char* X, int i, int j)
{
	// your code here 
	if (i==0 || j==0){
		return;
	}
	if(b[i][j] == 0){
		PRINT_LCS(X , i-1, j-1);
		printf("%c", X[i-1]);
	}
	else if(b[i][j] == -1){
		PRINT_LCS(X, i-1, j);
	}
	else{
		PRINT_LCS(X,i,j-1);
	}
	
}

void PRINT_LCS_ALL(char* X, char* Y, int i, int j, char* lcs, int k, char** lcs_list)
{
	if(i == 0 || j == 0) {
		int flag_dup = 0;
		for(int juno=0 ; juno<count_lcs ; juno++){
			if(strcmp(lcs,lcs_list[juno]) == 0)
				flag_dup = 1;
		}
		if(flag_dup == 0){
			strcpy(lcs_list[count_lcs] , lcs);
			count_lcs += 1;
			printf("%s\n", lcs);
		}
		return;
	}
	if (X[i-1] == Y[j-1]) {
		lcs[k-1] = X[i-1];
		PRINT_LCS_ALL(X, Y, i-1, j-1, lcs, k-1, lcs_list);
	}
	else {
		if (c[i-1][j] == c[i][j-1]) {
			PRINT_LCS_ALL(X, Y, i-1, j, lcs, k, lcs_list);
			PRINT_LCS_ALL(X, Y, i, j-1, lcs, k, lcs_list);
		}
		else if (c[i-1][j] > c[i][j-1]) {
			PRINT_LCS_ALL(X, Y, i-1, j, lcs, k, lcs_list);
		}
		else {
			PRINT_LCS_ALL(X, Y, i, j-1, lcs, k, lcs_list);
		}
	}
}





int GetCurrentUsec()
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_usec;
}

void GenSeq(char* s, int n)
{
  for (int i=0; i<n; i++)
  {
    s[i] = (char)((random() % num_alphabet)+ 'A');
  }
  return;
}

void PrintSeq(char* s, int n)
{
  printf("<");
  for (int i=0; i<n; i++)
  {
    printf("%c, ", s[i]);
  }
  printf(">\n");
}