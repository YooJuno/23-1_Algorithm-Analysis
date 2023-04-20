// https://www.acmicpc.net/problem/1495
// 기타리스트
#include <stdio.h>
#include <stdbool.h>

bool dp[51][1001] = {false,};

int main(){
    int n, s, m;
    scanf("%d %d %d" , &n, &s , &m);

    int vol[n+1];

    for(int i=1 ; i<=n ; i++){
        scanf("%d" , &vol[i]); 
    }

    dp[0][s] = true;
    int max=-1;

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){

            if(dp[i-1][j]==true){ // 걸러주기
                
                if(j-vol[i] >= 0){
                    dp[i][j-vol[i]] = true;
                    // if(max < j-vol[i]){
                    //     max = j-vol[i];
                    // }

                } 
                if(j+vol[i] <= m){
                    dp[i][j+vol[i]] = true;
                    // if(max < j+vol[i]){
                    //     max = j+vol[i];
                    // }
                } 
            }
        }

    }
    for(int i=m ; i>=0 ; i--){
        if(dp[n][i]){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");


    return 0;
}