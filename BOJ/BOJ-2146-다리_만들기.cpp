#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, island, ans = 10005, map[105][105], visited[105][105];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
void BFS_island(int sr, int sc){
    std::queue<pp> que;

    ++island;
    que.push({sr, sc});
    map[sr][sc] = island;
    visited[sr][sc] = 1;
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;

        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];
            if(possible(R, C) && map[R][C] && !visited[R][C]){
                visited[R][C] = 1;
                map[R][C] = island;
                que.push({R, C});
            }
        }
    }
}
void BFS_bridge(int sr, int sc, int i_idx){
    int trace[105][105] = {0,};
    std::queue<pp> que;
    
    que.push({sr, sc});
    trace[sr][sc] = 1;
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;

        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];

            if(trace[r][c] >= ans)
                break;
            if(possible(R, C)){
                if(map[R][C] && map[R][C] != i_idx){
                    ans = std::min(ans, trace[r][c]);
                    break;
                }
                if(!map[R][C] && 
                   (!trace[R][C] || trace[r][c] + 1 < trace[R][C])){
                    trace[R][C] = trace[r][c] + 1;
                    que.push({R, C});
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &map[i][u]);
    
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        if(!visited[i][u] && map[i][u]){
            BFS_island(i, u);
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        if(map[i][u])
            for(int k = 0; k < 4; ++k){
                int R = i + y[k], C = u + x[k];
                if(possible(R, C) && !map[R][C]){
                    BFS_bridge(i, u, map[i][u]);
                    break;
                }
            }
    }
    printf("%d", ans - 1);

    return 0;
}
