// 현재 지점에서 다음 고객에게 케익을 배달할 때 고객의 중심, 상하좌우 5개로 갈 수 있으므로
// 5개에 대한 경우에 대해서 각각 따로 분리하여 생각해줘야 하므로 cache도 2차원 배열을 쓰고
// DP 인자도 두 개로 해서 경우의 수를 분리했음
// ex) DP 인자를 하나로 하면 전에 있었던 곳의 경우의 수가 하나임(idx, 즉 전 고객의 중심)
//     두 개로 해야지 경우의 수가 5개가 됨(전 고객의 중심, 상하좌우)

#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define pp std::pair<ll, ll>

const ll x[5] = {0, 0, 1, 0, -1};
const ll y[5] = {0, 1, 0, -1, 0};
const ll MAX = 100005, INF = 30000000000;
ll N, cache[MAX][5];
pp customer[MAX];

bool possible(ll r, ll c){
    return r >= 1 && r <= MAX - 5 && c >= 1 && c <= MAX - 5;
}
ll DP(ll idx, ll dir){
    if(idx == N) return 0;

    ll &ret = cache[idx][dir];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < 5; ++i){
        if(possible(customer[idx + 1].first + x[i], customer[idx + 1].second + y[i])){
            ll dist = std::abs(customer[idx + 1].first + x[i] - (customer[idx].first + x[dir])) + 
                    std::abs(customer[idx + 1].second + y[i] - (customer[idx].second + y[dir]));
            ret = std::min(ret, dist + DP(idx + 1, i));
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
    printf("%lld", DP(0, 0));
    return 0;
}
