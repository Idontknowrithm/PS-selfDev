#include<iostream>

int main () {
    int N, M, K, ans, arr[300][300], lc[4];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &arr[i][u]);
    for(scanf("%d", &K); K > 0; --K){
        scanf("%d %d %d %d", &lc[0], &lc[1], &lc[2], &lc[3]);
        ans = 0;
        for(int i = lc[0] - 1; i < lc[2]; ++i)
        for(int u = lc[1] - 1; u < lc[3]; ++u)
            ans += arr[i][u];
        printf("%d\n", ans);
    }
    return 0;
}
