// 첫 째 문제: 타일 채우기 1, 2와 비슷한 문제인 줄 착각하고 1차원 배열로 풀어보려 했음
// 처음에는 여기에서 새로 생긴 타일의 예외가
// ■■□
// □■■
// 만 있는 줄 알았는데
// ##$$##
//  ##$$##
// 이런 식으로 계속될 수 있어서
// 처음 점화식을 
// DP(n) = DP(n - 1) * 2 + DP(n - 2) * 3 + DP(n - 3) * 2
// 로 생각했으나 사실
// DP(n) = DP(n - 1) * 2 + DP(n - 2) * 3 + DP(n - 3) * 2 + DP(n - 4) * 2 + ... + DP(0) * 2
// 였다. 그러나 이런 식으로 DP를 디자인하면 시간초과가 나므로 2차원 배열 DP로 캐시부터 재설계 해야했다
// 둘 째 문제: 이상하게 30만 정도부터 세그폴트가 뜬다. 왜그런 지 모르겠는데 일단 재귀 DP에서 반복 DP로
// 바꾸었더니 문제는 해결됐다. 어디에서 세그폴트가 뜨는지 정확히 이해는 못했다. 그러나 재귀 DP만 고집할 것이
// 아니라 상황에 따라 반복DP도 설계할 줄 알아야함을 배웠다

#include<iostream>
#include<cstring>
#define ll long long

const ll mod = 1000000007;
ll N, cache[1000005][2];

ll DP(ll n){
    for(ll i = 3; i <= n; ++i){
        cache[i][1] = (cache[i - 1][1] + cache[i - 3][0]) % mod;
        cache[i][0] = (cache[i - 1][0] * 2 + cache[i - 2][0] * 3 + cache[i][1] * 2) % mod;
    }
    return cache[n][0];
}

int main() {
    memset(cache, -1, sizeof(cache));
    cache[0][0] = 0;
    cache[1][0] = 2;
    cache[2][0] = 7;
    cache[2][1] = 1;
    scanf("%lld", &N);
    printf("%lld\n", DP(N));
    return 0;
}
