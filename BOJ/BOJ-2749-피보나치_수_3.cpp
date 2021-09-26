#include<iostream>
#include<vector>
#define ll long long

typedef std::vector<std::vector<ll>> matrix;

const ll MOD = 1000000;
ll N;
matrix unit(2);

matrix multiply(matrix a, matrix b){
    matrix ret = a;
    ret[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    ret[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    ret[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    ret[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    
    return ret;
}
matrix fib(ll n){
    if(n == 1) return unit;
    matrix tmp = fib(n / 2);
    if(n & 1){
        tmp = multiply(tmp, tmp);
        tmp = multiply(tmp, unit);
    }
    else{
        tmp = multiply(tmp, tmp);
    }
    return tmp;   
}

int main() {
    unit[0].push_back(1);
    unit[0].push_back(1);
    unit[1].push_back(1);
    unit[1].push_back(0);
    scanf("%lld", &N);
    if(N < 2)
        printf("%lld", N);
    else{
        matrix ans = fib(N);
        ans[0][1] %= MOD;
        printf("%lld", ans[0][1]);
    }
    return 0;
}
