#include<iostream>
#include<cstring>

int T, N, input[1005], sum[1005];
// input: 0 start, sum: 1 start
int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(input, 0, 1005 * (sizeof(int)));
        memset(sum, 0, 1005 * (sizeof(int)));
        scanf("%d", &N);

        for(int i = 0; i < N; ++i){
            scanf("%d", &input[i]);
            sum[i + 1] += input[i] + sum[i];
        }
        int max = -10000000;

        for(int i = 0; i < N; ++i){
            for(int u = 0; u < N - i; ++u){
                max = (max < sum[u + i + 1] - sum[u]) ? sum[u + i + 1] - sum[u] : max;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
