#include<iostream>
#include<vector>
#define MAT std::vector<std::vector<long long>>

long long N, B;
MAT matrix;

MAT matpow_cal(MAT a, MAT b){
    MAT tmp(10);
    for(int i = 0; i < N; ++i){
        tmp[i].resize(10);
        for(int u = 0; u < N; ++u){
            tmp[i][u] = 0;
            for(int k = 0; k < N; ++k){
                tmp[i][u] += a[i][k] * b[k][u];
                tmp[i][u] %= 1000;
            }
        }
    }
    return tmp;
}
MAT matpow(long long power){
    if(power == 1) return matrix;

    MAT tmp;
    if(power & 1){
        tmp = matpow(power - 1);
        tmp = matpow_cal(tmp, matrix);
    }
    else{
        tmp = matpow(power / 2);
        tmp = matpow_cal(tmp, tmp);
    }
    return tmp;
}

int main() {
    long long input;
    MAT ans;
    matrix.resize(10);
    scanf("%lld %lld", &N, &B);
    for(int i = 0; i < N; ++i){
            matrix[i].resize(10);
        for(int u = 0; u < N; ++u){
            scanf("%lld", &input);
            matrix[i][u] = input;
        }
    }
    ans = matpow(B);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < N; ++u)
            printf("%lld ", ans[i][u]);
        puts("");
    }
    return 0;
}
