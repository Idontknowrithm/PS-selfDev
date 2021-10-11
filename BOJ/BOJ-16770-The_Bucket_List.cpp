#include<iostream>

int N, buckets[105], cows[105][1005];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int start, end;
        scanf("%d %d %d", &start, &end, &buckets[i]);
        for(int u = start; u <= end; ++u)
            cows[i][u] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 1001; ++i){
        int tmp = 0;
        for(int u = 0; u < N; ++u)
            if(cows[u][i])
                tmp += buckets[u];
        ans = (ans < tmp) ? tmp : ans;
    }
    printf("%d", ans);
    return 0;
}
