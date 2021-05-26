// 입력 값의 범위들 꼼꼼히 체크하자...
// 선형적인 알고리즘을 생각하다 조금 비효율적일 것 같으면
// 탐색 방향을 반대로 바꿔보는 것도 좋을 

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define ll long long
#define pp std::pair<ll, ll>

ll N, K, ans, bag[300005];
pp jewels[300005];
std::priority_queue<ll> pque;

int main() {
    ll ia, ib;
    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%lld %lld", &ia, &ib);
        jewels[i] = {ia, ib};
    }
    for(int i = 0; i < K; ++i)
        scanf("%lld", &bag[i]);
    std::sort(jewels, jewels + N);
    std::sort(bag, bag + K);
    int ptr = 0;
    for(int i = 0; i < K; ++i){
        int cut = bag[i];
        for(; jewels[ptr].first <= cut && ptr < N; ++ptr)
            pque.push(jewels[ptr].second);
        if(!pque.empty()){
            ans += pque.top();
            pque.pop();
        }
    }
    printf("%lld", ans);
    return 0;
}
