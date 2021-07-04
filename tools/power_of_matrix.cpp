#include<iostream>
#include<vector>
#define ll long long
#define MAT std::vector<std::vector<ll>>

const int MAT_SIZE = 10, MOD = 1000;
ll N, B;
MAT matrix;

MAT matpow_cal(MAT a, MAT b){
    MAT tmp(MAT_SIZE);
    for(int i = 0; i < N; ++i){
        tmp[i].resize(MAT_SIZE);
        for(int u = 0; u < N; ++u){
            tmp[i][u] = 0;
            for(int k = 0; k < N; ++k){
                tmp[i][u] += a[i][k] * b[k][u];
                tmp[i][u] %= MOD;
            }
        }
    }
    return tmp;
}
MAT matpow(ll power){
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
