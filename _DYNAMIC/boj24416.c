//  https://www.acmicpc.net/problem/24416
#include <stdio.h>
#include <stdlib.h>

int fib(int n);
void fibonacci(int n);
char* f;

int cnt_recur=0;
int cnt_dynamic=0;

int main(){

    int n;
    scanf("%d" , &n );

    fib(n);

    f = (char*)malloc(sizeof(char)*n);
    fibonacci(n);

    printf("%d %d\n" , cnt_recur , cnt_dynamic);
    return 0;
}



int fib(int n){
    if(n==1 || n==2){
        cnt_recur +=  1;
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}


void fibonacci(int n){
    f[0] = 1;
    f[1] = 1;

    for(int i=2 ; i<n ; i++){
        cnt_dynamic += 1;
        f[i] = f[i-1] + f[i-2];
    }
}