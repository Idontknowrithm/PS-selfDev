// 생각지도 못한 오류
// 대회에서 이런 문제 만나면 바로 out 될 것 같음
// 정해에서는 뚫었을 때와 뚫지 않았을 때만을 구분했음

// 일단 처음 시도에서는 visited 배열을 만들어서 0과 1로만 구분했는데,
// 이렇게 했을 때는 마지막 maze[N-1][M-1]에 min 값이 들어왔는 지가 모호해서

// 두 번째 시도에서는 visited 배열을 DP배열로 바꿔봄.
// visited 배열에 그 점까지 올 때 까지의 dist를 저장해두었음.
// 이렇게 하면 될 줄 알았는데 안돼서, 여기서는 뚫었을 때와 아닐 때를 구분해줘야만 했음
// 뚫었을 때와 아닐 때를 어떻게 구분할 아이디어를 떠올릴 수 있었을까..?


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

typedef struct{
    int r, c, power, dist;
}data;
int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
int N, M, maze[1005][1005], visited[1005][1005][2];


bool possible(int r, int c){    
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int travel(){
    std::queue<data> bfs;

    bfs.push({0, 0, 1, 1});
    visited[0][0][0] = 1;
    while(!bfs.empty()){
        int r = bfs.front().r, c = bfs.front().c;
        int p = bfs.front().power, d = bfs.front().dist;
        if(r == N - 1 && c == M - 1)
            return d;
        for(int i = 0; i < 4; ++i){
            if(possible(r + y[i], c + x[i]) && !visited[r + y[i]][c + x[i]][!p] && maze[r + y[i]][c + x[i]] == 0){
                bfs.push({r + y[i], c + x[i], p, d + 1});
                visited[r + y[i]][c + x[i]][!p] = 1;
            }
            else if(possible(r + y[i], c + x[i]) && p && maze[r + y[i]][c + x[i]] == 1){
                bfs.push({r + y[i], c + x[i], 0, d + 1});
                visited[r + y[i]][c + x[i]][1] = 1;
            }
        }
        bfs.pop();
    }
    return -1;
}

int main () {
    char inp;
    scanf("%d %d", &N, &M); getchar();
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &inp);
            maze[i][u] = (inp == '0') ? 0 : 1;
        }
        getchar();
    }
    printf("%d", travel());    

    return 0;
}
