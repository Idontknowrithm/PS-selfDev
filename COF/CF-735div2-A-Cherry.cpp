#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
 
ll T, N, ans, input[100005];
 
int main() {
    for(scanf("%lld", &T); T > 0; --T){
        ans = 0;
        scanf("%lld", &N);
        for(ll i = 0; i < N; ++i)
            scanf("%lld", &input[i]);
        
        for(ll i = 0; i < N - 1; ++i)
            ans = std::max(ans, input[i] * input[i + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
