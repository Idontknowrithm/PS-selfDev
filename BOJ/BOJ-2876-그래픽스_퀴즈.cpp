// 문제 조건을 놓친 점, 문제의 코너 케이스를 생각하지 못했음
// 쉬운 문제면 가능할 법한 여러 예외 케이스를 생각해보자

#include<iostream>

int N, max, maxi, target, table[100005][2], answer[5];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    for(int i = 0; i < 5; ++i){
        answer[i] = target = 0;
        for(int u = 0; u < N; ++u){
            if(table[u][0] == i + 1 || table[u][1] == i + 1){
                ++target;
            }
            else{
                answer[i] = (target > answer[i]) ? target : answer[i];
                target = 0;
            }
        }
        answer[i] = (target > answer[i]) ? target : answer[i];
        target = 0;
    }
    for(int i = 0; i < 5; ++i)
        if(max < answer[i]){
            max = answer[i];
            maxi = i + 1;
        }
    printf("%d %d", max, maxi);
    return 0;
}
