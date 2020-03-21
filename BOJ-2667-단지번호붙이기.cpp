#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

int N, numOfCplx, city[25][25], visited[25][25];
std::vector<int> apartsInCplx;

void bfs(int R, int C){
    std::queue<std::pair<int, int>> que;
    int r, c, tempNum = 1;
    visited[R][C] = 1;
    que.push({R, C});
    while(!que.empty()){
        r = que.front().first;
        c = que.front().second;
        que.pop();
        if(r < N - 1 && city[r + 1][c] && !visited[r + 1][c]){
            visited[r + 1][c] = 1;
            que.push({r + 1, c});
            ++tempNum;
        }
        if(r > 0 && city[r - 1][c] && !visited[r - 1][c]){
            visited[r - 1][c] = 1;
            que.push({r - 1, c});
            ++tempNum;
        }
        if(c < N - 1 && city[r][c + 1] && !visited[r][c + 1]){
            visited[r][c + 1] = 1;
            que.push({r, c + 1});
            ++tempNum;
        }
        if(c > 0 && city[r][c - 1] && !visited[r][c - 1]){
            visited[r][c - 1] = 1;
            que.push({r, c - 1});
            ++tempNum;
        }
    }
    apartsInCplx.push_back(tempNum);
    ++numOfCplx;
}

int main () {
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < N; ++u)
            city[i][u] = getchar() - '0';
        getchar();
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(!visited[i][u] && city[i][u])
            bfs(i, u);
    std::sort(apartsInCplx.begin(), apartsInCplx.end());
    printf("%d\n", numOfCplx);
    for(int i = 0; i < apartsInCplx.size(); ++i)
        printf("%d\n", apartsInCplx[i]);
    return 0;
}
