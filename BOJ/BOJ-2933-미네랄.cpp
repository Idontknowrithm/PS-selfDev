#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105;
int R, C, N, cave[MAX][MAX];

bool possible(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}
void solve(){
    std::cin >> N;
    for(int z = 0; z < N; ++z){
        int stick;
        std::cin >> stick;
        if(z & 1){
            for(int i = C - 1; i >= 0; --i){
                if(cave[R - stick][i] == 1){
                    cave[R - stick][i] = 0;
                    break;
                }
            }
        }
        else{
            for(int i = 0; i < C; ++i){
                if(cave[R - stick][i] == 1){
                    cave[R - stick][i] = 0;
                    break;
                }
            }
        }
        int visited[MAX][MAX] = {0,};
        int vi = 1;
        for(int i = 0; i < R; ++i)
        for(int u = 0; u < C; ++u){
            if(cave[i][u] == 1 && !visited[i][u]){
                std::queue<pp> bfs;
                bfs.push({i, u});
                visited[i][u] = vi;
                while(!bfs.empty()){
                    pp tmp = bfs.front();
                    bfs.pop();
                    for(int k = 0; k < 4; ++k){
                        int rr = tmp.first + y[k], cc = tmp.second + x[k];
                        if(possible(rr, cc) && !visited[rr][cc] && cave[rr][cc] == 1){
                            visited[rr][cc] = vi;
                            bfs.push({rr, cc});
                        }
                    }
                }
                ++vi;
            }
        }
        bool not_above[MAX] = {false,};
        for(int i = 0; i < C; ++i)
            not_above[visited[R - 1][i]] = true;
        for(int k = 1; k < vi; ++k){
            if(!not_above[k]){
                int tmp[MAX][MAX];
                bool go_to = false;
                while(1){
                    for(int i = 0; i < R; ++i)
                    for(int u = 0; u < C; ++u)
                        tmp[i][u] = cave[i][u];
                    for(int i = R - 1; i >= 0; --i){
                        for(int u = 0; u < C; ++u){
                            if(visited[i][u] == k){
                                if(i == R - 1 || visited[i + 1][u]){
                                    go_to = true;
                                    break;
                                }
                                else{
                                    tmp[i + 1][u] = tmp[i][u];
                                    tmp[i][u] = 0;
                                    visited[i + 1][u] = visited[i][u];
                                    visited[i][u] = 0;
                                }
                            }
                        }
                        if(go_to) break;
                    }
                    if(go_to) break;
                    for(int i = 0; i < R; ++i)
                    for(int u = 0; u < C; ++u)
                        cave[i][u] = tmp[i][u];
                }
            }
        }
    }
    for(int i = 0; i < R; ++i){
        for(int u = 0; u < C; ++u)
            if(cave[i][u] == 0) std::cout << ".";
            else                std::cout << "x";
        std::cout << "\n";
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> R >> C;
    for(int i = 0; i < R; ++i){
        std::string input;
        std::cin >> input;
        for(int u = 0; u < C; ++u){
            cave[i][u] = (input[u] == '.') ? 0 : 1;
        }
    }
    solve();

    return 0;
}
