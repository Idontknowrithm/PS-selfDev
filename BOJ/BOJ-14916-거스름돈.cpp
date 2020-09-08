#include<iostream>

int N, dp[100005];

int find(){
    dp[1] = -1; dp[2] = 1; dp[3] = -1; dp[4] = 2; dp[5] = 1;
    if(N < 5)
        return dp[N];
    for(int i = 5; i <= N; ++i){
        dp[i] = (dp[i - 2] == -1) ? dp[i - 5] : (dp[i - 5] == -1) ? dp[i - 2] : (dp[i - 2] < dp[i - 5]) ? dp[i - 2] : dp[i - 5];
        ++dp[i];
    }
    return dp[N];
    
}

int main () {
    scanf("%d", &N);

    printf("%d", find());

    return 0;
}
