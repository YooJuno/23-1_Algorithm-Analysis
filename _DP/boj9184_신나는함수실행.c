// https://www.acmicpc.net/problem/9184
#include <stdio.h>

int w(int a, int b, int c);

int arr[21][21][21] = {0,};
int flag[21][21][21] = {0,};
int over;
int flag_over=0;

int main(){

    int a=0,b=0,c=0;
    

    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if (a==-1 && b==-1 && c==-1)
            break;
        
        printf("w(%d, %d, %d) = %d\n" , a,b,c , w(a,b,c));
    
    }

    return 0;
}


int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        if(flag_over==0)
            over = w(20, 20, 20);
        flag_over=1;
        return over;
    }
    
    else if(a<b && b<c){ // [1,20]의 범위 안에 있음
        if(flag[a][b][c-1]==0){
            arr[a][b][c-1] = w(a, b, c-1);
            flag[a][b][c-1]=1;
        }
        if(flag[a][b-1][c-1]==0){
            arr[a][b-1][c-1] = w(a, b-1, c-1);
            flag[a][b-1][c-1] = 1;
        }
        if(flag[a][b-1][c]==0){
            arr[a][b-1][c] = w(a, b-1, c);
            flag[a][b-1][c] = 1;
        } 
        
        return arr[a][b][c-1] + arr[a][b-1][c-1] - arr[a][b-1][c];
    }
    else{ // [1,20]의 범위 안에 있음
        if(flag[a-1][b][c]==0){
            arr[a-1][b][c] = w(a-1, b, c);
            flag[a-1][b][c] = 1;
        }
        if(flag[a-1][b-1][c]==0){
            arr[a-1][b-1][c] = w(a-1, b-1, c);
            flag[a-1][b-1][c] = 1;
        } 
        if(flag[a-1][b][c-1]==0){
            arr[a-1][b][c-1] = w(a-1, b, c-1);
            flag[a-1][b][c-1] = 1;
        }
        if(flag[a-1][b-1][c-1]==0){
            arr[a-1][b-1][c-1] = w(a-1, b-1, c-1);
            flag[a-1][b-1][c-1] = 1;
        }
        
        
        return arr[a-1][b][c] + arr[a-1][b-1][c] + arr[a-1][b][c-1] - arr[a-1][b-1][c-1];
    }


}