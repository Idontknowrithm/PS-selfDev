// 2차원으로 나타낼 수 있 그래프에서는 정점 N 개를 지날 수 있을 때(중복 가능)
// 정점 A에서 정점 B까지 갈 수 있는 경우의 수를 구할 때 행렬 제곱을 이용할 수 있음
#include<iostream>
#include<vector>
#define ll long long
#define MAT std::vector<std::vector<ll>>

const int MAT_SIZE = 10, MOD = 1000000007, N = 8;
ll P;
MAT matrix;

MAT init(){
    MAT mat = {{0, 1, 1, 0, 0, 0, 0, 0},
               {1, 0, 1, 1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1, 0, 0, 0},
               {0, 1, 1, 0, 1, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 1, 0},
               {0, 0, 0, 1, 1, 0, 0, 1},
               {0, 0, 0, 0, 1, 0, 0, 1},
               {0, 0, 0, 0, 0, 1, 1, 0}};
    return mat;
}
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

int main() {
    matrix = init();
    scanf("%lld", &P);
    matrix = matpow(P);
    printf("%lld", matrix[0][0]);
    return 0;
}
