// https://www.acmicpc.net/problem/15649
// N과 M (1)

// 혼자 힘으로 풀었다.


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

            int flag=0;
            for(int j=0 ; j<level ; j++){
                if(arr[j] == i){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                continue;
            }
            
            arr[level] = i; 
            nm(arr, level+1);
            
        }
    }
}