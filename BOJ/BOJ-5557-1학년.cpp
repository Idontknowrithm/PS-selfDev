#include<iostream>
typedef long long ll;

ll N, num[105], DP[105][25];

int main() {
    scanf("%lld", &N);
    for(ll i = 0; i < N; ++i)
        scanf("%lld", &num[i]);
    
    DP[0][num[0]] = 1;
    for(ll i = 0; i < N - 2; ++i){
        for(ll u = 0; u <= 20; ++u){
            if(DP[i][u]){
                if(u + num[i + 1] < 21)
                    DP[i + 1][u + num[i + 1]] += DP[i][u];
                if(u - num[i + 1] >= 0)
                    DP[i + 1][u - num[i + 1]] += DP[i][u];
            }
        }
    }
    printf("%lld", DP[N - 2][num[N - 1]]);
    return 0;
}
