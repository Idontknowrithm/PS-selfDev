#include<iostream>
#include<cstring>
#define ll long long

ll y[4] = {1, 0, -1, 0};
ll x[4] = {0, -1, 0, 1};
ll N, M, board[505][505], cache[505][505];

bool possible(ll r, ll c){
    return r >= 0 && r < M && c >= 0 && c < N;
}
ll DP(ll R, ll C){
    if(R == M - 1 && C == N - 1) return 1;

    ll &ret = cache[R][C];
    if(ret != -1) return ret;
    ret = 0;
    for(ll i = 0; i < 4; ++i){
        if(possible(R + y[i], C + x[i]) && board[R + y[i]][C + x[i]] < board[R][C])
            ret += DP(R + y[i], C + x[i]);
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &M, &N);
    for(ll i = 0; i < M; ++i)
    for(ll u = 0; u < N; ++u)
        scanf("%lld", &board[i][u]);
    memset(cache, -1, sizeof(cache));
    printf("%lld", DP(0, 0));
    return 0;
}
