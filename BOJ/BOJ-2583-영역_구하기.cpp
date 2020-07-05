#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

int X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
int R, C, K, region[100][100], visited[100][100];
std::vector<int> ans;

bool in(int row, int col){
    return (row < R && row >= 0 && col < C && col >= 0);
}

void find(int row, int col){
    int tempR, tempC, tempAns = 1;
    std::queue<std::pair<int, int>> bfs;

    bfs.push({row, col});
    visited[row][col] = 1;
    while(!bfs.empty()){
        tempR = bfs.front().first;
        tempC = bfs.front().second;
        bfs.pop();

        for(int i = 0; i < 4; ++i)
            if(in(tempR + Y[i], tempC + X[i]) && !visited[tempR + Y[i]][tempC + X[i]] && !region[tempR + Y[i]][tempC + X[i]]){
                visited[tempR + Y[i]][tempC + X[i]] = 1;
                bfs.push({tempR + Y[i], tempC + X[i]});
                ++tempAns;
            }
    }
    ans.push_back(tempAns);
}

int main () {
    int Frow, Fcol, Srow, Scol;
    
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0; i < K; ++i){
        scanf("%d %d %d %d", &Fcol, &Frow, &Scol, &Srow);
        for(int u = Frow; u < Srow; ++u)
        for(int k = Fcol; k < Scol; ++k)
            region[u][k] = 1;
    }

    for(int i = 0; i < R; ++i)
    for(int u = 0; u < C; ++u)
        if(!visited[i][u] && !region[i][u])
            find(i, u);
    
    std::sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    
    return 0;
}
