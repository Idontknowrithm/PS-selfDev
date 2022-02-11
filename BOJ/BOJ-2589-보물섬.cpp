#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, ans, map[55][55];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M && map[r][c] != 0;
}
int BFS(int sr, int sc){
    std::queue<pp> que;
    int tmp_ans = 0, visited[55][55];
    
    memset(visited, 1, sizeof(visited));
    que.push({sr, sc});
    visited[sr][sc] = 0;
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];
            if(possible(R, C) && visited[R][C] > visited[r][c] + 1){
                visited[R][C] = visited[r][c] + 1;
                que.push({R, C});
            }
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(visited[i][u] != visited[54][54])
            tmp_ans = std::max(tmp_ans, visited[i][u]);

    return tmp_ans;
}

int main() {
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            char c;
            scanf("%c", &c);
            map[i][u] = (c == 'W') ? 0 : 1;
        }
        getchar();
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(map[i][u])
            ans = std::max(ans, BFS(i, u));
            
    printf("%d", ans);
}
