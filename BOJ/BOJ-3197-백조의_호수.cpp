// 음... 일단.... 시간 초과 ㅠ

// 백조 만나는지 보고, N^2로 얼음 없애고 반복하다 보니까
// 1500^2를 수백 번 해서 TLE 나는 것 같다
// 이 때문에 각 백조에서 bfs 하면서 만나는 얼음 가장자리마다만 녹여주면서 탐색해봤는데
// 그냥 WA 뜬다...

// 무작정 bfs가 아니라 시간 제한을 고려하면서 최적화를 해야하기 때문에 최적화 과정에서
// 오류가 자주 뜨는 것 같음.

// #include<iostream>
// #include<queue>
// #include<algorithm>
// #include<vector>
// #define pp std::pair<int, int>

// const int y[4] = {1, 0, -1, 0};
// const int x[4] = {0, 1, 0, -1};
// const int MAX = 1505;
// int R, C, fond[MAX][MAX], visited[MAX][MAX];
// std::vector<pp> swans;

// bool possible(int r, int c){
//     return r >= 0 && r < R && c >= 0 && c < C;
// }
// bool by_water(int r, int c){
//     bool ans = false;
//     for(int i = 0; i < 4; ++i){
//         int rr = r + y[i], cc = c + x[i];
//         if(possible(rr, cc) && (fond[rr][cc] == 0 || fond[rr][cc] == 5))
//             ans = true;
//     }
//     return ans;
// }
// int melting(){
//     int days = 0, vi1 = 1, vi2 = -1;
//     std::queue<pp> bfs;
//     bfs.push({swans[0].first, swans[0].second});
//     visited[swans[0].first][swans[0].second] = vi1;
//     while(!bfs.empty()){
//         pp tmp = bfs.front();
//         if(tmp.first == swans[1].first && tmp.second == swans[1].second)
//             return days;
        
//         bfs.pop();
//         for(int i = 0; i < 4; ++i){
//             int rr = tmp.first + y[i], cc = tmp.second + x[i];
//             if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != vi1){
//                 visited[rr][cc] = vi1;
//                 bfs.push({rr, cc});
//             }
//         }
//     }
//     ++vi1;
//     std::queue<int> bfs1, bfs2;
    
//     while(1){
//         ++days;
        
//         bfs1.push({swans[0].first, swans[0].second});
//         bfs2.push({swans[1].first, swans[1].second});
//         visited[swans[0].first][swans[0].second] = vi1;
//         visited[swans[1].first][swans[1].second] = vi2;
//         while(!bfs.empty()){
//             pp tmp = bfs.front();
//             if(tmp.first == swans[1].first && tmp.second == swans[1].second)
//                 return days;
            
//             bfs.pop();
//             for(int i = 0; i < 4; ++i){
//                 int rr = tmp.first + y[i], cc = tmp.second + x[i];
//                 if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != vi){
//                     visited[rr][cc] = vi;
//                     bfs.push({rr, cc});
//                 }
//             }
//         }
//         ++vi;
//         while(!bfs.empty())
//             bfs.pop();
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL); std::cout.tie(NULL);

//     std::cin >> R >> C;
//     for(int i = 0; i < R; ++i){
//         std::string input;
//         std::cin >> input;
//         for(int u = 0; u < C; ++u){
//             if(input[u] == '.') 
//                 fond[i][u] = 0;
//             else if(input[u] == 'X') 
//                 fond[i][u] = 1;
//             else if(input[u] == 'L'){
//                 fond[i][u] = 5;
//                 swans.push_back({i, u});
//             }
//         }
//     }
//     std::cout << melting();
//     return 0;
// }

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #define pp std::pair<int, int>

// const int y[4] = {1, 0, -1, 0};
// const int x[4] = {0, 1, 0, -1};
// const int MAX = 1505;
// int R, C, fond[MAX][MAX], visited[MAX][MAX];
// std::vector<pp> swans;

// bool possible(int r, int c){
//     return r >= 0 && r < R && c >= 0 && c < C;
// }
// int solve(){
//     int days = 0;
//     std::queue<pp> swan1, swan2, edge1, edge2;
//     swan1.push({swans[0].first, swans[0].second});
//     swan2.push({swans[1].first, swans[1].second});
//     visited[swans[0].first][swans[0].second] = 1;
//     visited[swans[1].first][swans[1].second] = 2;
//     while(!swan1.empty()){
//         pp tmp = swan1.front();
//         swan1.pop();
//         for(int i = 0; i < 4; ++i){
//             int rr = tmp.first + y[i], cc = tmp.second + x[i];
//             if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != 1){
//                 if(visited[rr][cc] == 2)
//                     return days;
                
//                 swan1.push({rr, cc});
//                 visited[rr][cc] = 1;
//             }
//             else if(possible(rr, cc) && fond[rr][cc] == 1 && visited[rr][cc] != 1){
//                 edge1.push({rr, cc});
//                 visited[rr][cc] = 1;
//             }
//         }
//     }
//     while(!swan2.empty()){
//         pp tmp = swan2.front();
//         swan2.pop();
//         for(int i = 0; i < 4; ++i){
//             int rr = tmp.first + y[i], cc = tmp.second + x[i];
//             if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != 2){
//                 if(visited[rr][cc] == 1)
//                     return days;
                
//                 swan2.push({rr, cc});
//                 visited[rr][cc] = 2;
//             }
//             else if(possible(rr, cc) && fond[rr][cc] == 1 && visited[rr][cc] != 2){
//                 edge2.push({rr, cc});
//                 visited[rr][cc] = 2;
//             }
//         }
//     }
//     while(1){
//         ++days;
//         while(!edge1.empty()){
//             int r = edge1.front().first, c = edge1.front().second;
//             fond[r][c] = 0;
//             swan1.push({r, c});
//             edge1.pop();
//         }
//         while(!edge2.empty()){
//             int r = edge2.front().first, c = edge2.front().second;
//             fond[r][c] = 0;
//             swan2.push({r, c});
//             edge2.pop();
//         }
//         while(!swan1.empty()){
//             pp tmp = swan1.front();
//             swan1.pop();
//             for(int i = 0; i < 4; ++i){
//                 int rr = tmp.first + y[i], cc = tmp.second + x[i];
//                 if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != 1){
//                     if(visited[rr][cc] == 2)
//                         return days;
                    
//                     swan1.push({rr, cc});
//                     visited[rr][cc] = 1;
//                 }
//                 else if(possible(rr, cc) && fond[rr][cc] == 1 && visited[rr][cc] != 1){
//                     edge1.push({rr, cc});
//                     visited[rr][cc] = 1;
//                 }
//             }
//         }
//         while(!swan2.empty()){
//             pp tmp = swan2.front();
//             swan2.pop();
//             for(int i = 0; i < 4; ++i){
//                 int rr = tmp.first + y[i], cc = tmp.second + x[i];
//                 if(possible(rr, cc) && fond[rr][cc] != 1 && visited[rr][cc] != 2){
//                     if(visited[rr][cc] == 1)
//                         return days;
                    
//                     swan2.push({rr, cc});
//                     visited[rr][cc] = 2;
//                 }
//                 else if(possible(rr, cc) && fond[rr][cc] == 1 && visited[rr][cc] != 2){
//                     edge2.push({rr, cc});
//                     visited[rr][cc] = 2;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cin >> R >> C;
//     for(int i = 0; i < R; ++i){
//         std::string input;
//         std::cin >> input;
//         for(int u = 0; u < C; ++u){
//             if(input[u] == '.')
//                 fond[i][u] = 0;
//             else if(input[u] == 'X')
//                 fond[i][u] = 1;
//             else if(input[u] == 'L'){
//                 swans.push_back({i, u});
//                 fond[i][u] = 5;
//             }
//         }
//     }
//     std::cout << solve();
//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 1505;
int R, C, vi, fond[MAX][MAX];
std::vector<pp> swans;

bool possible(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}
int solve(){
    int days = 0;
    std::queue<pp> water, bfs;
    for(int i = 0; i < R; ++i)
    for(int u = 0; u < C; ++u)
        if(fond[i][u] != 1)
            water.push({i, u});
    
    bool visited[MAX][MAX] = {false,};

    bfs.push({swans[0].first, swans[0].second});
    visited[swans[0].first][swans[0].second] = true;
    while(1){
        std::queue<pp> edge;
        bool can_we_meet = false;

        while(!bfs.empty()){
            pp tmp = bfs.front();
            bfs.pop();
            if(tmp.first == swans[1].first && tmp.second == swans[1].second){
                can_we_meet = true;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int rr = tmp.first + y[i], cc = tmp.second + x[i];
                if(possible(rr, cc) && !visited[rr][cc]){
                    visited[rr][cc] = true;
                    if(fond[rr][cc] == 1){
                        edge.push({rr, cc});
                        continue;
                    }
                    bfs.push({rr, cc});
                }
            }
        }
        if(can_we_meet) break;

        bfs = edge;
        int water_size = water.size();
        while(water_size--){
            pp tmp = water.front();
            water.pop();
            for(int i = 0; i < 4; ++i){
                int rr = tmp.first + y[i], cc = tmp.second + x[i];
                if(possible(rr, cc) && fond[rr][cc] == 1){
                    fond[rr][cc] = 0;
                    water.push({rr, cc});
                }
            }
        }
        ++days;
    }
    return days;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

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
    std::cout << solve();
    return 0;
}
