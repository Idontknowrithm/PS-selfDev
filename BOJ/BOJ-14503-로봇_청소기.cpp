#include<iostream>
#include<algorithm>
#define pp std::pair<int, int>
#define R robot_loc.first
#define C robot_loc.second

int y[4] = {-1, 0, 1, 0};
int x[4] = {0, 1, 0, -1};
int N, M, robot_direc, place[55][55];
pp robot_loc;
// 0:^ 1:> 2:v 3:<

bool possible(int r, int c){
    return (r >= 0 && r < N && c >= 0 && c < M);
}
bool sweeped_or_wall(int r, int c){
    int T = 0;
    if(r + 1 < N)
        T += (place[r + 1][c] == 1 || place[r + 1][c] == 8) ? 1 : 0;
    if(c + 1 < M)
        T += (place[r][c + 1] == 1 || place[r][c + 1] == 8) ? 1 : 0;
    if(r - 1 >= 0)
        T += (place[r - 1][c] == 1 || place[r - 1][c] == 8) ? 1 : 0;
    if(c - 1 >= 0)
        T += (place[r][c - 1] == 1 || place[r][c - 1] == 8) ? 1 : 0;
    return (T == 4) ? true : false;
}
int sweeping(){
    int sweep = 0;
    while(1){
        place[R][C] = 8;
        ++sweep;
        while(1){
            if(sweeped_or_wall(R, C) && 
               possible(R + y[(robot_direc + 2) % 4], C + x[(robot_direc + 2) % 4]) &&
               place[R + y[(robot_direc + 2) % 4]][C + x[(robot_direc + 2) % 4]] == 8){
                R += y[(robot_direc + 2) % 4];
                C += x[(robot_direc + 2) % 4];
                continue;
            }
            else if(sweeped_or_wall(R, C) && 
               possible(R + y[(robot_direc + 2) % 4], C + x[(robot_direc + 2) % 4]) &&
               place[R + y[(robot_direc + 2) % 4]][C + x[(robot_direc + 2) % 4]] == 1){
                return sweep;
            }
            robot_direc = (robot_direc != 0) ? robot_direc - 1 : 3;
            if(possible(R + y[robot_direc], C + x[robot_direc]) &&
               place[R + y[robot_direc]][C + x[robot_direc]] == 0){
                R += y[robot_direc];
                C += x[robot_direc];
                break;
            }
        }
    }
}

int main() {
    scanf("%d %d\n%d %d %d", &N, &M, &robot_loc.first, &robot_loc.second, &robot_direc);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &place[i][u]);
    printf("%d", sweeping());
    return 0;
}
