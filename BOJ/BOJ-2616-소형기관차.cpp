#include<iostream>
#include<cstring>
#include<algorithm>

int N, M, sum[50005], cache[50005][3];

int DP(int cst, int train){
    if(!train) return 0;

    int &ret = cache[cst][train];
    if(ret != -1) return ret;
    ret = 0;
    if(cst - M >= (train - 1) * M)
        ret = std::max(ret, DP(cst - M, train - 1) + (sum[cst] - sum[cst - M]));
    if(cst - 1 >= train * M)
        ret = std::max(ret, DP(cst - 1, train));
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &sum[i + 1]);
        sum[i + 1] = sum[i] + sum[i + 1];
    }
        
    scanf("%d", &M);
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(N, 3));
    return 0;
}
