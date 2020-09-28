#include<iostream>
#include<algorithm>
#include<queue>

int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
int N, M, ans, visited[105][105];
char emacs[105][105];

bool possible(int r, int c){
    return (emacs[r][c] == '*' && r >= 0 && r < N && c >= 0 && c < M);
}
void find(int r, int c){
    int row, col;
    std::queue<std::pair<int, int>> bfs;
    bfs.push({r, c});
    visited[r][c] = 1;
    while(!bfs.empty()){
        row = bfs.front().first;
        col = bfs.front().second;
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(possible(row + y[i], col + x[i]) && !visited[row + y[i]][col + x[i]]){
                bfs.push({row + y[i], col + x[i]});
                visited[row + y[i]][col + x[i]] = 1;
            }
        }
    }
    ++ans;
}

int main () {
    scanf("%d %d\n", &N, &M);

    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u)
            scanf("%c", &emacs[i][u]);
        getchar();
    }
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            if(emacs[i][u] == '*' && !visited[i][u])
                find(i, u);
        }
    }
    printf("%d", ans);

    return 0;
}
