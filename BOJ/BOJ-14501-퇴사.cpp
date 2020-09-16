// 데이터 크기로 미루어 봤을 때 시간 복잡도 크게 상관없으면 일단 시도는 해보기

#include<iostream>

int N, ans = -1, schedule[20][2];

void find(int start, int cache){
    if(start > N + 1) return;
    if(start == N + 1){
        ans = (ans < cache) ? cache : ans;
        return;
    }
    if(schedule[start][0] != 1)           find(start + 1, cache);
    find(start + schedule[start][0], cache + schedule[start][1]);
}

int main () {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d %d", &schedule[i][0], &schedule[i][1]);
    }
    find(1, 0);
    printf("%d", ans);

    return 0;
}
