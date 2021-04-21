// 문제가 틀렸다
// 0은 제곱수가 아니지만 여기서는 정답으로 
#include<iostream>
#include<vector>
#include<cmath>

int N, M, ans = -1, input, board[10][10];

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}
bool is_square(int n){
    int tmp = (int)sqrt(n);
    tmp *= tmp;
    return (n == tmp);
}

int main() {
    scanf("%d %d", &N, &M);
    if(N == 0 || M == 0){
        printf("-1");
        return 0;
    }
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        for(int u = M - 1; u >= 0; --u){
            board[i][u] = input % 10;
            input /= 10;
        }
    }
    for(int a = 0; a < N; ++a){
        for(int b = 0; b < M; ++b){
            for(int c = -N; c < N; ++c){
                for(int d = -M; d < M; ++d){
                    if(c == 0 && d == 0) continue;
                    std::vector<int> tmp;
                    int row = a, col = b;
                    int tmp_ans = 0;
                    while(possible(row, col)){
                        tmp_ans *= 10;
                        tmp_ans += board[row][col];
                        ans = (is_square(tmp_ans) && ans < tmp_ans) ? tmp_ans : ans;
                        row += c; col += d;
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
