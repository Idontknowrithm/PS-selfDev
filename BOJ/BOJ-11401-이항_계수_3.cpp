페르마의 소정리를 이용하여 이항계수 공식을 바꾸어 풀이
과연, 이 문제를 보고 바로 수학 공식이 필요할 것이라는 것을 알고,
페르마의 소정리가 필요하다는 것을 알아챈 후 공식을 바꾸어 풀 수 있을까?
그냥 페르마의 소정리가 있고, 이는 어떻게 사용하는지만 알아두는 것이
내가 할 수 있는 최선인 것 같다

#include<iostream>
#define ll long long

const ll MOD = 1000000007;
ll N, K;

ll fac(ll t){
    ll ret = 1;
    for(ll i = 1; i <= t; ++i){
        ret *= i;
        ret %= MOD;
    }
    return ret;
}
ll square(ll n, ll k){
    // ll tmp;
    if(k == 1)
        return n;
    // if(k & 1)
    //     return (square(n, k - 1) * n) % MOD;
    // else{
    //     tmp = square(n, k / 2);
    //     return (tmp * tmp) % MOD;
    // }
    ll ret = square(n, k / 2);
    if(k & 1){
        ret *= ret;
        ret %= MOD;
        ret *= n;
        ret %= MOD;
    }
    else{
        ret *= ret;
        ret %= MOD;
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &N, &K);

    ll ans = fac(N) % MOD;
    ll tmp = fac(K) * fac(N - K);
    tmp %= MOD;
    ans *= square(tmp, MOD - 2);
    ans %= MOD;
    printf("%lld", ans);
    return 0;
}
