#include<iostream>
#include<queue>
#include<utility>

int N, M, bacon[101], graph[101][101], visited[101];

void find(int user){
    int baconNum = 0;
    std::queue<std::pair<int, int>> bfs;
    bfs.push({user, 0});
    visited[user] = 1;
    while(!bfs.empty()){
        for(int i = 1; i <= 100; ++i){
            if(graph[bfs.front().first][i] && !visited[i]){
                visited[i] = 1;
                bfs.push({i, bfs.front().second + 1});
            }
        }
        baconNum += bfs.front().second;
        bfs.pop();
    }
    bacon[user] = baconNum;
}

int main () {
    int row, col, min = 100000000;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &row, &col);
        graph[row][col] = graph[col][row] = 1;
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u)
            visited[u] = 0;
        find(i);
    }
    for(int i = 1; i <= N; ++i)
        min = (min > bacon[i] && bacon[i]) ? bacon[i] : min;
    for(int i = 1; i <= N; ++i)
        if(bacon[i] == min){
            printf("%d", i);
            return 0;
        }
}
