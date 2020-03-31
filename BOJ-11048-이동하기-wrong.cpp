// timeout

#include<iostream>

int N, M, ans, maze[1000][1000];

bool in(int row, int col){
    return (row < N && row >= 0 && col < M && col >= 0);
}

void candyHunter(int row, int col, int candy){
    if(row == N - 1 && col == M - 1){
        ans = (candy > ans) ? candy : ans;
        return;
    }
    if(in(row + 1, col))
        candyHunter(row + 1, col, candy + maze[row + 1][col]);
    if(in(row, col + 1))
        candyHunter(row, col + 1, candy + maze[row][col + 1]);
    if(in(row + 1, col + 1))
        candyHunter(row + 1, col + 1, candy + maze[row + 1][col + 1]);
}

int main () {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &maze[i][u]);
    
    candyHunter(0, 0, maze[0][0]);

    printf("%d", ans);

    return 0;
}
