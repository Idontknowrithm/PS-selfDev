#include<iostream>

int T, N, erathos[20000];

int main() {
    for(int i = 2; i < 20000; ++i)
        erathos[i] = 1;
    for(int i = 2; i < 10000; ++i){
        for(int u = i + i; u < 20000; u += i)
            erathos[u] = 0;
    }
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        int a, b;
        for(int i = 2; i <= N / 2; ++i){
            if(erathos[i] && erathos[N - i]){
                a = i; b = N - i;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
