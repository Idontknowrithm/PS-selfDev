#include<iostream>
#include<cstring>

const int MAX = 305, INF = 300000;
int N, M, marbles[MAX], sum[MAX], cache[MAX][MAX];

int DP(int idx, int packages){
    if(packages == 1) return sum[idx];

    int &ret = cache[idx][packages];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; idx - i >= packages - 1; ++i){
        ret = std::max(DP(idx - i, packages - 1), sum[idx] - sum[idx - i]);
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &marbles[i]);
        sum[i + 1] = sum[i] + marbles[i];
    }
        
    memset(cache, -1, sizeof(cache));
    int ans = INF;
    for(int i = 1; N - i >= M - 1; ++i){
        ans = std::min(ans, std::max(DP(N - i, M - 1), sum[N] - sum[N - i]));
    }
    printf("%d", ans);
    return 0;
}
