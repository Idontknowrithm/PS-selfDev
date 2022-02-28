#include<iostream>
#include<vector>
#include<cmath>

// #include<algorithm>
// #define pp std::pair<int, int>

// > V < ^
const int y[4] = {0, 1, 0, -1};
const int x[4] = {1, 0, -1, 0};
int N, L, ans, map[105][105];

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
bool can_bridge(int r, int c, int dir, int h, std::vector<bool> &tmp){
    for(int i = 1; i <= L; ++i){
        int R = r + y[dir] * i, C = c + x[dir] * i;

        if(!possible(R, C) || map[R][C] != h)
            return false;
        
        if(map[R][C] == h)
            if((dir == 0 || dir == 2) && tmp[C])
                return false;
            if((dir == 1 || dir == 3) && tmp[R])
                return false;
        if(dir == 0 || dir == 2)
            tmp[C] = true;
        else if(dir == 1 || dir == 3)
            tmp[R] = true;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &map[i][u]);
    
    for(int i = 0; i < N; ++i){
        bool tmp_can, can = true;
        std::vector<bool> tmp(N, false);

        for(int u = 1; u < N; ++u){
            if(std::abs(map[i][u - 1] - map[i][u]) > 1){
                can = false;
                break;
            }
            else if(map[i][u - 1] + 1 == map[i][u]){
                tmp_can = can_bridge(i, u, 2, map[i][u - 1], tmp);
                can = (tmp_can) ? can : false;
            }
            else if(map[i][u - 1] - 1 == map[i][u]){
                tmp_can = can_bridge(i, u - 1, 0, map[i][u], tmp);
                can = (tmp_can) ? can : false;
            }
            if(!can) break;
        }
        ans += (can) ? 1 : 0;
    }
    for(int i = 0; i < N; ++i){
        bool tmp_can, can = true;
        std::vector<bool> tmp(N, false);

        for(int u = 1; u < N; ++u){
            if(std::abs(map[u - 1][i] - map[u][i]) > 1){
                can = false;
                break;
            }
            else if(map[u - 1][i] + 1 == map[u][i]){
                tmp_can = can_bridge(u, i, 3, map[u - 1][i], tmp);
                can = (tmp_can) ? can : false;
            }
            else if(map[u - 1][i] - 1 == map[u][i]){
                tmp_can = can_bridge(u - 1, i, 1, map[u][i], tmp);
                can = (tmp_can) ? can : false;
            }
            if(!can) break;
        }
        ans += (can) ? 1 : 0;
    }
    printf("%d", ans);

    return 0;
}
