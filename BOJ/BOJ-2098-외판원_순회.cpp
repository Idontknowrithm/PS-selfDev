#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long

const ll INF = 50000000;
ll N, W[20][20], cache[20][1 << 20];

ll salesperson(ll here, ll visited){
    if(visited == (1 << N) - 1) return W[here][0];

    ll &ret = cache[here][visited];
    if(ret >= 0) return ret;

    ret = INF;
    for(ll i = 0; i < N; ++i){
        if(visited & (1 << i)) continue;
        ll tmp = W[here][i] + salesperson(i, visited + (1 << i));
        ret = std::min(ret, tmp);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(ll i = 0; i < N; ++i)
    for(ll u = 0; u < N; ++u)
        scanf("%d", &W[i][u]);
    memset(cache, -1, sizeof(cache));
    printf("%d", salesperson(0, 0));
    return 0;
}// 갈 수 없는 경우 W[i][j] = 0 인 경우를 고려하자
