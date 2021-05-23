// 2차원 배열에 대해서 평소 하던대로가 아닌 응용 방식으로
// 탐색 또는 인덱스 값 갱신을 할 때 생각 하면서 인덱스 위치에 대해
// 이해하면서 문제 

#include<iostream>

int N, M, pal_check[2005], DP[2005][2005];

int main() {
    int S, E;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &pal_check[i]);

    for(int i = 0; i < 2001; ++i)
        DP[i + 1][i] = 1;
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N - i + 1; ++u){
            if(i == 1){
                DP[u][i + u - 1] = 1;
            }
            else if(pal_check[u] != pal_check[i + u - 1]){
                DP[u][i + u - 1] = 0;
            }
            else{
                DP[u][i + u - 1] = DP[u + 1][i + u - 2];
            }
        }
    }
    
    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &S, &E);
        printf("%d\n", DP[S][E]);
    }
    return 0;
}
