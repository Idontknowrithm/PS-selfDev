#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#define pp std::pair<int, int>
#define r first
#define c second

const int y[4] = {0, 1, 0, -1};
const int x[4] = {1, 0, -1, 0};
int N, L, R, ans, city[55][55];
bool visited[55][55];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
int can_move(int start_r, int start_c){
    visited[start_r][start_c] = true;
    int ret = city[start_r][start_c];
    std::queue<pp> que;
    std::vector<pp> trace;
    trace.push_back({start_r, start_c});
    
    que.push({start_r, start_c});
    while(!que.empty()){
        int rr = que.front().r, cc = que.front().c;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int RR = rr + y[i], CC = cc + x[i];
            
            if(possible(RR, CC) && !visited[RR][CC]){
                int diff = std::abs(city[rr][cc] - city[RR][CC]);

                if(diff >= L && diff <= R){
                    visited[RR][CC] = true;
                    ret += city[RR][CC];
                    que.push({RR, CC});
                    trace.push_back({RR, CC});
                }
            }
        }
    }
    ret /= trace.size();
    for(int i = 0; i < trace.size(); ++i)
        city[trace[i].r][trace[i].c] = ret;
    return (trace.size() == 1) ? 1 : 0;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &city[i][u]);
    
    while(1){
        memset(visited, false, sizeof(visited));
        int didnt_move = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            if(!visited[i][u])
                didnt_move += can_move(i, u);
        if(didnt_move == N * N)
            break;
        ++ans;
    }
    printf("%d", ans);
    return 0;
}
