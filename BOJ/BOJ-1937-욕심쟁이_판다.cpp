#include<iostream>
#include<cstring>
#include<algorithm>
#define R r+y[i]
#define C c+x[i]
const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, ans, bamboos[505][505], cache[505][505];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
int DP(int r, int c){
    int &ret = cache[r][c];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 4; ++i)
        if(possible(R, C) && bamboos[R][C] > bamboos[r][c])
            ret = std::max(ret, DP(R, C) + 1);
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &bamboos[i][u]);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(cache[i][u] == -1)
            ans = std::max(ans, DP(i, u));
        else 
            ans = std::max(ans, cache[i][u]);
    printf("%d", ans + 1);
    return 0;
}
