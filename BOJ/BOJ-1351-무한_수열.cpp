#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long

ll N, P, Q, cache[105][105];

ll DP(ll n, ll p, ll q){
    if(!n) return 1;

    ll &ret = cache[p][q];
    if(ret != -1) return ret;
    
    ll np = n / P, nq = n / Q;
    ret = DP(np, p + 1, q) + DP(nq, p, q + 1);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld", DP(N, 0, 0));
    return 0;
}
