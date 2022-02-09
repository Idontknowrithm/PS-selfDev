#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

int T, N, M, coin[25], cache[25][10005];

int DP(int idx, int cost){
    if(cost == M) return 1;
    if(cost > M || idx == N) return 0;

    int &ret = cache[idx][cost];
    if(ret != -1) return ret;
    ret = 0;
    ret += DP(idx, cost + coin[idx]);
    ret += DP(idx + 1, cost);

    return ret;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &coin[i]);
        scanf("%d", &M);
        memset(cache, -1, sizeof(cache));
        printf("%d\n", DP(0, 0));
    }
    return 0;
}
