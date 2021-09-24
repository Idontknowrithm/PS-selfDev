// 음... 일단.... 시간 초과 ㅠ

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 1505;
int R, C, fond[MAX][MAX], visited[MAX][MAX];
std::vector<pp> swans;

bool possible(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}
bool by_water(int r, int c){
    bool ans = false;
    for(int i = 0; i < 4; ++i){
        int rr = r + y[i], cc = c + x[i];
        if(possible(rr, cc) && (fond[rr][cc] == 0 || fond[rr][cc] == 5))
            ans = true;
    }
    return ans;
}
int melting(){
    int days = 0, vi1 = 1, vi2 = -1;
    std::queue<pp> bfs;
    bfs.push({swans[0].first, swans[0].second});
    visited[swans[0].first][swans[0].second] = vi1;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        if(tmp.first == swans[1].first && tmp.second == swans[1].second)
            return days;
        
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int rr = tmp.first + y[i], cc = tmp.second + x[i];
            if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != vi1){
                visited[rr][cc] = vi1;
                bfs.push({rr, cc});
            }
        }
    }
    ++vi1;
    std::queue<int> bfs1, bfs2;
    
    while(1){
        ++days;
        
        bfs1.push({swans[0].first, swans[0].second});
        bfs2.push({swans[1].first, swans[1].second});
        visited[swans[0].first][swans[0].second] = vi1;
        visited[swans[1].first][swans[1].second] = vi2;
        while(!bfs.empty()){
            pp tmp = bfs.front();
            if(tmp.first == swans[1].first && tmp.second == swans[1].second)
                return days;
            
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int rr = tmp.first + y[i], cc = tmp.second + x[i];
                if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != vi){
                    visited[rr][cc] = vi;
                    bfs.push({rr, cc});
                }
            }
        }
        ++vi;
        while(!bfs.empty())
            bfs.pop();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> R >> C;
    for(int i = 0; i < R; ++i){
        std::string input;
        std::cin >> input;
        for(int u = 0; u < C; ++u){
            if(input[u] == '.') 
                fond[i][u] = 0;
            else if(input[u] == 'X') 
                fond[i][u] = 1;
            else if(input[u] == 'L'){
                fond[i][u] = 5;
                swans.push_back({i, u});
            }
        }
    }
    std::cout << melting();
    return 0;
}
