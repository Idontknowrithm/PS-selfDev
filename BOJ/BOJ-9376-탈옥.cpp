#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105;
int T, H, W, jail[MAX][MAX], visited[MAX][MAX], trace[MAX][MAX][3][2];
std::vector<pp> prisoners;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && jail[r][c] != 1;
}
void escape(int startr, int startc, int idx){
    std::queue<pp> bfs;
    bfs.push({startr, startc});
    bfs.pop();
    trace[startr][startc][idx][0] = 0;
    trace[startr][startc][idx][1] = 0;
    visited[startr][startc] = (visited[startr][startc] != 0 && 
                               visited[startr][startc] != idx) ? 3 : idx;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int rr = tmp.first + y[i], cc = tmp.second + x[i];
            if(possible(rr, cc)){
                
            }
        }
    }
}

int main() {
    for(std::cin >> T; T > 0; --T){
        std::cin >> H >> W;
        std::string input;
        for(int i = 0; i < H; ++i){
            std::cin >> input;
            for(int u = 0; u < W; ++u){
                switch(input[u]){
                    case '*':
                        jail[i][u] = 1; break;
                    case '.':
                        jail[i][u] = 0; break;
                    case '#':
                        jail[i][u] = 3; break;
                    case '$':
                        jail[i][u] = 4;
                        prisoners.push_back({i, u});
                        break;
                }
            }
        }
        memset(trace, -1, sizeof(trace));
        escape(prisoners[0].first, prisoners[0].second, 1);
        escape(prisoners[1].first, prisoners[1].second, 2);
    }
    return 0;
}
