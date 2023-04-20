// https://www.acmicpc.net/problem/9252
// LCS2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) a>b?a:b

// Recursive...?
int LCS_RECUR(char* X , char* Y , int i, int j); // -> 시간초과

// 해결 방법 -> DP
int** c;
int** b; // 0: '↖', -1: '↑', 1: '←'
int LCS_DP(char* X , char* Y , int i, int j);


// 0: '↖', -1: '↑', 1: '←'
void PRINT_LCS(char* X, int i, int j);

int count_lcs = 0;
void PRINT_LCS_ALL(char* X, char* Y, int i, int j, char* lcs, int k, char** lcs_list);

int main(){

    char X[1001];
    char Y[1001];

    int i,j;

    scanf("%s", X);
    scanf("%s", Y);

    i = strlen(X);
    j = strlen(Y);

    c = (int**)malloc(sizeof(int*)*(i+1));
	for (int k=0; k<i+1; k++) c[k] = (int*)malloc(sizeof(int)*(j+1));
	b = (int**)malloc(sizeof(int*)*(i+1));
	for (int k=0; k<i+1; k++) b[k] = (int*)malloc(sizeof(int)*(j+1));



    printf("%d\n", LCS_DP(X,Y,i,j));
    PRINT_LCS(X,i,j);
    printf("\n");




    return 0;
}

int LCS_RECUR(char* X , char* Y , int i, int j){ // 시간초과
    if(i==0 || j==0){
        return 0;
    }
    else if((i>0 && j>0) && (X[i] == Y[j]) ){
        return LCS_RECUR(X, Y, i-1, j-1) + 1;
    }
    else{
        return MAX(LCS_RECUR(X,Y,i,j-1),LCS_RECUR(X,Y,i-1,j));
    }
}

int LCS_DP(char* X , char* Y , int x_len, int y_len){
    
    for (int k=0; k<=x_len ; k++){
        c[k][0] = 0;
    }
    for (int k=0 ; k<y_len ; k++){
        c[0][k] = 0;
    }
	
	for (int i=1; i<=x_len; i++){
		for (int j=1; j<=y_len; j++){
            
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
	return c[x_len][y_len];
}




// 0: '↖', -1: '↑', 1: '←'
void PRINT_LCS(char* X, int i, int j)
{
    // Devide and Conquer

	// your code here 
	if (i==0 || j==0){
		return;
	}

	if(b[i][j] == 0){ // 여기가 끝이야
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

