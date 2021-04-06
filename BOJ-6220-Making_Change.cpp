#include<iostream>
#include<algorithm>

int C, N, coins[15], cache[2005];

int main() {
    scanf("%d %d", &C, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &coins[i]);
    }
    std::sort(coins, coins + N);
    cache[0] = 0;
    for(int i = 1; i < 2005; ++i) cache[i] = 99999;
    for(int i = 0; i < 1000; ++i){
        for(int u = 0; u < N; ++u){
            if(i + coins[u] <= 1000)
                cache[i + coins[u]] = (cache[i + coins[u]] > cache[i] + 1) ? 
                                       cache[i] + 1 : cache[i + coins[u]];
        }
    }
    printf("%d", cache[C]);
    return 0;
}
