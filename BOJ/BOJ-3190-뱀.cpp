#include<iostream>
#include<algorithm>
#define ppc std::pair<int, char>
#define pp std::pair<int, int>
#define Rh snake_head.first
#define Ch snake_head.second
#define Rt snake_tail.first
#define Ct snake_tail.second
#define dc direc_change
#define INF 2147483647

int y[4] = {-1, 0, 1, 0};
int x[4] = {0, 1, 0, -1};
int N, K, L, next_direc_change, snake_direc = 1, snakeH, snakeT, board[105][105];
ppc direc_change[105];
pp snake_head, snake_tail;

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < N);
}
void tail_care(){
    board[Rt][Ct] = 0;
    for(int i = 0; i < 4; ++i){
        if(board[Rt + y[i]][Ct + x[i]] == snakeT + 1){
            snakeT++;
            Rt += y[i];
            Ct += x[i];
            return;
        }
    }
}
int endgame(){
    int sec = 0;
    snake_head = snake_tail = {0, 0};
    snakeH = snakeT = 1;
    while(1){
        ++sec;
        if(!possible(Rh + y[snake_direc], Ch + x[snake_direc]) ||
           board[Rh + y[snake_direc]][Ch + x[snake_direc]] > 0){
            return sec;
        }
        if(board[Rh + y[snake_direc]][Ch + x[snake_direc]] == -1)
            board[Rh + y[snake_direc]][Ch + x[snake_direc]] = ++snakeH;
        else{
            board[Rh + y[snake_direc]][Ch + x[snake_direc]] = ++snakeH;
            tail_care();
        }
        Rh += y[snake_direc];
        Ch += x[snake_direc];

        if(next_direc_change < L && direc_change[next_direc_change].first == sec){
            snake_direc = (direc_change[next_direc_change].second == 'L') ? 
                           ((snake_direc == 0) ? 3 : snake_direc - 1) : (snake_direc + 1) % 4;
            ++next_direc_change;
        }
    }
}

int main() {
    int rapple, capple;
    scanf("%d\n%d\n", &N, &K);
    for(int i = 0; i < K; ++i){
        scanf("%d %d\n", &rapple, &capple);
        board[rapple - 1][capple - 1] = -1; // apple == -1
    }
    scanf("%d\n", &L);
    for(int i = 0; i < L; ++i){
        scanf("%d %c", &dc[i].first, &dc[i].second);
        getchar();
    }
    board[0][0] = 1;
    printf("%d", endgame());
    
    return 0;
}
