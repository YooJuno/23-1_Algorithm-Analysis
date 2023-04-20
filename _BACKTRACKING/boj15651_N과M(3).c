// https://www.acmicpc.net/problem/15651
// N과 M (3)


#include <stdio.h>
#include <string.h>

void nm(int* arr, int level);

int N, M;

int main(){

    scanf("%d %d", &N, &M);

    int arr[M];
    
    nm(arr, 0);

    return 0;
}

void nm(int* arr, int level){
    // printf("level : %d\n", level);
    
    if(level==M){
        for(int i=0 ; i<M ; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    
    else{
        for(int i=1 ; i<=N ; i++){
            
            arr[level] = i; 
            nm(arr, level+1);
            
        }
    }
}