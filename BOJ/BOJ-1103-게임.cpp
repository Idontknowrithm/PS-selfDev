// DFS로 백에지 찾는 알고리즘에 DP 붙인 것
// 함수 들어가고나서 trace 처리하고 함수 나갈 때 trace를 다시 지워줘야 했는데
// DP cache를 이용하다 보니 if(cache[r][c] == -1) return ret; 과정에서 
// trace를 지워주지 못하고 끝내버리는 부분이 있었음 이 부분을 간과하여 많은 시간을 허비함
// 알고가기: 함수가 끝나는 부분은 함수 마지막 return ret과 cache가 저장되어있을 때 끝나는 부분

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
    return (r >= 0 && r < N && c >= 0 && c < M);
}
int DP(int r, int c){
    if(loop) return 0;
    if(trace[r][c] == 10){
        loop = true;
        return 0;
    }
    trace[r][c] = 10;
    int &ret = cache[r][c];
    if(ret != -1) {
        trace[r][c] = -1;
        return ret;
    }
    ret = 0;
    for(int i = 0; i < 4; ++i){
        const int R = r + y[i] * board[r][c];
        const int C = c + x[i] * board[r][c];
        if(can(R, C)){
            ret = std::max(ret, DP(R, C));
        }
    }
    trace[r][c] = -1;
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
    DP(0, 0);
    
    printf("%d", (loop) ? -1 : cache[0][0]);
    return 0;
}
