#include<iostream>
#include<algorithm>
#include<queue>

typedef struct{
    int row, col;
}location;

int constore, city[105][105];
location vertex[100];

bool canWeGetThere(){
    std::queue<int> bfs;
    int curLoc, visited[105] = {1,};
    bfs.push(0);
    while(!bfs.empty() && bfs.front() != constore + 1){
        curLoc = bfs.front();
        bfs.pop();
        for(int i = 0; i < constore + 2; ++i)
            if(!visited[i] && city[curLoc][i]){
                bfs.push(i);
                visited[i] = 1;
            }
    }
    if(!bfs.empty() && bfs.front() == constore + 1)
        return true;
    else 
        return false;
}

int main () {
    int T, r, c;
    for(scanf("%d", &T); T > 0; --T){
        for(int i = 0; i < 105; ++i)
        for(int u = 0; u < 105; ++u)
            city[i][u] = 0;
        scanf("%d", &constore);
        for(int i = 0; i < constore + 2; ++i){
            scanf("%d %d", &r, &c);
            vertex[i] = {r, c};
        }

        for(int i = 0; i < constore + 1; ++i){
            for(int u = i + 1; u < constore + 2; ++u){
                city[i][u] =  (vertex[i].row < vertex[u].row) ? vertex[u].row - vertex[i].row : vertex[i].row - vertex[u].row;
                city[u][i] =  (vertex[i].row < vertex[u].row) ? vertex[u].row - vertex[i].row : vertex[i].row - vertex[u].row;
                city[i][u] += (vertex[i].col < vertex[u].col) ? vertex[u].col - vertex[i].col : vertex[i].col - vertex[u].col;
                city[u][i] += (vertex[i].col < vertex[u].col) ? vertex[u].col - vertex[i].col : vertex[i].col - vertex[u].col;
            }
        }
        for(int i = 0; i < constore + 2; ++i)
        for(int u = 0; u < constore + 2; ++u)
            city[i][u] = (city[i][u] > 1000) ? 0 : city[i][u];

        if(canWeGetThere())
            printf("happy\n");
        else 
            printf("sad\n");
    }

    return 0;
}
