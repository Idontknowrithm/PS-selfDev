#include<iostream>

long long N, K, arr[35][35];

int main() {
    scanf("%lld %lld", &N, &K);
    for(int i = 0; i <= 30; ++i) arr[0][i] = 1;
    for(int i = 1; i < N; ++i){
        arr[i][0] = 1;
        for(int u = 1; u < K; ++u){
            arr[i][u] = arr[i - 1][u] + arr[i][u - 1];
        }
    }
    printf("%lld", arr[N - K][K - 1]);
    return 0;
}
