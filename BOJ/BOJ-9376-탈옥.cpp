// 생각을 잘못하면 상당히 어려워보임(사실 생각을 잘 하는 것부터 나에기는 어려움)
// 처음 생각: 두 탈옥수 위치에서 시작해서, 각 좌표에서 각 탈옥수의 열어야하는 문의
// 최소 개수를 저장하고, 그때 그때 방문 여부를 visited로 저장해서 두 탈옥수가 겹치는
// 부분은 또 따로 저장해서 몇 번 겹쳤는 지 저장해서 나중에 나갈 수 있는 모든 부분에 대해서
// 1번 탈옥수가 나갈 수 있는 최소, 2번 탈옥수가 나갈 수 있는 최소를 합하여 답을 내는데,
// 이 과정에서 visited 여부와 두 탈옥수가 겹친 여부를 사용하려 했음
// ㄴ 말로만 들어도 뭐가 뭔 지 모르겠고 코드로 옮기는 게 여간 어려운 게 아님

// 다르게 생각해서: 바깥을 '.'으로 둘러서 바깥에서 시작하는 가상의 한 명을 만듦
// ***
// *.*
// ***  을
// .....
// .***.
// .*.*.
// .***.
// ..... 로 만든다는 뜻
// 가상의 한 명, 탈옥수1, 탈옥수2 각 위치에서 시작해서 각 좌표로 갈 때 열어야하는 문의
// 최소 개수를 저장해둠. 그 후 3개의 2차원 캐시를 모두 합하고, 문이 있는 곳은 -2를 해줌
// (왜냐하면 문이 있는 곳에서 세 명이 만났다는 이야기니까 3개가 겹치므로 -2를 해줌)
// 각 행동들을 따로 계산한 후 합하는 방식으로 예외 사항을 최소로 없앰
// 논외로 여기에서 들 수 있는 의문점은 "3명이서 만나는 예외는 처리하면서 왜
// 2명이서 만나는 예외는 처리하지 않지?" 라고 생각할 수 있는데, 간단한 예제를 생각해보면
// 2명이서 만나다가 나머지 한 명이랑 만나는 경우는 존재하지 않음. 다시말해 모든 2명이서 만나다가
// 나머지 한 명이랑 만나는 경우는 셋이 따로 놀다가 마지막에 3명이 함께 만나는 경우로 전환될 수 있음
// 따라서 2명이서 만나다가 나머지 한 명이랑 만나는 경우는 생각해줄 필요가 없음

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int MAX = 105, INF = 10005;
int T, H, W, jail[MAX][MAX];
int trace[MAX][MAX], sum[MAX][MAX];
std::vector<pp> prisoners;

bool possible(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W && jail[r][c] != 1;
}
void prison_break(){
    std::queue<pp> bfs;
    for(int t = 0; t < 3; ++t){
        for(int i = 0; i < H; ++i)
        for(int u = 0; u < W; ++u)
            trace[i][u] = INF;
        int r, c;
        if(t <= 1){
            r = prisoners[t].first; c = prisoners[t].second;
        }
        else{
            r = 0; c = 0;
        }
        bfs.push({r, c});
        
        trace[r][c] = 0;
        while(!bfs.empty()){
            pp tmp = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int R = tmp.first + y[i], C = tmp.second + x[i];
                if(possible(R, C)){
                    if(jail[R][C] == 3 && trace[R][C] > trace[tmp.first][tmp.second] + 1){
                        trace[R][C] = trace[tmp.first][tmp.second] + 1;
                        bfs.push({R, C});
                    }
                    else if(jail[R][C] != 3 && trace[R][C] > trace[tmp.first][tmp.second]){
                        trace[R][C] = trace[tmp.first][tmp.second];
                        bfs.push({R, C});
                    }
                }
            }
        }
        for(int i = 0; i < H; ++i)
        for(int u = 0; u < W; ++u)
            sum[i][u] += trace[i][u];
    }
    for(int i = 0; i < H; ++i)
    for(int u = 0; u < W; ++u)
        if(jail[i][u] == 3)
            sum[i][u] -= 2;
}

int main() {
    for(std::cin >> T; T > 0; --T){
        memset(jail, 0, sizeof(jail));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < MAX; ++i)
        for(int u = 0; u < MAX; ++u)
            trace[i][u] = INF;
        
        std::cin >> H >> W;
        std::string input;
        for(int i = 1; i <= H; ++i){
            std::cin >> input;
            for(int u = 1; u <= W; ++u){
                switch(input[u - 1]){
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
        H += 2; W += 2;
        prison_break();
        int ans = INF;
        for(int i = 0; i < H; ++i)
        for(int u = 0; u < W; ++u)
            ans = std::min(ans, sum[i][u]);
        printf("%d\n", ans);
        prisoners.clear();
    }
    return 0;
}
