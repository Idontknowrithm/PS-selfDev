#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};

int N, cave[130][130], cache[130][130];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}

void BFS(){
    std::queue<pp> que;
    que.push({0, 0});

    cache[0][0] = cave[0][0];
    while(!que.empty()){
        int r = que.front().first, c = que.front().second;

        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];
            if(possible(R, C) && cache[R][C] > cache[r][c] + cave[R][C]){
                cache[R][C] = cache[r][c] + cave[R][C];
                que.push({R, C});
            }
        }
    }
}

int main() {
    for(int T = 1; ; ++T){
        memset(cache, 1, sizeof(cache));
        scanf("%d", &N);
        if(!N) return 0;

        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            scanf("%d", &cave[i][u]);
        
        BFS();

        printf("Problem %d: %d\n", T, cache[N - 1][N - 1]);
    }
    return 0;
}
