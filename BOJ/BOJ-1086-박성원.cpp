#include<iostream>
#include<algorithm>
#include<cstring>

int N, K, cache[105][(1 << 15) + 5], mod[20], ten_mod[55];
std::string nums[20];

int GCD(int a, int b){
    if(a > b) std::swap(a, b);
    if(!b) return a;
    return GCD(b, a % b);
}

int modulo(std::string a, int k){
    int len = 0, tmp = k;
    while(tmp){
        tmp /= 10;
        ++len;
    }
    tmp = 0;
    if(len == 1)
        tmp = a[0] - '0';
    else if(len == 2)
        tmp = (a[0] - '0') * 10 + a[1] - '0';
    else
        tmp = (a[0] - '0') * 100 + (a[1] - '0') * 10 + a[2] - '0';

    tmp %= k;
    for(int i = len; i < a.size(); ++i){
        tmp *= 10;
        tmp += a[i] - '0';
        tmp %= k;
    }
    return tmp;
}

int DP(){
    cache[0][0] = 1;
    for(int u = 0; u < (1 << N) - 1; ++u){
        std::cout << "ok\n";
        for(int k = 0; k < N; ++k){
            std::cout << k << "\n";
            if(!(u & (1 << k))){
                int next = u | (1 << k);
                for(int i = 0; i < K; ++i){
                    int new_mod = ((i * ten_mod[nums[k].size()]) % K + modulo(nums[k], K)) % K;
                    cache[new_mod][next] += cache[i][u];
                }
            }
        }
    }
}

int main() {
    int gcd, all = 1, ans = 0;

    std::cin >> N;
    for(int i = 0; i < N; ++i)
        std::cin >> nums[i];
    std::cin >> K;
    for(int i = 0; i < N; ++i)
        mod[i] = modulo(nums[i], K);
    
    int ten = 1;
    ten_mod[0] = 1 % K;
    for(int i = 1; i <= 50; ++i){
        ten *= 10;
        ten_mod[i] = ten % K;
        ten %= K;
    }
    DP();
    for(int i = 1; i <= N; ++i)
        all *= i;
    ans = cache[(1 << N) - 1][0];
    gcd = GCD(all, ans);
    all /= gcd;
    ans /= gcd;

    std::cout << ans << "/" << all;
    return 0;
}
