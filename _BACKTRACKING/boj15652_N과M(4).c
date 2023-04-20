// https://www.acmicpc.net/problem/15652
// N과 M (4)


#include <stdio.h>
#include <string.h>

void nm(int* arr, int level, int init);

int N, M;

int main(){

    scanf("%d %d", &N, &M);

    int arr[M];
    
    
    nm(arr, 0, 1);
    

    return 0;
}

void nm(int* arr, int level, int init){
    // printf("level : %d\n", level);
    
    if(level==M){
        for(int i=0 ; i<M ; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    else{
        for(int i=init ; i<=N ; i++){
            
            arr[level] = i; 
            nm(arr, level+1, i);
            
        }
    }
}