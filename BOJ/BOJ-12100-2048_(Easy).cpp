#include<iostream>

int N, ans, board[25][25], tmp[25][25];

void up(){
    for(int col = 0; col < N; ++col){
        int start = 0, end = 0;
        while(start < N){
            for(int i = start; i < N; ++i)
                if(tmp[i][col] && i == start){
                    end = i + 1;
                    break;
                }
                else if(tmp[i][col]){
                    tmp[start][col] = tmp[i][col];
                    tmp[i][col] = 0;
                    end = i + 1;
                    break;
                }
            if(!tmp[start][col]) break;
            for(; end < N; ++end){
                if(tmp[end][col] == tmp[start][col]){
                    tmp[start][col] += tmp[end][col];
                    tmp[end][col] = 0;
                    break;
                }
                else if(tmp[end][col]){
                    tmp[start + 1][col] = tmp[end][col];
                    if(start + 1 != end)
                        tmp[end][col] = 0;
                    break;
                }
            }
            end = ++start;
        }
    }
}
void down(){
    for(int col = 0; col < N; ++col){
        int start = N - 1, end = N - 1;
        while(start >= 0){
            for(int i = start; i >= 0; --i)
                if(tmp[i][col] && i == start){
                    end = i - 1;
                    break;
                }
                else if(tmp[i][col]){
                    tmp[start][col] = tmp[i][col];
                    tmp[i][col] = 0;
                    end = i - 1;
                    break;
                }
            if(!tmp[start][col]) break;
            for(; end >= 0; --end){
                if(tmp[end][col] == tmp[start][col]){
                    tmp[start][col] += tmp[end][col];
                    tmp[end][col] = 0;
                    break;
                }
                else if(tmp[end][col]){
                    tmp[start - 1][col] = tmp[end][col];
                    if(start - 1 != end)
                        tmp[end][col] = 0;
                    break;
                }
            }
            end = --start;
        }
    }
}
void left(){
    for(int row = 0; row < N; ++row){
        int start = 0, end = 0;
        while(start < N){
            for(int i = start; i < N; ++i)
                if(tmp[row][i] && i == start){
                    end = i + 1;
                    break;
                }
                else if(tmp[row][i]){
                    tmp[row][start] = tmp[row][i];
                    tmp[row][i] = 0;
                    end = i + 1;
                    break;
                }
            if(!tmp[row][start]) break;
            for(; end < N; ++end){
                if(tmp[row][end] == tmp[row][start]){
                    tmp[row][start] += tmp[row][end];
                    tmp[row][end] = 0;
                    break;
                }
                else if(tmp[row][end]){
                    tmp[row][start + 1] = tmp[row][end];
                    if(start + 1 != end)
                        tmp[row][end] = 0;
                    break;
                }
            }
            end = ++start;
        }
    }
}
void right(){
    for(int row = 0; row < N; ++row){
        int start = N - 1, end = N - 1;
        while(start >= 0){
            for(int i = start; i >= 0; --i)
                if(tmp[row][i] && i == start){
                    end = i - 1;
                    break;
                }
                else if(tmp[row][i]){
                    tmp[row][start] = tmp[row][i];
                    tmp[row][i] = 0;
                    end = i - 1;
                    break;
                }
            if(!tmp[row][start]) break;
            for(; end >= 0; --end){
                if(tmp[row][end] == tmp[row][start]){
                    tmp[row][start] += tmp[row][end];
                    tmp[row][end] = 0;
                    break;
                }
                else if(tmp[row][end]){
                    tmp[row][start - 1] = tmp[row][end];
                    if(start - 1 != end)
                        tmp[row][end] = 0;
                    break;
                }
            }
            end = --start;
        }
    }
}
void mover(int a, int b, int c, int d, int e){
    switch(a){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(b){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(c){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(d){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
    switch(e){
        case 0: up(); break;
        case 1: down(); break;
        case 2: left(); break;
        case 3: right(); break;
    }
}
int matrix_max(){
    int max = -1;
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        max = (max < tmp[i][u]) ? tmp[i][u] : max;
    return max;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &board[i][u]);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        tmp[i][u] = board[i][u];
    
    for(int a = 0; a < 4; ++a)
    for(int b = 0; b < 4; ++b)
    for(int c = 0; c < 4; ++c)
    for(int d = 0; d < 4; ++d)
    for(int e = 0; e < 4; ++e){
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            tmp[i][u] = board[i][u];
        mover(a, b, c, d, e);
        ans = std::max(ans, matrix_max());
    }
    printf("%d", ans);
    return 0;
}
