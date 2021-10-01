#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105, INF = 10005;
int T, H, W, jail[MAX][MAX], visited[MAX][MAX], trace[MAX][MAX][3][2];
std::vector<pp> prisoners;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && jail[r][c] != 1;
}
void escape(int startr, int startc, int idx){
    std::queue<pp> bfs;
    bfs.push({startr, startc});
    
    trace[startr][startc][idx][0] = 0;
    trace[startr][startc][idx][1] = 0;
    visited[startr][startc] = (visited[startr][startc] != 0 && 
                               visited[startr][startc] != idx) ? 3 : idx;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int rr = tmp.first + y[i], cc = tmp.second + x[i];
            if(possible(rr, cc) && (visited[rr][cc] != idx && visited[rr][cc] != 3)){
                int cur_trace = trace[tmp.first][tmp.second][idx][0];
                int next_trace = trace[rr][cc][idx][0];
                if(jail[rr][cc] == 3){    
                    if(next_trace == -1 || next_trace > cur_trace + 1){
                        visited[rr][cc] = (visited[rr][cc] != 0) ? 3 : idx;
                        trace[rr][cc][idx][0] = trace[tmp.first][tmp.second][idx][0];
                        trace[rr][cc][idx][1] = trace[tmp.first][tmp.second][idx][1];
                        if(visited[rr][cc] == 3)
                            trace[rr][cc][idx][1] += 1;
                        bfs.push({rr, cc});
                    }
                }
                else{
                    if(next_trace == -1 || next_trace > cur_trace){
                        visited[rr][cc] = (visited[rr][cc] != 0) ? 3 : idx;
                        trace[rr][cc][idx][0] = trace[tmp.first][tmp.second][idx][0];
                        trace[rr][cc][idx][1] = trace[tmp.first][tmp.second][idx][1];
                        bfs.push({rr, cc});
                    }
                }
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
                    default:            break;
                }
            }
        }
        memset(trace, -1, sizeof(trace));
        escape(prisoners[0].first, prisoners[0].second, 1);
        escape(prisoners[1].first, prisoners[1].second, 2);
        int min1, min2, min3, tmp3;
        min1 = min2 = min3 = INF;
        for(int i = 0; i < W; ++i){
            switch(visited[0][i]){
                case 1:
                    min1 = std::min(min1, trace[0][i][1][0]); break;
                case 2:
                    min2 = std::min(min2, trace[0][i][2][0]); break;
                case 3:
                    tmp3 = trace[0][i][1][0] + trace[0][i][2][0] - 
                           trace[0][i][1][1];
                    min3 = std::min(min3, tmp3);
                default:                                      break;
            }
            switch(visited[H - 1][i]){
                case 1:
                    min1 = std::min(min1, trace[H - 1][i][1][0]); break;
                case 2:
                    min2 = std::min(min2, trace[H - 1][i][2][0]); break;
                case 3:
                    tmp3 = trace[H - 1][i][1][0] + trace[H - 1][i][2][0] - 
                           trace[H - 1][i][1][1];
                    min3 = std::min(min3, tmp3);
                default:                                          break;
            }
        }
        for(int i = 1; i < H - 1; ++i){
            switch(visited[i][0]){
                case 1:
                    min1 = std::min(min1, trace[i][0][1][0]); break;
                case 2:
                    min2 = std::min(min2, trace[i][0][2][0]); break;
                case 3:
                    tmp3 = trace[i][0][1][0] + trace[i][0][2][0] - 
                           trace[i][0][1][1];
                    min3 = std::min(min3, tmp3);
                default:                                      break;
            }
            switch(visited[i][W - 1]){
                case 1:
                    min1 = std::min(min1, trace[i][W - 1][1][0]); break;
                case 2:
                    min2 = std::min(min2, trace[i][W - 1][2][0]); break;
                case 3:
                    tmp3 = trace[i][W - 1][1][0] + trace[i][W - 1][2][0] - 
                           trace[i][W - 1][1][1];
                    min3 = std::min(min3, tmp3);
                default:                                          break;
            }
        }
        int ans = std::min(min1 + min2, min3);
        std::cout << ans << "\n";
    }
    return 0;
}
