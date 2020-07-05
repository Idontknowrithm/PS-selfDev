#include<iostream>
#include<queue>
#include<utility>

int row, col, numOfI, island[50][50], visited[50][50]; // row: h, col: w;

bool RTE(int r, int c){
    return !(r < row && r >= 0 && c < col && c >= 0);
}

void find(int R, int C){
    int tempR, tempC;
    std::queue<std::pair<int, int>> bfs;

    bfs.push({R, C});
    while(!bfs.empty()){
        tempR = bfs.front().first;
        tempC = bfs.front().second;
        bfs.pop();
        if(!RTE(tempR - 1, tempC - 1) && !visited[tempR - 1][tempC - 1] && island[tempR - 1][tempC - 1]){
            visited[tempR - 1][tempC - 1] = 1;
            bfs.push({tempR - 1, tempC - 1});
        }
        if(!RTE(tempR - 1, tempC) && !visited[tempR - 1][tempC] && island[tempR - 1][tempC]){
            visited[tempR - 1][tempC] = 1;
            bfs.push({tempR - 1, tempC});
        }
        if(!RTE(tempR - 1, tempC + 1) && !visited[tempR - 1][tempC + 1] && island[tempR - 1][tempC + 1]){
            visited[tempR - 1][tempC + 1] = 1;
            bfs.push({tempR - 1, tempC + 1});
        }
        if(!RTE(tempR, tempC + 1) && !visited[tempR][tempC + 1] && island[tempR][tempC + 1]){
            visited[tempR][tempC + 1] = 1;
            bfs.push({tempR, tempC + 1});
        }
        if(!RTE(tempR + 1, tempC + 1) && !visited[tempR + 1][tempC + 1] && island[tempR + 1][tempC + 1]){
            visited[tempR + 1][tempC + 1] = 1;
            bfs.push({tempR + 1, tempC + 1});
        }
        if(!RTE(tempR + 1, tempC) && !visited[tempR + 1][tempC] && island[tempR + 1][tempC]){
            visited[tempR + 1][tempC] = 1;
            bfs.push({tempR + 1, tempC});
        }
        if(!RTE(tempR + 1, tempC - 1) && !visited[tempR + 1][tempC - 1] && island[tempR + 1][tempC - 1]){
            visited[tempR + 1][tempC - 1] = 1;
            bfs.push({tempR + 1, tempC - 1});
        }
        if(!RTE(tempR, tempC - 1) && !visited[tempR][tempC - 1] && island[tempR][tempC - 1]){
            visited[tempR][tempC - 1] = 1;
            bfs.push({tempR, tempC - 1});
        }
    }
    ++numOfI;
}

int main () {
    scanf("%d %d", &col, &row);

    while(row || col){
        numOfI = 0;
        for(int i = 0; i < row; ++i)
        for(int u = 0; u < col; ++u){
            scanf("%d", &island[i][u]);
            visited[i][u] = 0;
        }

        for(int i = 0; i < row; ++i)
        for(int u = 0; u < col; ++u){
            if(!visited[i][u] && island[i][u])
                find(i, u);
        }
        printf("%d\n", numOfI);

        scanf("%d %d", &col, &row);
    }
    return 0;
}
