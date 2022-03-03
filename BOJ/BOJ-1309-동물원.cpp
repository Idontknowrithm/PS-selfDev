#include<iostream>
#include<cstring>

const int MOD = 9901;
int N, cache[100005][3];

int DP(int idx, int where){
    if(idx == 1)
        return 1;
    
    int &ret = cache[idx][where];

    if(ret != -1) return ret;
    ret = DP(idx - 1, 0);
    if(where == 0)
        ret += (DP(idx - 1, 1) + DP(idx - 1, 2)) % MOD;
    else if(where == 1)
        ret += DP(idx - 1, 2) % MOD;
    else if(where == 2)
        ret += DP(idx - 1, 1) % MOD;

    return ret % MOD;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    printf("%d", (DP(N, 0) + DP(N, 1) + DP(N, 2)) % MOD);

    return 0;
}
