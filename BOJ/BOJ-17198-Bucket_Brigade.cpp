#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int ans = 100000, barn[15][15], visited[15][15];
pp start;

bool possible(int r, int c){
    return r >= 0 && r < 10 && c >= 0 && c < 10;
}
void BFS(){
    for(int i = 0; i < 10; ++i)
    for(int u = 0; u < 10; ++u)
        visited[i][u] = 100000;
    std::queue<pp> que;
    que.push(start);
    visited[start.first][start.second] = 0;
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];
            if(possible(R, C) && barn[R][C] != 1 && visited[R][C] > visited[r][c] + 1){
                visited[R][C] = visited[r][c] + 1;
                que.push({R, C});
            }
        }
    }
}

int main() {
    char c;
    for(int i = 0; i < 10; ++i){
        for(int u = 0; u < 10; ++u){
            scanf("%c", &c);
            if(c == '.') barn[i][u] = 0;
            if(c == 'R') barn[i][u] = 1;
            if(c == 'B') barn[i][u] = 2;
            if(c == 'L'){barn[i][u] = 3;
                start = {i, u};
            }            
        }
        getchar();
    }
    BFS();
    for(int i = 0; i < 10; ++i)
    for(int u = 0; u < 10; ++u)
        if(barn[i][u] == 2){
            printf("%d", visited[i][u] - 1);
            return 0;
        }
    return 0;
}
