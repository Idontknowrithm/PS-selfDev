#include<iostream>
#include<algorithm>

const int INF = 2000000000;
int T, N, mat[2][100005], sum[2][100005];

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &mat[0][i]);
        for(int i = 0; i < N; ++i)
            scanf("%d", &mat[1][i]);
        if(N == 1){
            printf("0\n");
            continue;
        }
        sum[0][N - 1] = mat[0][N - 1];
        sum[1][0] = mat[1][0];
        for(int i = 1; i < N; ++i){
            sum[0][N - i - 1] = sum[0][N - i] + mat[0][N - i - 1];
            sum[1][i] = sum[1][i - 1] + mat[1][i];
        }
        int ans = INF;
        for(int i = 0; i < N; ++i){
            if(i == 0)
                ans = std::min(ans, sum[0][1]);
            else if(i == N - 1)
                ans = std::min(ans, sum[1][N - 2]);
            else 
                ans = std::min(ans, std::max(sum[0][i + 1], sum[1][i - 1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
