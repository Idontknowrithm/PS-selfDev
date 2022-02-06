// 점화식에 대한 규칙:
// (A)B 이런 식에서, A가 점점 길어지는 방식으로
// ex) DP(6) = DP(6 - 2)*DP(2 - 2) + DP(6 - 4)*DP(4 - 2) + DP(6 - 6)*DP(6 - 2)
//     (DP(4))DP(0) + 
//     (()())   ((()))
//     (DP(2))DP(2) +
//     (())()
//     (DP(0))DP(4)
//     ()()() ()(())

// (A)B 점화식에는 A가 참이면 (A)도 참이라는 규칙과, A와 B가 참이면 AB도
// 참이라는 규칙을 한 번에 담고있다

// DP 점화식을 설계할 때는 문제에 나와있는 규칙을 모두 점화식에 담을 수 있게끔
// 설계를 해야함을 생각하지

// 추가로 알면 좋을 
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
