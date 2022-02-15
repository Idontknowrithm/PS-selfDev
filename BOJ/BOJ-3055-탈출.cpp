#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int R, C, flood[55][55], trace[55][55];
std::string map[55];
pp start, dest;

bool possible(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C && 
           map[r][c] != 'X';
}
void BFS_flood(){
    std::queue<pp> que;
    for(int i = 0; i < R; ++i)
    for(int u = 0; u < C; ++u){
        if(map[i][u] == '*'){
            flood[i][u] = 0;
            que.push({i, u});
        }
    }
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nextr = r + y[i], nextc = c + x[i];
            if(possible(nextr, nextc) && map[nextr][nextc] != 'D' &&
               flood[nextr][nextc] == -1){
                flood[nextr][nextc] = flood[r][c] + 1;
                que.push({nextr, nextc});
            }
        }
    }
}
void BFS_go(){
    std::queue<pp> que;

    que.push(start);
    trace[start.first][start.second] = 0;

    while(!que.empty()){
        int r = que.front().first, c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; ++i){
            int nextr = r + y[i], nextc = c + x[i];
            if(possible(nextr, nextc) && trace[r][c] + 1 < trace[nextr][nextc] &&
               (trace[r][c] < flood[nextr][nextc] - 1 || flood[nextr][nextc] == -1)){
                trace[nextr][nextc] = trace[r][c] + 1;
                que.push({nextr, nextc});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> R >> C;
    for(int i = 0; i < R; ++i){
        std::cin >> map[i];
        for(int u = 0; u < C; ++u){
            if(map[i][u] == 'S')
                start = {i, u};
            if(map[i][u] == 'D')
                dest = {i, u};
        }
    }
    
    memset(flood, -1, sizeof(flood));
    BFS_flood();

    memset(trace, 1, sizeof(trace));
    BFS_go();

    if(trace[dest.first][dest.second] == trace[54][54])
        std::cout << "KAKTUS";
    else 
        std::cout << trace[dest.first][dest.second];
    
    return 0;
}
