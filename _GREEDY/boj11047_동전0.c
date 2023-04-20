// https://www.acmicpc.net/problem/11047
// 동전 0

#include <stdio.h>



int main(){

    int N, K;
    scanf("%d %d", &N, &K);

    int value[N];

    for(int i=0 ; i<N ; i++){
        scanf("%d", &value[i]);
    }

    int count=0;

    for(int i=N-1 ; i>=0 ; i--){
        while(K>=value[i] && K>=0){
            K -= value[i];
            count++;
        }
    }



    printf("%d", count);



    return 0;
}