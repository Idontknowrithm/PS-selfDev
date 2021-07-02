// 문제를 해결하는 메인 알고리즘을 생각해내는 것보다 문제 자체에서 제시된 특성에서
// 문제를 해결하는 힌트를 찾아낼 수 있어야 했던 문제
// 시간 제한, 체스판, 비숍은 같은 색의 칸에서만 움직일 수 있다는 점
// --> 두 부분으로 나누어 완전탐색
// 대각선 방향이 중요
// --> 우측 하단 방향 대각선의 y, x 값은 y - x 값이 일정하다는 특성
// --> 우측 상단 방향 대각선의 y, x 값은 y + x 값이 일정하다는 특성

#include<iostream>
#include<algorithm>

int N, ansB, ansW, board[15][15], down_right[55], down_left[55];

void moving_black(int y, int x, int count){
    ansB = std::max(ansB, count);
    if(x >= N)
        x = ((++y) & 1) ? 1 : 0;
    if(y >= N)
        return;
    
    if(board[y][x] && !down_right[N + y - x] && !down_left[y + x]){
        down_right[N + y - x] = down_left[y + x] = 1;
        moving_black(y, x + 2, count + 1);
        down_right[N + y - x] = down_left[y + x] = 0;
    }
    moving_black(y, x + 2, count);
}
void moving_white(int y, int x, int count){
    ansW = std::max(ansW, count);
    if(x >= N)
        x = ((++y) & 1) ? 0 : 1;
    if(y >= N)
        return;
    
    if(board[y][x] && !down_right[N + y - x] && !down_left[y + x]){
        down_right[N + y - x] = down_left[y + x] = 1;
        moving_white(y, x + 2, count + 1);
        down_right[N + y - x] = down_left[y + x] = 0;
    }
    moving_white(y, x + 2, count);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &board[i][u]);
    
    moving_black(0, 0, 0);
    moving_white(0, 1, 0);

    printf("%d", ansB + ansW);
    return 0;
}
