#include<iostream>
#include<vector>
#define mat std::vector<std::vector<long long>>

long long N;
const long long mod = 1e9 + 7;
mat init;

mat matcal(mat &a, mat &b){
    mat tmp(2);
    tmp[0].resize(2);
    tmp[1].resize(2);
    for(int i = 0; i < 2; ++i){
        for(int u = 0; u < 2; ++u){
            tmp[i][u] = 0;
            for(int k = 0; k < 2; ++k){
                tmp[i][u] += a[i][k] * b[k][u];
                tmp[i][u] %= mod;
            }
        }
    }
    return tmp;
}
mat bigfib(long long N){
    if(N <= 1) return init;
    if(N & 1){
        mat tmp = bigfib(N - 1);
        return matcal(tmp, init);
    }
    else{
        mat tmp = bigfib(N / 2);
        return matcal(tmp, tmp);
    }
}

int main() {
    scanf("%lld", &N);
    init.resize(2);
    init[0].resize(2);
    init[1].resize(2);
    init[0][0] = init[0][1] = init[1][0] = 1;
    init[1][1] = 0;
    mat ans = bigfib(N);
    printf("%lld", (!N) ? 0 : ans[1][0]);

    return 0;
}
