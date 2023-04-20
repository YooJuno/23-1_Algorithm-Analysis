// https://www.acmicpc.net/problem/13305
// 주유소 [실버3] 

#include <stdio.h>



int main(){

    int N;
    scanf("%d" , &N);

    int len[N-1];
    for(int i=0 ; i<N-1 ; i++){
        scanf("%d", &len[i]);
    }

    int city[N];
    for(int i=0 ; i<N-1 ; i++){
        scanf("%d", &city[i]);
    }

    long long sum=0;

    long long min = 1000000000;
    for(int i=0 ; i<N-1 ; i++){
        if(min > city[i]){
            min = city[i];
        }

        
        sum += len[i]*min;
        
    }

    printf("%lld\n", sum);


    return 0;
}