// https://www.acmicpc.net/problem/9095
// 1, 2, 3 더하기

// 가끔은 노가다가 필요한 때가 있다

#include <stdio.h>

int main(){

    int t;
    scanf("%d", &t);

    int dp[12];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;


    for(int i=0 ; i<t ; i++){
        int n;
        scanf("%d", &n);
        if(n>3){
            for(int i=4 ; i<=n ; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
        }
        printf("%d\n", dp[n]);
    }


    return 0;
}