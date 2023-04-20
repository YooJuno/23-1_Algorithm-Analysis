// https://www.acmicpc.net/problem/1541
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
방법 1
마이너스 부호 뒤에 나오는 것들은 싹다 인버트...?
근데 이렇게 하면 오히려 값이 커질 수도 있어서 다시 생각해 봐야할듯
*/

/*
방법 2
마이너스 부호 나오는 순간 뒤에꺼는 싹 다 음수 취하면 됨
*/
int is_operator(char ch){
    if(ch == '-' || ch == '+' || ch == '\0')
        return 1;
    else
        return 0;
}


int main(){

    char msg[50];
    scanf("%s" , msg);
    
    int num[50];
    int num_cnt=0;
    char* buf = (char*)malloc(sizeof(char)*5);
    int buf_cnt=0;

    char operator[50];
    int oper_cnt=0;

    for(int i=0 ; i<=strlen(msg) ; i++){
        if(is_operator(msg[i])){
            num[num_cnt++] = atoi(buf);
            free(buf);
            buf = (char*)malloc(sizeof(char)*5);
            buf_cnt=0;

            operator[oper_cnt++] = msg[i];
        }
        else{
            buf[buf_cnt++] = msg[i];
        }
    }

    int sum = num[0];
    int flag=1;
    for(int i=1 ; i<num_cnt ; i++){
        if(operator[i-1] == '-'){
            flag=0;
        }

        if(flag == 1){
            sum += num[i];
        }
        else{
            sum -= num[i];
        }

    }

    printf("%d\n", sum);

    return 0;
}
