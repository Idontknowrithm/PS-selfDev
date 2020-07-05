#include<iostream>
#include<queue>
#include<vector>

typedef struct{
    int dist, x, y;
}loc;
int T, N, i1, i2, i3, i4, board[305][305];
int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool possible(int x, int y){
    return (x < N && x >= 0 && y < N && y >= 0);
}
int find(){
    std::queue<loc> bfs;
    loc cache;
    int distance = 0;
    bfs.push({0, i1, i2});
    while(!bfs.empty()){
        cache = bfs.front();
        if(cache.x == i3 && cache.y == i4)
            return cache.dist;
        for(int i = 0; i < 8; ++i){
            if(possible(cache.x + x[i], cache.y + y[i]) && !board[cache.x + x[i]][cache.y + y[i]]){
                board[cache.x + x[i]][cache.y + y[i]] = 1;
                bfs.push({cache.dist + 1, cache.x + x[i], cache.y + y[i]});
            }
        }
        bfs.pop();
    }
}

int main () {
    for(scanf("%d", &T); T > 0; --T){
        for(int i = 0; i < 305; ++i)
        for(int u = 0; u < 305; ++u)
            board[i][u] = 0;
        scanf("%d\n%d %d\n%d %d", &N, &i1, &i2, &i3, &i4);

        printf("%d\n", find());
    }
    return 0;
}
