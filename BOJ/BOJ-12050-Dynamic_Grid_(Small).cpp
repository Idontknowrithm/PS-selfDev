#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};
int T, inpR, inpC, bin, N, M, query, grid[105][105], visited[105][105];
char inp[105];

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M && !visited[r][c] && grid[r][c] == 1);
}
void find(int startR, int startC){
    std::queue<std::pair<int, int>> bfs;
    bfs.push({startR, startC});

    while(!bfs.empty()){
        int r, c;
        r = bfs.front().first;
        c = bfs.front().second;
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(possible(r + y[i], c + x[i])){
                visited[r + y[i]][c + x[i]] = 1;
                bfs.push({r + y[i], c + x[i]});
            }
        }
    }
}
int island(){
    int ans = 0;
    for(int i = 0; i < 105; ++i)
    for(int u = 0; u < 105; ++u)
        visited[i][u] = 0;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(!visited[i][u] && grid[i][u] == 1){
            find(i, u);
            ++ans;
        }
    return ans;
}

int main() {
    scanf("%d\n", &T);
    for(int z = 1; z <= T; ++z){
        scanf("%d %d\n", &N, &M);
        for(int i = 0; i < N; ++i){
            scanf("%s", inp);
            for(int u = 0; u < M; ++u){
                grid[i][u] = (inp[u] == '0') ? 0 : 1;
            }
            getchar();
        }
        scanf("%d", &query);
        printf("Case #%d:\n", z);
        for(int i = 0; i < query; ++i){
            scanf("%s", inp);
            if(inp[0] == 'M'){
                scanf("%d %d %d\n", &inpR, &inpC, &bin);
                grid[inpR][inpC] = bin;
            }
            else{
                printf("%d\n", island());
            }
        }
    }
    return 0;
}
