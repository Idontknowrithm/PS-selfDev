#include<iostream>

int main() {
    long long N, fib[3] = {0, 1, 1};
    int i;
    scanf("%lld", &N);

    if(N < 3){
        printf("%lld", fib[N]);
        return 0;
    }
    for(i = 3; i <= N; ++i){
        fib[i % 3] = fib[(i + 1) % 3] + fib[(i + 2) % 3];
        fib[i % 3] %= 1000000007;
    }
    printf("%lld", fib[(i - 1) % 3]);

    return 0;
}
