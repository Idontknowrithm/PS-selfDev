#include<iostream>
#define ll long long

const ll MOD = 1000000007;
ll N, K;

ll fac(ll n){
    ll ans = 1;
    for(ll i = n; i > 0; --i){
        ans *= n;
        ans %= MOD;
    }
    return ans;
}
ll square(ll n, ll k){
    ll tmp;
    if(k == 1) return n;
    tmp = square(n, k / 2);
    tmp %= MOD;
    if(k & 1){
        tmp *= tmp;
        tmp %= MOD;
        tmp *= n;
        tmp %= MOD;
        return tmp;
    }
    else {
        tmp *= tmp;
        tmp %= MOD;
        return tmp;
    }
}

int main() {
    scanf("%lld %lld", &N, &K);
    ll ans = ((fac(N) % MOD) * (square((fac(K) * fac(N - K)) % MOD, MOD - 2))) % MOD;
    printf("%lld", ans);
    return 0;
}
