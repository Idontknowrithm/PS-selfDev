// int -> long long에 걸렸다

#include<iostream>
#include<queue>
#include<vector>
#define ll long long

ll N;
std::vector<ll> roads, gs;

int main() {
    scanf("%lld", &N);
    for(ll i = 0; i < N - 1; ++i){
        ll tmp;
        scanf("%lld", &tmp);
        roads.push_back(tmp);
    }
    for(ll i = 0; i < N; ++i){
        ll tmp;
        scanf("%lld", &tmp);
        gs.push_back(tmp);
    }
    ll ans = 0;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    for(ll i = 0; i < N - 1; ++i){
        pq.push(gs[i]);
        ll min = pq.top();
        ans += roads[i] * min;
    }
    printf("%lld", ans);
    return 0;
}
