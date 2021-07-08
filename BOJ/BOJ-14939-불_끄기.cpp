#include<iostream>
#include<algorithm>
#include<vector>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
const int INF = 100000000;
std::string input[15];
int ans = INF, lights[15][15];

bool possible(int r, int c){
    return r >= 0 && r < 10 && c >= 0 && c < 10;
}
void hit_the_light(int r, int c){
    lights[r][c] = (lights[r][c]) ? 0 : 1;
    for(int i = 0; i < 4; ++i)
        if(possible(r + y[i], c + x[i]))
            lights[r + y[i]][c + x[i]] = (lights[r + y[i]][c + x[i]]) ? 0 : 1;
}
bool is_dark(){
    for(int i = 0; i < 10; ++i)
    for(int u = 0; u < 10; ++u)
        if(lights[i][u]) return false;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(int i = 0; i < 10; ++i)
        std::cin >> input[i];
    for(int i = 0; i < 1024; ++i){
        int tmp_ans = 0;
        for(int u = 0; u < 10; ++u)
        for(int k = 0; k < 10; ++k)
            lights[u][k] = (input[u][k] == 'O') ? 1 : 0;
        int tmp = i;
        for(int u = 0; u < 10; ++u){
            if(tmp & 1){
                hit_the_light(0, u);
                ++tmp_ans;
            }
            tmp >>= 1;
        }
        for(int u = 1; u < 10; ++u){
            for(int k = 0; k < 10; ++k){
                if(lights[u - 1][k]){
                    hit_the_light(u, k);
                    ++tmp_ans;
                }
            }
        }
        if(is_dark())
            ans = std::min(ans, tmp_ans);
    }
    printf("%d", ans);
    return 0;
}
