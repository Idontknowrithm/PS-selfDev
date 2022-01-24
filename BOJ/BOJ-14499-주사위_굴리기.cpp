#include<iostream>

const int y[4] = {0, 0, -1, 1};
const int x[4] = {1, -1, 0, 0};
int N, M, K, dice_r, dice_c, map[25][25];
//  1    2   3   4   5    6
// top | ^ | > | < | v | bot
int dice_cur[7] = {-1, 1, 2, 3, 4, 5, 6};
int dice_cur_val[7] = {-1, 0, 0, 0, 0, 0, 0};

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
void dice_rolling(int dir){
    int tmp;
    ++dir;
    if(dir == 1){
        tmp = dice_cur[3];
        dice_cur[3] = dice_cur[1];
        dice_cur[1] = dice_cur[4];
        dice_cur[4] = dice_cur[6];
        dice_cur[6] = tmp;
    }
    if(dir == 2){
        tmp = dice_cur[4];
        dice_cur[4] = dice_cur[1];
        dice_cur[1] = dice_cur[3];
        dice_cur[3] = dice_cur[6];
        dice_cur[6] = tmp;
    }
    if(dir == 3){
        tmp = dice_cur[2];
        dice_cur[2] = dice_cur[1];
        dice_cur[1] = dice_cur[5];
        dice_cur[5] = dice_cur[6];
        dice_cur[6] = tmp;
    }
    if(dir == 4){
        tmp = dice_cur[5];
        dice_cur[5] = dice_cur[1];
        dice_cur[1] = dice_cur[2];
        dice_cur[2] = dice_cur[6];
        dice_cur[6] = tmp;
    }
}
void num_copier(int r, int c){
    if(map[r][c]){
        dice_cur_val[dice_cur[6]] = map[r][c];
        map[r][c] = 0;
    }
    else{
        map[r][c] = dice_cur_val[dice_cur[6]];
    }
}

int main() {
    scanf("%d %d %d %d %d", &N, &M, &dice_r, &dice_c, &K);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &map[i][u]);
    for(int i = 0; i < K; ++i){
        int query, cur_r, cur_c;
        scanf("%d", &query);
        --query;
        // 1: >  2: <  3: ^  4: v
        cur_r = dice_r + y[query];
        cur_c = dice_c + x[query];
        if(!possible(cur_r, cur_c))
            continue;
        dice_rolling(query);
        num_copier(cur_r, cur_c);
        printf("%d\n", dice_cur_val[dice_cur[1]]);
        dice_r = cur_r;
        dice_c = cur_c;
    }
    return 0;
}
