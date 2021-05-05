#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long

ll T, N, cache[70][15];

ll ascending(){
    ll ans = 0;
    for(int i = 0; i < 10; ++i)
        cache[1][i] = 1;
    for(int i = 2; i <= N; ++i)
    for(int u = 0; u < 10; ++u)
    for(int k = 0; k <= u; ++k)
        cache[i][u] += cache[i - 1][k];
        
    for(int i = 0; i < 10; ++i)
        ans += cache[N][i];
    return ans;
}

int main() {
    for(scanf("%lld", &T); T > 0; --T){
        memset(cache, 0, sizeof(cache));
        scanf("%lld", &N);
        printf("%lld\n", ascending());
    }
    return 0;
}
