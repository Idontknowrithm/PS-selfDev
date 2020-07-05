#include<iostream>
#include<queue>
#include<algorithm>

int N, domain, domainRG, picture[101][101], visited[101][101];
char picchar[101];

bool in(int row, int col){
    return (row < N && row >= 0 && col < N && col >= 0);
}
void find(int row, int col, int color, int RG){
    std::queue<std::pair<int, int>> bfs;
    int r, c;

    bfs.push({row, col});
    visited[row][col] = 1;
    while(!bfs.empty()){
        r = bfs.front().first;
        c = bfs.front().second;
        bfs.pop();
        if(in(r + 1, c) && !visited[r + 1][c] && picture[r + 1][c] == color){
            visited[r + 1][c] = 1;
            bfs.push({r + 1, c});
        }
        if(in(r, c + 1) && !visited[r][c + 1] && picture[r][c + 1] == color){
            visited[r][c + 1] = 1;
            bfs.push({r, c + 1});
        }
        if(in(r - 1, c) && !visited[r - 1][c] && picture[r - 1][c] == color){
            visited[r - 1][c] = 1;
            bfs.push({r - 1, c});
        }
        if(in(r, c - 1) && !visited[r][c - 1] && picture[r][c - 1] == color){
            visited[r][c - 1] = 1;
            bfs.push({r, c - 1});
        }
    }
    (RG) ? (++domainRG) : (++domain);
}

int main () {
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s", picchar);
        for(int u = 0; u < N; ++u){
            picture[i][u] = (picchar[u] == 'R') ? 1 : (picchar[u] == 'G') ? 2 : 3;
        }
    }

    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(!visited[i][u])
            find(i, u, picture[i][u], 0);
    
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        visited[i][u] = 0;
        picture[i][u] = (picture[i][u] == 1) ? 2 : picture[i][u];
    }

    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(!visited[i][u])
            find(i, u, picture[i][u], 1);

    printf("%d %d", domain, domainRG);

    return 0;
}
