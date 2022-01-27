#include<iostream>
#include<algorithm>
#include<cstring>

int N, group[1005], cache[1005];

int DP(int idx){
    if(idx == N) return 0;

    int &ret = cache[idx];
    if(ret != -1) return ret;

    ret = 0;
    int max = -1, min = 10000005;
    for(int i = idx; i < N; ++i){
        max = std::max(max, group[i]);
        min = std::min(min, group[i]);
        ret = std::max(ret, DP(i + 1) + max - min);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &group[i]);

    printf("%d", DP(0));
}
