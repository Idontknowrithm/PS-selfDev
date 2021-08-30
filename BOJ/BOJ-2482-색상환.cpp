// 일단 처음 혼자 생각한 DP. DP 재귀 스타일이 O(N)이다

#include<iostream>
#include<cstring>
#define ll long long

const ll MOD = 1000000003;
ll N, K, ans, cache[1005][1005][2];

ll DP(ll n, ll k, ll first){
    if(n == -1){
        ll tmp = 0;
        tmp += DP(n + 1, k - 1, 1) % MOD;
        for(int i = 2; i <= N; ++i)
            tmp += DP(n + i, k - 1, 0) % MOD;
        tmp %= MOD;
        return tmp;
    }
    if(first && n == N - 1) return 0;
    if(!k) return 1;
    if((N - n) / 2 < k) return 0;

    ll &ret = cache[n][k][first];
    if(ret != -1) return ret;

    ret = 0;
    for(ll i = 2; n + i < N; ++i){
        ret += DP(n + i, k - 1, first) % MOD;
    }
    ret %= MOD;
    return ret;
}

int main() {
    scanf("%lld\n%lld", &N, &K);
    memset(cache, -1, sizeof(cache));
    printf("%lld", DP(-1, K, 0));
    return 0;
}

// 타 블로그를 참고한 재귀 스타일. O(logN) 느낌으로 들어간다
// 색을 고른 것과 색을 고르지 않은 것 두 가지를 한꺼번에 탐색하는 방향으로
// 시간을 400ms 대에서 10ms대로 줄일 수 있었다
// 또한 덕지덕지 붙은 예외처리들이 조금 더 줄어서 상수 커팅 효과도 볼 수 있었다
#include<iostream>
#include<cstring>
#define ll long long

const ll MOD = 1000000003;
ll N, K, ans, cache[1005][1005][2];

ll DP(ll n, ll k, ll first){
    if(first && n == N - 1) return 0;
    if(k == 1) return N - n;
    if((N - n) / 2 < k) return 0;

    ll &ret = cache[n][k][first];
    if(ret != -1) return ret;

    ret = 0;
    ret += (DP(n + 2, k - 1, first) + DP(n + 1, k, first)) % MOD;
    ret %= MOD;
    return ret;
}

int main() {
    scanf("%lld\n%lld", &N, &K);
    memset(cache, -1, sizeof(cache));
    printf("%lld", DP(0, K, 0));
    return 0;
}
