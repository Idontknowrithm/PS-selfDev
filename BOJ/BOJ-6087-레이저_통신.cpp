// DP로 생각했는데 풀리지 않아서 해답 알고리즘 봄
// visited 배열을 DP 캐시처럼 이용하여 해결함

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define pp std::pair<int, int>

typedef struct{
    int r, c, mirror, dir;
}data;

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105, INF = 100005;
int H, W, map[MAX][MAX], cache[MAX][MAX][5];
std::string input;
std::vector<pp> Cs;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && map[r][c] != 1;
}

int route(){
    std::queue<data> bfs;
    for(int i = 0; i < 4; ++i){
        int R = Cs[0].first + y[i], C = Cs[0].second + x[i];
        if(possible(R, C))
            bfs.push({R, C, 0, i});
    }
    while(!bfs.empty()){
        data tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int R = tmp.r + y[i], C = tmp.c + x[i];
            int cur_mirror = tmp.mirror;
            if(i != tmp.dir) ++cur_mirror;
            if(possible(R, C) && cache[R][C][i] > cur_mirror){
                cache[R][C][i] = cur_mirror;
                bfs.push({R, C, cur_mirror, i});
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 4; ++i)
        ans = std::min(ans, cache[Cs[1].first][Cs[1].second][i]);
    return ans;
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
    for(int i = 0; i <= H; ++i)
    for(int u = 0; u <= W; ++u)
    for(int k = 0; k < 4; ++k)
        cache[i][u][k] = INF;
    
    std::cout << route();
    return 0;
}
