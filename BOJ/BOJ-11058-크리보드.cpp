// 문제 자체를 잘 분석해서 
// 기저 조건, 캐시테이블 디자인, 점화식
// 을 깔끔하게 설계할 수 있게끔 하는 연습을 해야한다
// Ctrl-A,C,V를 한 번에 묶어서 생각을 할 수 있었어야 했다
// ACV -> 현재 A의 수를 2배 한다
// ACVV -> 현재 A의 수를 3배 한다
// ACVV...(N개) -> 현재 A의 수를 N+1배 한다
// DP(idx): 버튼을 idx번 눌러서 만들 수 있는 A의 최대 개수
// 점화식: DP(idx-1)+1이 더 클 지, DP(idx-i-2)*(i+1)이 더 클 지 비교

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define ll long long

ll N, cache[105];

ll DP(int idx){
    if(idx <= 3) return idx;
    ll &ret = cache[idx];
    if(ret != -1) return ret;
    ret = DP(idx - 1) + 1;
    for(ll i = 1; i <= N; ++i){
        if(idx - i - 2 > 0)
            ret = std::max(ret, DP(idx - i - 2) * (i + 1));
    }
    return ret;
}

int main() {
    scanf("%lld", &N);
    memset(cache, -1, sizeof(cache));
    cache[0] = 0;
    printf("%lld", DP(N));
    return 0;
}
