#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define ll long long
#define pp std::pair<ll, ll>

ll N, ans = 1, erathos[1000005];
std::vector<pp> phi;

int main(){
    for(int i = 2; i <= 1000; ++i){
        for(int u = i + i; u < 1000005; u += i)
            erathos[u] = 1;
    }
    scanf("%lld", &N);
    for(ll i = 2; i <= 1000000; ++i){
        if(erathos[i]) continue;
        ll power = 0;
        while(!(N % i)){
            ++power;
            N /= i;
        }
        if(power)
            phi.push_back({i, power});
    }
    for(int i = 0; i < phi.size(); ++i){
        ll tmp_power = 1;
        for(ll u = 1; u < phi[i].second; ++u)
            tmp_power *= phi[i].first;
        tmp_power *= phi[i].first - 1;
        ans *= tmp_power;
    }
    if(N != 1)
        ans *= N - 1;
    printf("%lld", ans);
    return 0;
}
