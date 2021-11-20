#include<iostream>
#include<algorithm>
#include<cstring>

const int INF = 10000005;
int N, D[25][25], cache[25][(1 << 20) + 5];

int DP(int idle, int bit){
    if(idle == N + 1 || bit == (1 << (N + 1)) - 2)
        return 0;
    int &ret = cache[idle][bit];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 1; i <= N; ++i){
        if(!(bit & (1 << i))){
            ret = std::min(ret, DP(idle + 1, bit | (1 << i)) + D[idle][i]);
        }
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u)
        scanf("%d", &D[i][u]);
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(1, 0));
    return 0;
}
