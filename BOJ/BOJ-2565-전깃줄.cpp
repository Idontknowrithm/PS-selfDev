#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N, cache[105][505];
std::vector<pp> lines;

int DP(int idx, int high){
    if(idx == N) return 0;
    int &ret = cache[idx][high];
    if(ret != -1) return ret;
    ret = 0;

    ret = std::max(ret, DP(idx + 1, high));
    if(lines[idx].second > high)
        ret = std::max(ret, DP(idx + 1, lines[idx].second) + 1);
    
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        lines.push_back({a, b});
    }
    std::sort(lines.begin(), lines.end());
    memset(cache, -1, sizeof(cache));
    printf("%d", N - DP(0, 0));
    return 0;
}
