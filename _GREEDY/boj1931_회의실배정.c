// https://www.acmicpc.net/problem/1931
// 회의실 배정
// 끝나는 시간을 기준으로 정렬한다.
#include <stdio.h>
#include <stdlib.h>

struct time{
    int t_start;
    int t_end;
};


int cmp(const void *a,const void *b){
	struct time *x=(struct time *)a;
	struct time *y=(struct time *)b;
	if(x->t_end != y->t_end){
		return x->t_end - y->t_end;
	}
	else{
		return x->t_start - y->t_start;
	}
}

int main(){

    int N;
    scanf("%d" , &N);

    struct time time_t[N];

    int cnt=0;
    for(int i=0 ; i<N ; i++){
        scanf("%d %d" , &time_t[i].t_start , &time_t[i].t_end);
    }
    qsort(time_t,N,sizeof(struct time),cmp);

    // quicksort(time_t ,0, N-1);

    int answer=1;
    int tt=time_t[0].t_end;

    for(int i=1 ; i<N ; i++){

        if(tt <= time_t[i].t_start){
            answer++;
            tt = time_t[i].t_end;
        }

    }

    printf("%d\n", answer);
    

    return 0;
}



