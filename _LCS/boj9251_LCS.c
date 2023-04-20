// https://www.acmicpc.net/problem/9251
// LCS

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

    // printf("recur : %d\n", LCS_RECUR(X,Y,i,j));
    printf("%d\n", LCS_DP(X,Y,i,j));

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
