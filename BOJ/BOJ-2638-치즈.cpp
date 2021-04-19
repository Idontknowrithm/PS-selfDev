#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#define pp std::pair<int, int>
#define jR tmp.first + y[i]
#define jC tmp.second + x[i]

int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
int N, M, board[105][105];

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}

void airing(){
    std::queue<pp> bfs;
    int visited[105][105];
    memset(visited, 0, 105 * 105 * sizeof(int));
    bfs.push({0, 0});
    visited[0][0] = 1;
    board[0][0] = 5;

    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(possible(jR, jC) && !visited[jR][jC] && board[jR][jC] != 1){
                visited[jR][jC] = 1;
                board[jR][jC] = 5;
                bfs.push({jR, jC});
            }
        }
    }
}
int melting(){
    int days = 0;
    while(1){
        int cheese = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < M; ++u)
            cheese += (board[i][u] == 1) ? 1 : 0;
        if(!cheese) break;

        airing();
        for(int i = 1; i < N - 1; ++i)
        for(int u = 1; u < M - 1; ++u){
            if(board[i][u] == 1){
                int around = 0;
                for(int k = 0; k < 4; ++k){
                    around += (board[i + y[k]][u + x[k]] == 5) ? 1 : 0;
                }
                board[i][u] = (around > 1) ? -1 : board[i][u];
            }
        }
        for(int i = 1; i < N - 1; ++i)
        for(int u = 1; u < M - 1; ++u)
            board[i][u] = (board[i][u] == -1) ? 0 : board[i][u];
        ++days;
    }
    return days;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &board[i][u]);
    
    printf("%d", melting());
    return 0;
}
