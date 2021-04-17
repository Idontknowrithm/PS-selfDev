#include<iostream>
#define mod 1000000007

long long M, ans, a, b;

long long EEA(long long b, long long m){
    long long r1, r2, q, r, t, t1, t2;
    r1 = b;
    r2 = m;
    t1 = 0; t2 = 1;
    while(r1 != 1){
        q = r2 / r1;
        r = r2 - r1 * q;
        t = t1 - t2 * q;
        r2 = r1;
        r1 = r;
        t1 = t2;
        t2 = t;
    }
    t2 += (t2 < 0) ? m : 0;
    return t2;
}

int main() {
    
    scanf("%lld", &M);
    for(int i = 0; i < M; ++i){
        scanf("%lld %lld", &b, &a);

        ans += (a * EEA(b, mod)) % mod;
        ans %= mod;
    }
    printf("%lld", ans);
    return 0;
}
