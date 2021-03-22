#include<iostream>

long long N, K, ans = 1;

int main() {
    scanf("%lld %lld", &N, &K);
    for(int i = N - 1; i > N - K; --i) ans *= i;
    for(int i = 1; i < K; ++1)     ans /= i;
    printf("%lld", ans);
    return 0;
}
