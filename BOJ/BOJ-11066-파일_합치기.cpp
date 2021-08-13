#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>
#define ll long long

const ll INF = 5000000000000;
int T, K;
ll input[505], sum[505], cache[505][505];

ll DP(int start, int end){
    if(start == end) return 0;
    ll &ret = cache[start][end];
    if(ret) return ret;

    ret = INF;
    for(int i = start; i < end; ++i){
        int tmp = (sum[i] - sum[start - 1]) + (sum[end] - sum[i]);
        ret = std::min(ret, DP(start, i) + DP(i + 1, end) + tmp);
    }
    return ret;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(cache, 0, sizeof(cache));
        scanf("%d", &K);
        for(int i = 1; i <= K; ++i){
            scanf("%lld", &input[i]);
            sum[i] = sum[i - 1] + input[i];
        }
        printf("%lld\n", DP(1, K));
    }
    return 0;
}
