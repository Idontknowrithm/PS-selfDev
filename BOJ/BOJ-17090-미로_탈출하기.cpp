#include<iostream>
#include<cstring>

const int MAX = 505;
int N, M, trace, maze[MAX][MAX], cache[MAX][MAX], visited[MAX][MAX];
std::string input;

int interpreter(char a){
    switch(a){
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'R':
            return 2;
        case 'L':
            return 3;
    }
    return -1;
}
int DP(int r, int c){
    if(r < 0 || r >= N || c < 0 || c >= M) return 1;
    if(visited[r][c] == trace) return 0;
    visited[r][c] = trace;
    int &ret = cache[r][c];
    if(ret != -1) return ret;

    if(maze[r][c] == 0) ret = DP(r - 1, c);
    else if(maze[r][c] == 1) ret = DP(r + 1, c);
    else if(maze[r][c] == 2) ret = DP(r, c + 1);
    else if(maze[r][c] == 3) ret = DP(r, c - 1);

    return ret;
}

int main() {
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        for(int u = 0; u < M; ++u)
            maze[i][u] = interpreter(input[u]);
    }
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        if(cache[i][u] == -1){
            ++trace;
            DP(i, u);
        }
    }
        

    int ans = 0;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        ans += (cache[i][u] == 1) ? 1 : 0;

    std::cout << ans;
    return 0;
}
