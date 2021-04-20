#include<iostream>
#include<vector>
#include<cmath>
#define ll long long

ll N, M, input, board[10][10];

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}
bool is_square(ll n){
    int tmp = sqrt((double)n);
    return (n == tmp * tmp);
}

int main() {
    scanf("%lld %lld", &N, &M);
    if(N == 0 || M == 0){
        printf("-1");
        return 0;
    }
    for(int i = 0; i < N; ++i){
        scanf("%lld", &input);
        for(int u = M - 1; u >= 0; --u){
            board[i][u] = input % 10;
            input /= 10;
        }
    }
    for(int a = 0; a < N; ++a){
        for(int b = 0; b < M; ++b){
            std::vector<int> tmp;
            for(int c = -N + 1; c < N; ++c){
                for(int d = -M + 1; d < M; ++d){
                    if(c == 0 && d == 0) continue;
                }
            }
        }
    }
    return 0;
}
