#include<iostream>
#include<cstring>

long long T, N, DP[100005][4];

int main() {
    for(scanf("%lld", &T); T > 0; --T){
        scanf("%lld", &N);
        memset(DP, 0, 100005 * 4 * sizeof(long long));
        DP[1][1] = 1; DP[1][2] = 0; DP[1][3] = 0;
        DP[2][1] = 0; DP[2][2] = 1; DP[2][3] = 0; 
        DP[3][1] = 1; DP[3][2] = 1; DP[3][3] = 1;

        for(long long i = 4; i <= N; ++i){
            DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % 1000000009;
            DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % 1000000009;
            DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % 1000000009;
        }
        printf("%lld\n", (DP[N][1] + DP[N][2] + DP[N][3]) % 1000000009);
    }
    return 0;
}
