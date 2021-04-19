#include<iostream>

long long H, N, road[35][35];

int main(){
    long long sub;
    scanf("%lld %lld", &H, &N);
    sub = (H - N < 0) ? N - H : H - N;
    for(long long i = 0; i <= sub; ++i)
        road[0][i] = 1;
    for(long long i = 1; i <= sub; ++i){
        for(long long u = i; u <= sub; ++u){
            road[i][u] = road[i - 1][u] + road[i][u - 1];
        }
    }
    printf("%lld", road[sub][sub]);
    return 0;
}
