#include<iostream>
#include<queue>
#include<algorithm>
#define pp std::pair<int, int>

typedef struct{
    pp red, blue;
    int num;
}data;

int N, M, board[15][15];
pp R, B;

data up(data prev){
    bool Rhole = false, Bhole = false;
    pp &R = prev.red, &B = prev.blue;
    int rf = R.first, bf = B.first;

    int rtmp = R.first;
    while(board[rtmp - 1][R.second] != 1){
        --rtmp;
        if(board[rtmp][R.second] == 9) Rhole = true;
    }
    R.first = rtmp;
    int btmp = B.first;
    while(board[btmp - 1][B.second] != 1){
        --btmp;
        if(board[btmp][B.second] == 9) Bhole = true;
    }
    B.first = btmp;
    if(B.second == R.second && B.first == R.first){
        if(bf < rf) ++R.first;
        else        ++B.first;
    }
    if(Bhole)         return {{-1, -1}, {-1, -1}, 0};
    else if(Rhole)    return {{1000, 1000}, {1000, 1000}, prev.num + 1};
    else {++prev.num; return prev;}
    
}
data down(data prev){
    bool Rhole = false, Bhole = false;
    pp &R = prev.red, &B = prev.blue;
    int rf = R.first, bf = B.first;

    int rtmp = R.first;
    while(board[rtmp + 1][R.second] != 1){
        ++rtmp;
        if(board[rtmp][R.second] == 9) Rhole = true;
    }
    R.first = rtmp;
    int btmp = B.first;
    while(board[btmp + 1][B.second] != 1){
        ++btmp;
        if(board[btmp][B.second] == 9) Bhole = true;
    }
    B.first = btmp;
    if(B.second == R.second && B.first == R.first){
        if(bf < rf) --B.first;
        else        --R.first;
    }
    if(Bhole)         return {{-1, -1}, {-1, -1}, 0};
    else if(Rhole)    return {{1000, 1000}, {1000, 1000}, prev.num + 1};
    else {++prev.num; return prev;}
}
data left(data prev){
    bool Rhole = false, Bhole = false;
    pp &R = prev.red, &B = prev.blue;
    int rs = R.second, bs = B.second;

    int rtmp = R.second;
    while(board[R.first][rtmp - 1] != 1){
        --rtmp;
        if(board[R.first][rtmp] == 9) Rhole = true;
    }
    R.second = rtmp;
    int btmp = B.second;
    while(board[B.first][btmp - 1] != 1){
        --btmp;
        if(board[B.first][btmp] == 9) Bhole = true;
    }
    B.second = btmp;
    if(B.second == R.second && B.first == R.first){
        if(bs < rs) ++R.second;
        else        ++B.second;
    }
    if(Bhole)         return {{-1, -1}, {-1, -1}, 0};
    else if(Rhole)    return {{1000, 1000}, {1000, 1000}, prev.num + 1};
    else {++prev.num; return prev;}
}
data right(data prev){
    bool Rhole = false, Bhole = false;
    pp &R = prev.red, &B = prev.blue;
    int rs = R.second, bs = B.second;

    int rtmp = R.second;
    while(board[R.first][rtmp + 1] != 1){
        ++rtmp;
        if(board[R.first][rtmp] == 9) Rhole = true;
    }
    R.second = rtmp;
    int btmp = B.second;
    while(board[B.first][btmp + 1] != 1){
        ++btmp;
        if(board[B.first][btmp] == 9) Bhole = true;
    }
    B.second = btmp;
    if(B.second == R.second && B.first == R.first){
        if(bs < rs) --B.second;
        else        --R.second;
    }
    if(Bhole)         return {{-1, -1}, {-1, -1}, 0};
    else if(Rhole)    return {{1000, 1000}, {1000, 1000}, prev.num + 1};
    else {++prev.num; return prev;}
}
int game(data start){
    int ans = 999;
    std::queue<data> bfs;
    bfs.push(start);
    while(!bfs.empty()){
        data tmp = bfs.front();
        bfs.pop();
        if(tmp.blue.first == -1 || tmp.num > 10) 
            continue;
        if(tmp.blue.first == 1000){
            ans = (ans > tmp.num) ? tmp.num : ans;
            continue;
        }
        bfs.push(up(tmp));
        bfs.push(down(tmp));
        bfs.push(left(tmp));
        bfs.push(right(tmp));
    }
    return (ans == 999) ? -1 : ans;
}

int main() {
    char input;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%c", &input);
            if(input == '#') board[i][u] = 1;
            else if(input == '.') board[i][u] = 0;
            else if(input == 'O') board[i][u] = 9;
            else if(input == 'R') R = {i, u};
            else if(input == 'B') B = {i, u};
        }
        getchar();
    }
    printf("%d", game({R, B, 0}));
    return 0;
}
