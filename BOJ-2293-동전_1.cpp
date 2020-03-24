#include<iostream>
#include<algorithm>

int main () {
    int N, K, coin[100], DP[10001] = {1,};

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", &coin[i]);

    std::sort(coin, coin + N);

    for(int i = 0; i < N; ++i)
    for(int u = coin[i]; u <= K; u++)
        DP[u] += DP[u - coin[i]];

    printf("%d", DP[K]);
    return 0;
}
