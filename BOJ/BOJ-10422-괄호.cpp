// 점화식에 대한 규칙을 찾아보려 했으나 실패함. 카탈란 수로 알고있어야 할 듯
// 카탈란 수: sigma<i = 2; i <= N; i += 2> DP(N - i) * DP(i - 2)
// 카탈란 수를 Cn이라 했을 때 Cn의 의미는
// 1. 리프노드를 n/2+1개 가진 이진 트리의 개수
// 2. 노드를 n/2+1개 가진 트리의 개수
// 3. 괄호 개수가 n개이고, 짝이 맞는 문자열의 개수
// 4. n/2+2각형을 n/2개의 삼각형으로 나누는 방법의 개수

#include<iostream>
#include<cstring>
#define ll long long

const ll MOD = 1000000007;
ll T, L, cache[5005];

ll DP(ll l){
    if(l == 2 || !l) return 1;

    ll &ret = cache[l];
    if(ret != -1) return ret;
    ret = 0;
    for(ll i = 2; i <= l; i += 2){
        ret += DP(l - i) * DP(i - 2);
        ret %= MOD;
    }
    return ret % MOD;
}

int main() {
    memset(cache, -1, sizeof(cache));
    for(scanf("%lld", &T); T > 0; --T){
        scanf("%lld", &L);
        if(L & 1){
            printf("0\n");
            continue;
        }
        printf("%lld\n", DP(L));
    }
    return 0;
}
