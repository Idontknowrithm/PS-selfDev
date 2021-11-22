자잘한 구현과 수학때문에 정말 풀기싫은 유형이다. 문자열에서
나머지를 구하는 함수에서 문제가 있어서 세그폴트가 뜬 것 같다

#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long

ll N, K, cache[105][(1 << 16)], mod[50], ten_mod[100];
std::string nums[50];

ll GCD(ll a, ll b){
    ll A, B;
    A = std::max(a, b);
    B = std::min(a, b);

    while(B){
        ll tmp = A % B;
        A = B;
        B = tmp;
    }
    return A;
}

ll modulo(std::string a, ll k){
    ll tmp = 0;
    for(ll i = 0; i < a.size(); ++i){
        tmp *= 10;
        tmp += a[i] - '0';
        tmp %= k;
    }
    return tmp;
}

void DP(){
    cache[0][0] = 1;
    for(ll u = 0; u < (1 << N) - 1; ++u){
        for(ll k = 0; k < N; ++k){
            if(!(u & (1 << k))){
                ll next = u | (1 << k);
                for(ll i = 0; i < K; ++i){
                    ll new_mod = ((i * ten_mod[nums[k].size()]) % K + mod[k]) % K;
                    cache[new_mod][next] += cache[i][u];
                }
            }
        }
    }
}

int main() {
    ll gcd, all = 1, ans = 0;

    std::cin >> N;
    for(ll i = 0; i < N; ++i)
        std::cin >> nums[i];
    std::cin >> K;
    for(ll i = 0; i < N; ++i)
        mod[i] = modulo(nums[i], K);
    
    ll ten = 1;
    ten_mod[0] = 1 % K;
    for(ll i = 1; i <= 60; ++i){
        ten *= 10;
        ten_mod[i] = ten % K;
        ten %= K;
    }
    DP();
    for(ll i = 1; i <= N; ++i)
        all *= i;
    ans = cache[0][(1 << N) - 1];
    gcd = GCD(all, ans);
    all /= gcd;
    ans /= gcd;

    std::cout << ans << "/" << all;
    return 0;
}
