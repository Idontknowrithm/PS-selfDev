#include<iostream>

long long T, N, fib[3] = {1, 1, 2};

int main() {
    for(scanf("%lld", &T); T > 0; --T){
        scanf("%lld", &N);
        fib[0] = 1;
        fib[1] = 1;
        fib[2] = 2;
        if(N < 3) printf("%lld\n", fib[N]);
        else{
            int f;
            for(f = 0; f < N - 2; ++f){
                fib[f % 3] = fib[(f + 1) % 3] + fib[(f + 2) % 3];
                fib[f % 3] %= 1000000007;
            }
            printf("%lld\n", fib[(--f) % 3]);
        }
    }
    return 0;
}
