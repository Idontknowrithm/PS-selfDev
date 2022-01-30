// 간단한 예외처리 무시(N == 1, N == 2일 때 경우)

#include<iostream>
#include<cstring>
#define ll long long

ll N, ans, cache[35];

ll DP(ll N){
    if(N == 1) return 1;
    if(N == 2) return 3;

    ll &ret = cache[N];
    if(ret != -1) return ret;
    
    ret = DP(N - 1) + DP(N - 2) * 2;
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%lld", &N);
    if(N < 3)
        ans = DP(N) * 2;
    else if(N & 1)
        ans = DP(N) + DP(N / 2);
    else
        ans = DP(N) + DP(N / 2) + DP(N / 2 - 1) * 2;
    
    ans >>= 1;
    printf("%lld", ans);
    return 0;
}
