#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define pp std::pair<ll, ll>

const ll x[5] = {0, 0, 1, 0, -1};
const ll y[5] = {0, 1, 0, -1, 0};
const ll MAX = 100005, INF = 30000000000;
ll N, cache[MAX];
pp customer[MAX];

bool possible(ll r, ll c){
    return r >= 0 && r <= MAX - 5 && c >= 0 && c <= MAX - 5;
}
ll DP(ll idx){
    if(idx == N) return 0;

    ll &ret = cache[idx];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < 5; ++i){
        if(possible(customer[idx + 1].first + x[i], customer[idx + 1].second + y[i])){
            ll dist = std::abs(customer[idx + 1].first + x[i] - customer[idx].first) + 
                    std::abs(customer[idx + 1].second + y[i] - customer[idx].second);
            ret = std::min(ret, dist + DP(idx + 1));
        }
    }
    return ret;
}

int main() {
    scanf("%lld", &N);
    for(ll i = 0; i < N + 1; ++i){
        scanf("%lld %lld", &customer[i].first, &customer[i].second);
    }
    memset(cache, -1, sizeof(cache));
    printf("%lld", DP(0));
    return 0;
}
