// 라면매니아 교준이네 집 주변에는 N개의 라면 공장이 있다. 
// 각 공장은 1번부터 N번까지 차례대로 번호가 부여되어 있다. 
// 교준이는 i번 공장에서 정확하게 Ai개의 라면을 구매하고자 한다(1 ≤ i ≤ N).

// 교준이는 아래의 세 가지 방법으로 라면을 구매할 수 있다.

// i번 공장에서 라면을 하나 구매한다(1 ≤ i ≤ N). 이 경우 비용은 3원이 든다.
// i번 공장과 (i+1)번 공장에서 각각 라면을 하나씩 구매한다(1 ≤ i ≤ N-1).
// 이 경우 비용은 5원이 든다.
// i번 공장과 (i+1)번 공장, (i+2)번 공장에서 각각 라면을 하나씩 구매한다(1 ≤ i ≤ N-2). 
// 이 경우 비용은 7원이 든다.
// 최소의 비용으로 라면을 구매하고자 할 때, 교준이가 필요한 금액을 출력하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에 라면 공장의 개수를 의미하는 자연수 N가 주어진다.

// 두번째 줄에 N개의 정수 A1, ···, AN가 사이에 공백을 두고 주어진다.

// 출력
// 첫 번째 줄에 교준이가 필요한 최소 금액을 출력한다.




#include <stdio.h>

int min(int a, int b);

int main(){
    int fac_num;
    int sum=0;
    scanf("%d", &fac_num);

    int arr_num[10003];
    for(int i=1 ; i<=fac_num ; i++){
        scanf("%d" , &arr_num[i]);
    }


    for(int i=1 ; i<=fac_num ; i++){
        // if와 else에서 i와 i+2
        if(arr_num[i+1] > arr_num[i+2]){

            // 2 5 3 의 경우 가운데를 깎아주거나 2를 없애버림.
            int temp1 = min(arr_num[i], arr_num[i+1] - arr_num[i+2]);
            sum += temp1*5;
            arr_num[i] -= temp1;
            arr_num[i+1] -= temp1;

            int temp2 = min(arr_num[i] , min(arr_num[i+1] , arr_num[i+2])); // = min(i , i+1 , i+2)
            sum += temp2*7;
            arr_num[i] -= temp2;
            arr_num[i+1] -= temp2;
            arr_num[i+2] -= temp2;
        }
        else{
            int temp1 = min(arr_num[i] , min(arr_num[i+1] , arr_num[i+2]));
            sum += temp1*7;
            arr_num[i] -= temp1;
            arr_num[i+1] -= temp1;
            arr_num[i+2] -= temp1;

            int temp2 = min(arr_num[i] , arr_num[i+1]);
            sum += temp2*5;
            arr_num[i] -= temp2;
            arr_num[i+1] -= temp2;

        }
        sum += arr_num[i]*3;
        arr_num[i] = 0;
    }

    printf("%d" , sum);


    return 0;

}

int min(int a, int b){
    return  a < b ? a : b;
}