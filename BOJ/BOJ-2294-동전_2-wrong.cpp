#include<iostream>
#include<algorithm>
// normal wrong

#include<vector>

int main () {
    int N, K, inp, DP[10001] = {0,};
    std::vector<int> coin;

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", &inp);
        coin.push_back(inp);
    }
    std::sort(coin.begin(), coin.end());
    for(int i = 1; i < coin.size(); ++i)
        if(coin[i] == coin[i - 1])
            coin.erase(coin.begin() + i--);

    for(int i = 1; i <= K; ++i)
        DP[i] = 100000000;
    for(int i = coin.size() - 1; i >= 0; --i){
        for(int u = coin[i]; u <= K; u += coin[i])
            DP[u] = (DP[u] > DP[u - coin[i]] + 1) ? DP[u - coin[i]] + 1 : DP[u];
    }
    if(DP[K] != 100000000)
        printf("%d", DP[K]);
    else 
        printf("-1");
    
    return 0;
}
