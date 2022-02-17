#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, ans, arctic[305][305];
bool visited[305][305];

void melting(){
    int tmp_arctic[305][305] = {0,};

    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        if(arctic[i][u] > 0){
            int water = 0;
            for(int k = 0; k < 4; ++k)
                water += (!arctic[i + y[k]][u + x[k]]) ? 1 : 0;
            tmp_arctic[i][u] = water;
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        arctic[i][u] = (arctic[i][u] - tmp_arctic[i][u] < 0) ?
                        0 : arctic[i][u] - tmp_arctic[i][u];
    }

    ++ans;
}
bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
void BFS(int startr, int startc){
    std::queue<pp> que;
    que.push({startr, startc});
    visited[startr][startc] = true;

    while(!que.empty()){
        int r = que.front().first, c = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nextr = r + y[i], nextc = c + x[i];
            if(possible(nextr, nextc) && arctic[nextr][nextc] &&
               !visited[nextr][nextc]){
                visited[nextr][nextc] = true;
                que.push({nextr, nextc});
            }
        }
    }
}
bool is_broken(){
    int island = 0;
    
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(arctic[i][u] && !visited[i][u]){
            BFS(i, u);
            ++island;
        }
    
    return (island != 1);
}
bool doesnt_exist(){
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(arctic[i][u])
            return false;
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &arctic[i][u]);
    
    while(1){
        melting();
        if(doesnt_exist()){
            printf("0");
            return 0;
        }
        if(is_broken())
            break;
    }
    printf("%d", ans);

    return 0;
}
