#include <stdio.h>

void insertionsort(int* A , int n);

int main(){

    int arr[10] = {9,8,7,6,5,4,3,2,1,0};


    insertionsort(arr, 10);
    return 0;
}

void insertionsort(int* A , int n){
    int key,j;
    for(int i=1 ; i<n ; i++){
        // for(int k=0 ; k<n ; k++){
        //     printf("%d ", A[k]);
        // }
        // printf("\n");

        key = A[i];
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
        /*
        맨 오른쪽 부터 대소 비교해서 왼쪽애보다 작으면 먹힘. 먹힌 애는 나중에 자기 자리 찾아서 들어감.
        */
        
    }
    // for(int k=0 ; k<n ; k++){
    //         printf("%d ", A[k]);
    //     }

}