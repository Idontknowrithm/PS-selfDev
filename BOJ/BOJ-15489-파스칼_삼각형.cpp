#include<iostream>

long long ans, R, C, W, c[35][35];

int main () {
    c[0][0] = 1;
    for(int i = 1; i <= 30; ++i){
        c[i][0] = 1;
        for(int u = 1; u < i; ++u)
            c[i][u] = c[i - 1][u - 1] + c[i - 1][u];
        c[i][i] = 1;
    }
    scanf("%lld %lld %lld", &R, &C, &W);
    for(int i = 0; i < W; ++i){
        for(int u = 0; u <= i; ++u){
            ans += c[R + i - 1][C + u - 1];
        }
    }

    printf("%lld", ans);

    return 0;
}
