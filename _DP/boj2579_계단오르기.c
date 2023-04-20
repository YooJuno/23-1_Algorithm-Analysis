// https://www.acmicpc.net/problem/2579
// 계단 오르기

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX(a,b) a>b?a:b

int main(){

    int stair[301];
    int dp[301];
    

    int N; // 계단의 갯수
    scanf("%d", &N);

    stair[0] = 0;
    
    for(int i=1 ; i<=N ; i++){
        scanf("%d", &stair[i]);
    }

    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for(int i=3 ; i<=N ; i++){
        dp[i] = MAX(stair[i] + stair[i-1] + dp[i-3] , stair[i] + dp[i-2]);
    }

    printf("%d\n", dp[N]);


    return 0;
}