// DFS로 하다가 시간초과가 남.
// BFS로 하되 DP 느낌으로 중복되는 연산을 줄임
// 주의: BFS 시 queue에서도 중복 연산이 발생돼 메모리 초과가 남

#include<iostream>
#include<queue>

typedef struct{
    int r, c;
}location;

int N, M, candy[1000][1000], ans[1000][1000];
std::queue<location> bfs;

bool in(int row, int col){
    return (row < N && row >= 0 && col < M && col >= 0);
}
void candyCatcher(){
    int R, C;
    bfs.push({0, 0});
    ans[0][0] = candy[0][0];
    while(!bfs.empty()){
        R = bfs.front().r;
        C = bfs.front().c;
        bfs.pop();
        
        if(in(R, C + 1) && ans[R][C] + candy[R][C + 1] > ans[R][C + 1]){
            ans[R][C + 1] = ans[R][C] + candy[R][C + 1];
            bfs.push({R, C + 1});
        }
        if(in(R + 1, C) && ans[R][C] + candy[R + 1][C] > ans[R + 1][C]){
            ans[R + 1][C] = ans[R][C] + candy[R + 1][C];
            bfs.push({R + 1, C});
        }
    }
}

int main () {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        scanf("%d", &candy[i][u]);
        ans[i][u] = -1;
    }

    candyCatcher();

    printf("%d", ans[N - 1][M - 1]);

    return 0;    
}
