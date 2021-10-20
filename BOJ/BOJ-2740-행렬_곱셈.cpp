#include<iostream>

int N, M, K, A[105][105], B[105][105], ans[105][105];

void mat_mul(){
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < K; ++u)
    for(int k = 0; k < M; ++k)
        ans[i][u] += A[i][k] * B[k][u];    
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &A[i][u]);
    scanf("%d %d", &M, &K);
    for(int i = 0; i < M; ++i)
    for(int u = 0; u < K; ++u)
        scanf("%d", &B[i][u]);
    mat_mul();
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < K; ++u)
            printf("%d ", ans[i][u]);
        puts("");
    }
    return 0;
}
