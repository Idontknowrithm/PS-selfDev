// 나름 모든 경우의 수를 생각했다고 판단했으나 그보다 더 많은 경우의 수가 있었음
// 문제가 틀렸을 경우 이상한 곳 보다 핵심 알고리즘을 구현하는 코드에서 문제가 있을 확률이 높음

#include<iostream>
#include<algorithm>
#include<vector>

int main () {
    int N, K, DP[100001], coin[100];

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", &coin[i]);
    }
    std::sort(coin, coin + N);

    for(int i = 1; i <= K; ++i)
        DP[i] = 100000000;
    DP[0] = 0;
    for(int i = N - 1; i >= 0; --i){
        for(int u = coin[i]; u <= K; ++u)
            DP[u] = (DP[u] > DP[u - coin[i]] + 1) ? DP[u - coin[i]] + 1 : DP[u];
    }

    printf("%d", (DP[K] == 100000000) ? -1 : DP[K]);

    return 0;
}
