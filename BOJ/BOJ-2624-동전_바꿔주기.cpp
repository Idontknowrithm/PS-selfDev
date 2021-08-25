#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define pp std::pair<int, int>

int T, K, cache[10005][105];
std::vector<pp> coins; // val, cnt

int DP(int val, int coin_idx){
    if(!val){
        cache[val][coin_idx] = 1;
        return 1;
    }
    if(coin_idx < 0) return 0;

    int &ret = cache[val][coin_idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i <= coins[coin_idx].second; ++i){
        if(val - coins[coin_idx].first * i >= 0)
            ret += DP(val - coins[coin_idx].first * i, coin_idx - 1);
    }
    return ret;
}

int main() {
    scanf("%d\n%d", &T, &K);
    for(int i = 0; i < K; ++i){
        int p, n;
        scanf("%d %d", &p, &n);
        coins.push_back({p, n});
    }
    std::sort(coins.begin(), coins.end());
    memset(cache, -1, sizeof(cache));
    
    printf("%d\n", DP(T, K - 1));
    
    return 0;
}
