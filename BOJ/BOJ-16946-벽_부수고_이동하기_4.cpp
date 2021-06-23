#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>
#define r first
#define c second

const int y[4] = {0, 1, 0, -1};
const int x[4] = {1, 0, -1, 0};
int N, M, sector_num = 2, board[1005][1005], sector_size[1000005];

bool possible(int R, int C){
    return (R >= 0 && R < N && C >= 0 && C < M);
}
void division(int R, int C){
    std::queue<pp> bfs;
    bfs.push({R, C});
    board[R][C] = sector_num;
    ++sector_size[sector_num];
    while(!bfs.empty()){
        pp tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            if(possible(tmp.r + y[i], tmp.c + x[i]) && !board[tmp.r + y[i]][tmp.c + x[i]]){
                bfs.push({tmp.r + y[i], tmp.c + x[i]});
                board[tmp.r + y[i]][tmp.c + x[i]] = sector_num;
                ++sector_size[sector_num];
            }
        }
    }
    ++sector_num;
}
int can_move(int R, int C){
    int ans = 0;
    std::vector<int> near_by;
    for(int i = 0; i < 4; ++i){
        if(possible(R + y[i], C + x[i]) && board[R + y[i]][C + x[i]] != 1)
            near_by.push_back(board[R + y[i]][C + x[i]]);
    }
    if(near_by.size() == 0) return 1;
    std::sort(near_by.begin(), near_by.end());
    ans += sector_size[near_by[0]];
    for(int i = 1; i < near_by.size(); ++i)
        if(near_by[i] != near_by[i - 1])
            ans += sector_size[near_by[i]];
    near_by.clear();
    return (ans + 1) % 10;
}

int main() {
    char c;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &c);
            board[i][u] = (int)(c - '0');
        }
        getchar();    
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(!board[i][u])
            division(i, u);
    
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u)
            if(board[i][u] == 1)
                printf("%d", can_move(i, u));
            else 
                printf("0");
        puts("");
    }
    return 0;
}
