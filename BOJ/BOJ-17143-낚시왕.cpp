#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int r, c, s, d, z; // row, col, speed, direction, size
}shark;

shark obj[10005];
int R, C, M, ans, fishing[105][105];

// 1 2 3 4
// ^ v > <
void sharks_are_moving(){
    for(int i = 1; i <= M; ++i){
        /*
         * (현재 장소 + 속도 - 1) / (낚시터 격자 크기 - 1)
         *  홀수면 방향 그대로, 짝수면 방향 변경
         * 
         * (현재 장소 + 속도 - 1) % (낚시터 격자 크기 - 1)
         * 최종 방향 반대 방향의 맨 끝에서 나머지 만큼 더해주면서
         * 값이 0이 아니면 방향 변경
         */
        if(!obj[i].z)
            continue;
        fishing[obj[i].r][obj[i].c] = 0;
        int div, mod;
        switch(obj[i].d){
            case 1: // ^
                div = (R - obj[i].r + obj[i].s) / (R - 1);
                mod = (R - obj[i].r + obj[i].s) % (R - 1);
                if(div != 0 && !(div & 1)){
                    obj[i].d = 2;
                }
                if(obj[i].d = 2)
                    obj[i].r = R;
                else 
                    obj[i].r = 1;
                if(mod){
                    obj[i].d = (obj[i].d == 2) ? 1 : 2;
                    if(obj[i].d == 1)
                        obj[i].r -= mod;
                    else 
                        obj[i].r += mod;
                }
                break;
            case 2: // v
                div = (obj[i].r + obj[i].s - 1) / (R - 1);
                mod = (obj[i].r + obj[i].s - 1) % (R - 1);
                if(div != 0 && !(div & 1)){
                    obj[i].d = 1;
                }
                if(obj[i].d = 1)
                    obj[i].r = 1;
                else 
                    obj[i].r = R;
                if(mod){
                    obj[i].d = (obj[i].d == 1) ? 2 : 1;
                    if(obj[i].d == 2)
                        obj[i].r += mod;
                    else 
                        obj[i].r -= mod;
                }
                break;
            case 3: // >
                div = (obj[i].c + obj[i].s - 1) / (C - 1);
                mod = (obj[i].c + obj[i].s - 1) % (C - 1);
                if(div != 0 && !(div & 1)){
                    obj[i].d = 4;
                }
                if(obj[i].d = 4)
                    obj[i].c = 1;
                else 
                    obj[i].c = C;
                if(mod){
                    obj[i].d = (obj[i].d == 4) ? 3 : 4;
                    if(obj[i].d == 3)
                        obj[i].c += mod;
                    else 
                        obj[i].c -= mod;
                }
                break;
            case 4: // <
                div = (C - obj[i].c + obj[i].s) / (C - 1);
                mod = (C - obj[i].c + obj[i].s) % (C - 1);
                if(div != 0 && !(div & 1)){
                    obj[i].d = 3;
                }
                if(obj[i].d = 3)
                    obj[i].c = C;
                else 
                    obj[i].c = 1;
                if(mod){
                    obj[i].d = (obj[i].d == 3) ? 4 : 3;
                    if(obj[i].d == 4)
                        obj[i].c -= mod;
                    else 
                        obj[i].c += mod;
                }
                break;
        }
        if(fishing[obj[i].r][obj[i].c]){
            if(obj[fishing[obj[i].r][obj[i].c]].z < obj[i].z){
                obj[fishing[obj[i].r][obj[i].c]].z = 0;
                fishing[obj[i].r][obj[i].c] = i;
            }
            else{
                obj[i].z = 0;
            }
        }
        else{
            fishing[obj[i].r][obj[i].c] = i;
        }
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
    printf("%d", ans);
    return 0;
}
