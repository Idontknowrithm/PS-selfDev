#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105, INF = 100005;
int H, W, map[MAX][MAX], visited[MAX][MAX], cache[MAX][MAX][5];
std::string input;
std::vector<pp> Cs;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && map[r][c] != 1;
}
int DP(int r, int c, int prev){
    if(r == Cs[1].first && c == Cs[1].second) return 0;

    int &ret = cache[r][c][prev];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = 0; i < 4; ++i){
        int R = r + y[i], C = c + x[i];
        if(possible(R, C) && !visited[R][C]){
            if(prev == 4 || prev == i){
                visited[R][C] = 1;
                ret = std::min(ret, DP(R, C, i));
                visited[R][C] = 0;
            }   
            else{
                visited[R][C] = 1;
                ret = std::min(ret, 1 + DP(R, C, i));
                visited[R][C] = 0;
            }
        }
    }
    return ret;
}

int main() {
    std::cin >> W >> H;
    for(int i = 0; i < H; ++i){
        std::cin >> input;
        for(int u = 0; u < W; ++u)
            if(input[u] == '.')
                map[i][u] = 0;
            else if(input[u] == '*')
                map[i][u] = 1;
            else if(input[u] == 'C'){
                map[i][u] = 2;
                Cs.push_back({i, u});
            }
    }
    memset(cache, -1, sizeof(cache));
    visited[Cs[0].first][Cs[0].second] = 1;
    std::cout << DP(Cs[0].first, Cs[0].second, 4);
    return 0;
}
