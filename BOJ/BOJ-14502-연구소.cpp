#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

int N, M, tempSecurity, max = -1, field[10][10], testField[10][10], permTable[70] = {1, 1, 1, };
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
std::vector<std::pair<int, int>> two;

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}

void propagation(int sr, int sc){
    std::queue<std::pair<int, int>> bfs;
    bfs.push({sr, sc});

    while(!bfs.empty()){
        int r, c;
        r = bfs.front().first;
        c = bfs.front().second;
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(possible(r + x[i], c + y[i]) && testField[r + x[i]][c + y[i]] == 0){
                testField[r + x[i]][c + y[i]] = 2;
                bfs.push({r + x[i], c + y[i]});
            }
        }
    }
}

int main () {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        scanf("%d", &field[i][u]);
        if(field[i][u] == 2)
            two.push_back({i, u});
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        testField[i][u] = field[i][u];

    do{
        bool can = true;
        for(int i = 0; i < N * M && can; ++i){
            if(permTable[i] == 1 && testField[i / M][i % M] != 0)
                can = false;
        }
        if(!can) continue;

        for(int i = 0; i < N * M && can; ++i){
            if(permTable[i] == 1)
                testField[i / M][i % M] = 1;
        }

        for(int i = 0; i < two.size(); ++i)
            propagation(two[i].first, two[i].second);
        tempSecurity = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < M; ++u)
            tempSecurity += (testField[i][u] == 0) ? 1 : 0;
        
        max = (tempSecurity > max) ? tempSecurity : max;

        for(int i = 0; i < N; ++i)
        for(int u = 0; u < M; ++u)
            testField[i][u] = field[i][u];
    }while(std::prev_permutation(permTable, permTable + N * M));

    printf("%d", max);

    return 0;
}
