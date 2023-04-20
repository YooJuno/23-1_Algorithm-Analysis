// https://www.acmicpc.net/problem/1958
// LCS3



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) a>b?a:b


// 해결 방법 -> DP
int c[101][101][101] = {0,};
int LCS_DP(char* X , char* Y ,char* Z , int x_len, int y_len, int z_len);


int main(){

    char X[101];
    char Y[101];
    char Z[101];

    scanf("%s", X);
    scanf("%s", Y);
    scanf("%s", Z);

    int i = strlen(X);
    int j = strlen(Y);
    int k = strlen(Z);




    printf("%d\n", LCS_DP(X,Y,Z,i,j,k));

    return 0;
}


// 0: '↖', -1: '↑', 1: '←'
int LCS_DP(char* X , char* Y ,char* Z , int x_len, int y_len, int z_len){
	
	for (int i=1; i<=x_len; i++){
		for (int j=1; j<=y_len; j++){
            for (int k=1; k<=z_len; k++){
            
                if(X[i-1] == Y[j-1] && Y[j-1] == Z[k-1]){
                    c[i][j][k] = c[i-1][j-1][k-1] + 1;
                }
                else{
                    c[i][j][k] = MAX(MAX(c[i-1][j][k], c[i][j-1][k]) , c[i][j][k-1]);
                }
            }

		}
	}
	return c[x_len][y_len][z_len];
}