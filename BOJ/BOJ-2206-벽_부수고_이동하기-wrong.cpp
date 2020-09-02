// normal wrong

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

typedef struct{
    int r, c, power, dist;
}data;
int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
int N, M, maze[1005][1005], visited[1005][1005];

bool possible(int r, int c){    
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int travel(){
    for(int i = 0; i < 1005; ++i)
    for(int u = 0; u < 1005; ++u)
        visited[i][u] = 999999999;
    std::queue<data> bfs;
    bfs.push({0, 0, 1, 1});
    visited[0][0] = 1;
    while(!bfs.empty()){
        int r = bfs.front().r, c = bfs.front().c;
        int p = bfs.front().power, d = bfs.front().dist;
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(visited[r + y[i]][c + x[i]] > d + 1 && possible(r + y[i], c + x[i]) && maze[r + y[i]][c + x[i]] == 0){
                bfs.push({r + y[i], c + x[i], p, d + 1});
                visited[r + y[i]][c + x[i]] = d + 1;
            }
            else if(p && visited[r + y[i]][c + x[i]] > d + 1 && possible(r + y[i], c + x[i]) && maze[r + y[i]][c + x[i]] == 1){
                bfs.push({r + y[i], c + x[i], 0, d + 1});
                visited[r + y[i]][c + x[i]] = d + 1;
            }
        }
    }
    if(visited[N - 1][M - 1] == 999999999)
        return -1;
    else 
        return visited[N - 1][M - 1];
}

int main () {
    char inp;
    scanf("%d %d", &N, &M); getchar();
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &inp);
            maze[i][u] = (inp == '0') ? 0 : 1;
        }
        getchar();
    }
    printf("%d", travel());    

    return 0;
}
