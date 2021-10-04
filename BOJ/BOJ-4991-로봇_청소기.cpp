// trash 벡터가 ans가 -1일 때는 clear 되지 않아서 오류가 뜸
// 조건문 등으로 for문이나 함수 등이 종료될 부분이 하나 이상일 때,
// 종료 부분에서 적용한 것들이 모든 종료 부분에서 적용되는지를 점검해줘야함

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 25, INF = 5000;
int H, W, N, room[MAX][MAX], rtot[MAX], ttot[MAX][MAX];
pp robot;
std::vector<pp> trash;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && room[r][c] != 1;
}
bool possible_to_clean(){
    int trashes = 0;
    bool visited[MAX][MAX] = {false,};
    std::queue<pp> bfs;
    bfs.push(robot);
    visited[robot.first][robot.second] = true;
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int R = tmp.first + y[i], C = tmp.second + x[i];
            if(possible(R, C) && !visited[R][C]){
                if(room[R][C] == 3)
                    ++trashes;
                visited[R][C] = true;
                bfs.push({R, C});
            }
        }
    }
    return (trashes == N);
}
void path_finder(){
    int visited[MAX][MAX];
    // robot to trash
    for(int t = 0; t < N; ++t){
        for(int i = 0; i < H; ++i)
        for(int u = 0; u < W; ++u)
            visited[i][u] = INF;
        std::queue<pp> bfs;
        bfs.push(robot);
        visited[robot.first][robot.second] = 0;
        while(!bfs.empty()){
            pp tmp = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int R = tmp.first + y[i], C = tmp.second + x[i];
                int r = tmp.first, c = tmp.second;
                if(possible(R, C) && visited[R][C] > visited[r][c] + 1){
                    visited[R][C] = visited[r][c] + 1;
                    bfs.push({R, C});
                }
            }
        }
        rtot[t] = visited[trash[t].first][trash[t].second];
    }
    // trash to trash
    for(int t1 = 0; t1 < N - 1; ++t1){
        for(int t2 = t1 + 1; t2 < N; ++t2){
            for(int i = 0; i < H; ++i)
            for(int u = 0; u < W; ++u)
                visited[i][u] = INF;
            std::queue<pp> bfs;
            bfs.push(trash[t1]);
            visited[trash[t1].first][trash[t1].second] = 0;
            while(!bfs.empty()){
                pp tmp = bfs.front();
                bfs.pop();
                for(int i = 0; i < 4; ++i){
                    int R = tmp.first + y[i], C = tmp.second + x[i];
                    int r = tmp.first, c = tmp.second;
                    if(possible(R, C) && visited[R][C] > visited[r][c] + 1){
                        visited[R][C] = visited[r][c] + 1;
                        bfs.push({R, C});
                    }
                }
            }
            ttot[t1][t2] = visited[trash[t2].first][trash[t2].second];
            ttot[t2][t1] = visited[trash[t2].first][trash[t2].second];
        }
    }
}
int solve(){
    int tmp, ret = INF;
    int perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do{
        tmp = rtot[perm[0]];
        for(int i = 1; i < N; ++i){
            tmp += ttot[perm[i - 1]][perm[i]];
        }
        ret = std::min(ret, tmp);
    }while(std::next_permutation(perm, perm + N));
    return ret;
}

int main() {
    while(1){
        trash.clear();
        std::cin >> W >> H;
        if(!W && !H) break;

        for(int i = 0; i < H; ++i){
            std::string input;
            std::cin >> input;
            for(int u = 0; u < W; ++u){
                if(input[u] == '.')
                    room[i][u] = 0;
                else if(input[u] == 'x')
                    room[i][u] = 1;
                else if(input[u] == 'o'){
                    room[i][u] = 2;
                    robot = {i, u};
                }
                else if(input[u] == '*'){
                    room[i][u] = 3;
                    trash.push_back({i, u});
                }
            }
        }
        N = trash.size();
        if(!N){
            std::cout << "0\n";
            continue;
        }
        if(!possible_to_clean()){
            std::cout << "-1\n";
            continue;
        }
        path_finder();
        int ans = solve();
        std::cout << ans << "\n";
    }
    return 0;
}
