#include<iostream>
#include<algorithm>

int N, M, ans, board[1005][1005];

bool possible(int r, int c){
    return(r >= 0 && r < N && c >= 0 && c < M);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        for(int u = 0; u < M; ++u){
            board[i][u] = input[u] - '0';
        }
    }
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            if(board[i][u] && possible(i - 1, u) &&
               possible(i, u - 1) && possible(i - 1, u - 1))
                board[i][u] = std::min(std::min(board[i - 1][u], board[i][u - 1]), board[i - 1][u - 1]) + 1;
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        ans = (board[i][u] > ans) ? board[i][u] : ans;
    std::cout << ans * ans;
    return 0;
}
