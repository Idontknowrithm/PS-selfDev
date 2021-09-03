#include<iostream>
#include<algorithm>
#include<cstring>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, level, cache[55][55], trace[55][55], board[55][55];
std::string input[55];
bool loop;

bool can(int r, int c){
    if(board[r][c] == -1) return false;
    // printf("%d\n", r >= 0 && r < N && c >= 0 && c < M);
    return (r >= 0 && r < N && c >= 0 && c < M);
}
int DP(int r, int c){
    if(loop) return 0;
    if(trace[r][c] == 1){
        loop = true;
        return 0;
    }
    trace[r][c] = 1;
    // puts("sfs");
    int &ret = cache[r][c];
    if(ret != -1) return ret;
    // for(int i = 0; i < N; ++i){
    //     for(int u = 0; u < M; ++u)
    //         printf("%d ", cache[i][u]);
    //     puts("");
    // }
    // puts("");
    ret = 0;
    for(int i = 0; i < 4; ++i){
        const int R = r + y[i] * board[r][c];
        const int C = c + x[i] * board[r][c];
        // printf("%d %d\n", R, C);
        //if(R < 0 || C < 0) continue;
        if(can(R, C)){
            ret = std::max(ret, DP(R, C));
        }
    }
    ++ret;
    return ret;
}

int main() {
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i)
        std::cin >> input[i];
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        board[i][u] = (input[i][u] == 'H') ? -1 : input[i][u] - '0';
    memset(cache, -1, sizeof(cache));
    memset(trace, -1, sizeof(trace));
    // for(int i = 0; i < N; ++i){
    //     for(int u = 0; u < M; ++u)
    //         printf("%d ", board[i][u] - '0');
    //     puts("");
    // }
    // puts("");
    DP(0, 0);
    
    printf("%d", (loop) ? -1 : cache[0][0]);
    return 0;
}
