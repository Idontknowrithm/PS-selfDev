// 상어를 하나씩 움직이다가 반례에 걸림
// 상어를 하나씩 움직이면서 그때 그때 만난 상어들에 대해서 그 즉시 처리해줬는데
// 하나씩 처리해주면 안되고 모든 상어가 움직이고 나서 한 번에 잡아먹는 처리를 해줬어야 함
// 문제를 읽고 하니씩 그때 그때 처리해도 되는지, 한꺼번에 처리해줘야 하는지 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

typedef struct{
    int r, c, s, d, z; // row, col, speed, direction, size
}shark;

shark obj[10005];
int R, C, M, ans, fishing[105][105], tmp[105][105];

// 1 2 3 4
// ^ v > <

void sharks_are_moving(){
    for(int i = 1; i <= M; ++i){
        if(!obj[i].z)
            continue;
        fishing[obj[i].r][obj[i].c] = 0;
        int div, mod;
        if(obj[i].d == 3 && obj[i].c == C) obj[i].d = 4;
        else if(obj[i].d == 4 && obj[i].c == 1) obj[i].d = 3;
        else if(obj[i].d == 1 && obj[i].r == 1) obj[i].d = 2;
        else if(obj[i].d == 2 && obj[i].r == R) obj[i].d = 1;
        switch(obj[i].d){
            case 1: // ^
                obj[i].d = 2;
                div = (R * 2 - obj[i].r + obj[i].s - 1) / (R - 1);
                mod = (R * 2 - obj[i].r + obj[i].s - 1) % (R - 1);
                
                if(div & 1){
                    obj[i].d = 1;
                    obj[i].r = R;
                }
                else{
                    obj[i].r = 1;
                }
                obj[i].r += (obj[i].d == 2) ? mod : -mod;
                break;
            case 2: // v
                div = (obj[i].r + obj[i].s - 1) / (R - 1);
                mod = (obj[i].r + obj[i].s - 1) % (R - 1);
                
                if(div & 1){
                    obj[i].d = 1;
                    obj[i].r = R;
                }
                else{
                    obj[i].r = 1;
                }
                obj[i].r += (obj[i].d == 2) ? mod : -mod;
                break;
            case 3: // >
                div = (obj[i].c + obj[i].s - 1) / (C - 1);
                mod = (obj[i].c + obj[i].s - 1) % (C - 1);
                
                if(div & 1){
                    obj[i].d = 4;
                    obj[i].c = C;
                }
                else{
                    obj[i].c = 1;
                }
                obj[i].c += (obj[i].d == 3) ? mod : -mod;
                break;
            case 4: // <
                obj[i].d = 3;
                div = (C * 2 - obj[i].c + obj[i].s - 1) / (C - 1);
                mod = (C * 2 - obj[i].c + obj[i].s - 1) % (C - 1);
                
                if(div & 1){
                    obj[i].d = 4;
                    obj[i].c = C;
                }
                else{
                    obj[i].c = 1;
                }
                obj[i].c += (obj[i].d == 3) ? mod : -mod;
                break;
        }
    }
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i <= M; ++i){
        if(!obj[i].z) continue;
        if(tmp[obj[i].r][obj[i].c]){
            if(obj[tmp[obj[i].r][obj[i].c]].z < obj[i].z){
                obj[tmp[obj[i].r][obj[i].c]].z = 0;
                tmp[obj[i].r][obj[i].c] = i;
            }
            else{
                obj[i].z = 0;
            }
        }
        else{
            tmp[obj[i].r][obj[i].c] = i;
        }
    }
    for(int i = 1; i <= R; ++i)
    for(int u = 1; u <= C; ++u)
        fishing[i][u] = tmp[i][u];
}

int main() {
    int ir, ic, is, id, iz;
    scanf("%d %d %d", &R, &C, &M);
    for(int i = 1; i <= M; ++i){
        scanf("%d %d %d %d %d", &ir, &ic, &is, &id, &iz);
        obj[i] = {ir, ic, is, id, iz};
        fishing[ir][ic] = i;
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
