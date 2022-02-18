#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, maze[105][105], trace[105][105];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
int BFS(){
    std::queue<pp> que;

    memset(trace, 1, sizeof(trace));
    que.push({0, 0});
    trace[0][0] = 0;

    while(!que.empty()){
        int r = que.front().first, c = que.front().second;

        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];
            
            if(possible(R, C) && trace[R][C] > trace[r][c] + maze[R][C]){
                trace[R][C] = trace[r][c] + maze[R][C];
                que.push({R, C});
            }
        }
    }
    return trace[N - 1][M - 1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> M >> N;
    for(int i = 0; i < N; ++i){
        std::string input;
        std::cin >> input;
        for(int u = 0; u < M; ++u)
            maze[i][u] = (input[u] == '0') ? 0 : 1;
    }

    printf("%d", BFS());

    return 0;
}
