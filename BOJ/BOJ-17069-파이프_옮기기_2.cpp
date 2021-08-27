#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long

ll N, board[35][35], cache[35][35][3]; // 0: - 1: \ 2: |

ll DP(ll R, ll C, ll dir){
    if(R == N - 1 && C == N - 1) return 1;
    else if(R >= N || C >= N) return 0;

    ll &ret = cache[R][C][dir];
    if(ret != -1) return ret;
    ret = 0;
    if(dir == 0){
        if(board[R][C + 1] != 1)
            ret += DP(R, C + 1, 0);
        if(board[R + 1][C] != 1 && board[R + 1][C + 1] != 1 && board[R][C + 1] != 1)
            ret += DP(R + 1, C + 1, 1);
    }
    else if(dir == 1){
        if(board[R + 1][C] != 1)
            ret += DP(R + 1, C, 2);
        if(board[R + 1][C] != 1 && board[R + 1][C + 1] != 1 && board[R][C + 1] != 1)
            ret += DP(R + 1, C + 1, 1);
        if(board[R][C + 1] != 1)
            ret += DP(R, C + 1, 0);
    }
    else if(dir == 2){
        if(board[R + 1][C] != 1)
            ret += DP(R + 1, C, 2);
        if(board[R + 1][C] != 1 && board[R + 1][C + 1] != 1 && board[R][C + 1] != 1)
            ret += DP(R + 1, C + 1, 1);
    }
    return ret;
}

int main() {
    scanf("%lld", &N);
    for(ll i = 0; i < N; ++i)
    for(ll u = 0; u < N; ++u)
        scanf("%lld", &board[i][u]);
    memset(cache, -1, sizeof(cache));
    printf("%lld", DP(0, 1, 0));
    return 0;
}
