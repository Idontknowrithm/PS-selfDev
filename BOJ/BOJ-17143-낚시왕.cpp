#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int r, c, s, d, z; // row, col, speed, direction, size
}shark;

shark obj[10005];
int R, C, M, ans, fishing[105][105];

void sharks_are_moving(){
    for(int i = 1; i <= M; ++i){
        /*
         * (현재 장소 + 속도 - 1) / 낚시터 격자 크기
         *  짝수면 방향 그대로, 홀수면 방향 변경
         * 
         * (현재 장소 + 속도 - 1) % 낚시터 격자 크기
         * 최종 방향 반대 방향의 맨 끝에서 나머지 만큼 더해주기
         * 
         */
    }
}

int main() {
    int ir, ic, is, id, iz;
    scanf("%d %d %d", &R, &C, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d %d %d", &ir, &ic, &is, &id, &iz);
        obj[i + 1] = {ir, ic, is, id, iz};
        fishing[ir][ic] = i + 1;
    }
    for(int i = 1; i <= C; ++i){
        for(int u = 1; u <= R; ++u){
            if(fishing[u][i]){
                ans += obj[fishing[u][i]].z;
                obj[fishing[u][i]].z = 0;
                fishing[u][i] = 0;
                break;
            }
        }
        sharks_are_moving();
    }
}
