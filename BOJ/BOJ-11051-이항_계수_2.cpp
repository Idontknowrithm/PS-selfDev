#include<iostream>
#include<cstring>

int N, K, cache[1005][1005];

int DP(int n, int k){
    if(!k || n == k) return 1;
    
    int &ret = cache[n][k];
    if(ret != -1) return ret;
    ret = (DP(n - 1, k - 1) + DP(n - 1, k)) % 10007;
    return ret % 10007;
}

int main() {
    scanf("%d %d", &N, &K);
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(N, K));
    return 0;
}
