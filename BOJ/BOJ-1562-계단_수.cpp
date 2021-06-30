#include<iostream>
#define ll long long

const ll MOD = 1000000000;
ll N, ans, cache[15][105][1025];
// end_val, N, bitmask

int main() {
    scanf("%lld", &N);
    for(ll i = 1; i <= 9; ++i){
        ++cache[i][1][1 << i];
    }
    for(ll i = 2; i <= N; ++i){
        for(ll u = 1; u <= 1023; ++u){
            if(cache[1][i - 1][u])
                cache[0][i][u | (1 << 0)] += cache[1][i - 1][u];
            cache[0][i][u | (1 << 0)] %= MOD;
        }
        for(ll k = 1; k < 9; ++k){
            for(ll u = 1; u <= 1023; ++u){
                if(cache[k - 1][i - 1][u])
                    cache[k][i][u | (1 << k)] += cache[k - 1][i - 1][u];
                cache[k][i][u | (1 << k)] %= MOD;
                if(cache[k + 1][i - 1][u])
                    cache[k][i][u | (1 << k)] += cache[k + 1][i - 1][u];
                cache[k][i][u | (1 << k)] %= MOD;
            }   
        }
        for(ll u = 1; u <= 1023; ++u){
            if(cache[8][i - 1][u])
                cache[9][i][u | (1 << 9)] += cache[8][i - 1][u];
            cache[9][i][u | (1 << 9)] %= MOD;
        }
    }
    for(int i = 0; i <= 9; ++i){
        ans += cache[i][N][1023];
        ans %= MOD;
    }
    printf("%lld", ans);
    return 0;
}
