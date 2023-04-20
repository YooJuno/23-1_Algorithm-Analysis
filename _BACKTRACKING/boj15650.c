// https://www.acmicpc.net/problem/15650
// N과 M (2)


#include <stdio.h>
#include <string.h>

void nm(int* arr, int level, int init);

int N, M;

int main(){

    scanf("%d %d", &N, &M);

    int arr[M];
    
    nm(arr, 0, 0);
    

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
        for(int i=init+1 ; i<=N ; i++){

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
            nm(arr, level+1, i);
            
        }
    }
}