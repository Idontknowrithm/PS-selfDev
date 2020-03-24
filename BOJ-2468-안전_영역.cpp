#include<iostream>
#include<queue>
#include<utility>

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};
int N, tempAns, ans = 1, region[100][100], visited[100][100];

bool in(int row, int col){
    return (row < N && row >= 0 && col < N && col >= 0);
}

void notImmersed(int row, int col, int height){
    std::queue<std::pair<int, int>> bfs;
    int tempR, tempC;

    bfs.push({row, col});
    while(!bfs.empty()){
        tempR = bfs.front().first;
        tempC = bfs.front().second;
        bfs.pop();
        for(int i = 0; i < 4; ++i)
            if(in(tempR + Y[i], tempC + X[i]) && region[tempR + Y[i]][tempC + X[i]] > height && !visited[tempR + Y[i]][tempC + X[i]]){
                bfs.push({tempR + Y[i], tempC + X[i]});
                visited[tempR + Y[i]][tempC + X[i]] = 1;
            }
    }
    ++tempAns;
}

int main (){
    int max = -1, min = 1000000;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        scanf("%d", &region[i][u]);
        max = (region[i][u] > max) ? region[i][u] : max;
        min = (region[i][u] < min) ? region[i][u] : min;
    }

    for(int k = min; k <= max; ++k){
        tempAns = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            visited[i][u] = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            if(region[i][u] > k && !visited[i][u])
                notImmersed(i, u, k);
        ans = (ans < tempAns) ? tempAns : ans;
    }
    
    printf("%d", ans);

    return 0;
}
