// 일단 안되는 코드

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#define ll long long
#define pp std::pair<ll, ll>

ll T, K;

// ll min_len(std::vector<pp> &dots){
    
//     puts("sfe");
//     return ret;
// }

int main() {
    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        std::vector<pp> dots;

        scanf("%lld", &K);
        for(ll i = 0; i < 8; ++i){
            ll a, b;

            scanf("%lld %lld", &a, &b);
            dots.push_back({a, b});
        }

        std::vector<ll> x, y, s_x, s_y;
        std::vector<ll> x8 = {0, 0, K, 2 * K, 3 * K, 3 * K, 2 * K, K};
        std::vector<ll> y8 = {0, K, 2 * K, 2 * K, K, 0, -K, -K};
        ll xp, yp, ret = 1e10, perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        for(ll i = 0; i < 8; ++i){
            x.push_back(dots[i].first);
            y.push_back(dots[i].second);
        }
        do{
            ll tmp_ans = 0;

            for(ll i = 0; i < 8; ++i){
                s_x.push_back(x[perm[i]] - x8[i]);
                s_y.push_back(y[perm[i]] - y8[i]);
            }
            std::sort(s_x.begin(), s_x.end());
            std::sort(s_y.begin(), s_y.end());

            xp = s_x[3];
            yp = s_y[3];

            for(ll i = 0; i < 8; ++i){
                tmp_ans += std::abs((xp + x8[i]) - x[perm[i]]);
                tmp_ans += std::abs((yp + y8[i]) - y[perm[i]]);
            }
            for(int i = 0; i < 8; ++i)
                printf("%lld ", perm[i]);
            puts("");
            ret = std::min(ret, tmp_ans);
        }while(std::next_permutation(perm, perm + 8));
        
        printf("Case #%lld\n%lld\n", z, ret);
    }
    return 0;
}
