#include<iostream>
#include<algorithm>
#include<cstring>

int N, K, subjects[10005][2], cache[1005][10005];

int DP(int idx, int time){
    if(idx == K) return 0;
    int &ret = cache[idx][time];
    if(ret != -1) return ret;

    ret = 0;
    if(time + subjects[idx][1] <= N)
        ret = std::max(ret, DP(idx + 1, time + subjects[idx][1]) + subjects[idx][0]);
    ret = std::max(ret , DP(idx + 1, time));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; ++i)
        scanf("%d %d", &subjects[i][0], &subjects[i][1]);
    printf("%d", DP(0, 0));
    return 0;
}
