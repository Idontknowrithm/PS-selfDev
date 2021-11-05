// 다 해봐야 하는데 인풋 크기가 적당히 클 때
// 반으로 잘라서 반씩 완탐하는 알고리즘 -> meet in the middle
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

ll N, C, things[35];
std::vector<ll> perm1, perm2;

int main() {
    scanf("%lld %lld", &N, &C);
    for(ll i = 0; i < N; ++i)
        scanf("%lld", &things[i]);
    if(N <= 15){
        for(ll i = 0; i < (1 << N); ++i){
            ll tmp = 0, idx = 0;
            for(ll u = i; u > 0; u >>= 1){
                tmp += (u & 1) ? things[idx] : 0;
                ++idx;
            }
            perm1.push_back(tmp);
        }
        std::sort(perm1.begin(), perm1.end());
        for(ll i = 0; i <= perm1.size(); ++i)
            if(perm1[i] > C || i == perm1.size()){
                printf("%lld", i);
                return 0;
            }
    }
    else{
        for(ll i = 0; i < (1 << 15); ++i){
            ll tmp = 0, idx = 0;
            for(ll u = i; u > 0; u >>= 1){
                tmp += (u & 1) ? things[idx] : 0;
                ++idx;
            }
            perm1.push_back(tmp);
        }
        for(ll i = 0; i < (1 << N - 15); ++i){
            ll tmp = 0, idx = 0;
            for(ll u = i; u > 0; u >>= 1){
                tmp += (u & 1) ? things[idx + 15] : 0;
                ++idx;
            }
            perm2.push_back(tmp);
        }
        std::sort(perm2.begin(), perm2.end());
        ll ans = 0;
        for(ll i = 0; i < perm1.size(); ++i){
            if(C - perm1[i] >= 0){
                ll bound = std::upper_bound(perm2.begin(), perm2.end(), C - perm1[i]) - perm2.begin();
                ans += bound;
            }
        }
        printf("%lld", ans);
    }
}
