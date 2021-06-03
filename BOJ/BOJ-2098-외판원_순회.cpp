// 진짜 이거 말이 안되는 오류다 싶은 곳은 진짜 말이 안되는 오류일 확률이 큼
// 합리적일 수 있는 부분들을 비판적으로 테스트 해봐야 함
// 생각하는 부분도 당연한 곳에서 당연한 것으로 이어지는 사고를 연습하자

#include<iostream>
#include<cstring>
#include<algorithm>

const int INF = 50000000;
int N, W[20][20], cache[20][1 << 20];

int salesperson(int here, int visited){
    if(visited == (1 << N) - 1) return (W[here][0] == 0) ? INF : W[here][0];

    int &ret = cache[here][visited];
    if(ret > 0) return ret;

    ret = INF;
    for(int i = 0; i < N; ++i){
        if(visited & (1 << i) || !W[here][i]) continue;
        int tmp = W[here][i] + salesperson(i, visited + (1 << i));
        ret = std::min(ret, tmp);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &W[i][u]);
    memset(cache, -1, sizeof(cache));
    printf("%d", salesperson(0, 1)); // sales(0, 0)으로 
    return 0;
}
