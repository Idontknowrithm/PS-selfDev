// 자동으로 될거라는 생각으로 많은 시간을 날림
// 특정한 순서 등의  알고리즘이 제시되면 확실히 자동으로 되는지 보고,
// 애매하거나 안될 것 같으면 그 부분의 알고리즘을 강제로 되게 만들기


#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<vector>

typedef struct{
    int row;
    int col;
    int dist;
}distInfo;

int N, distance, eat, food, sharkR, sharkC, sharkM = 2, sea[20][20], visited[20][20];
bool possible; std::vector<distInfo> que;

bool compare(distInfo a, distInfo b){
    if(a.dist == b.dist){
        if(a.row == b.row){
            return a.col < b.col;
        }
        return a.row < b.row;
    }
    return a.dist < b.dist;

}
void launchTime(int r, int c, int d){

    ++eat;
    sea[sharkR][sharkC] = 0;
    sharkR = r;
    sharkC = c;
    sea[sharkR][sharkC] = 9;
    distance += d;
}
bool in(int r, int c){
    return (r < N && r >= 0 && c < N && c >= 0);
}
void hunt(){
    int r, c, d;
    std::queue<distInfo> bfs;

    bfs.push({sharkR, sharkC, 0});
    visited[sharkR][sharkC] = 1;
    while(!bfs.empty()){
        r = bfs.front().row;
        c = bfs.front().col;
        d = bfs.front().dist;
        if(in(r - 1, c) && sea[r - 1][c] <= sharkM && !visited[r - 1][c]){
            if(sea[r - 1][c] != 0 && sea[r - 1][c] != sharkM){
                que.push_back({r - 1, c, d + 1});
            }
            visited[r - 1][c] = 1;
            bfs.push({r - 1, c, d + 1});
        }
        if(in(r + 1, c) && sea[r + 1][c] <= sharkM && !visited[r + 1][c]){
            if(sea[r + 1][c] != 0 && sea[r + 1][c] != sharkM){
                que.push_back({r + 1, c, d + 1});
            }
            visited[r + 1][c] = 1;
            bfs.push({r + 1, c, d + 1});
        }
        if(in(r, c - 1) && sea[r][c - 1] <= sharkM && !visited[r][c - 1]){
            if(sea[r][c - 1] != 0 && sea[r][c - 1] != sharkM){
                que.push_back({r, c - 1, d + 1});
            }
            visited[r][c - 1] = 1;
            bfs.push({r, c - 1, d + 1});
        }
        if(in(r, c + 1) && sea[r][c + 1] <= sharkM && !visited[r][c + 1]){
            if(sea[r][c + 1] != 0 && sea[r][c + 1] != sharkM){
                que.push_back({r, c + 1, d + 1});
            }
            visited[r][c + 1] = 1;
            bfs.push({r, c + 1, d + 1});
        }
        bfs.pop();
    }
}

int main () {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        scanf("%d", &sea[i][u]);
        if(sea[i][u] == 9){
            sharkR = i;
            sharkC = u;
        }
    }
    while(1){
        food = 0;
        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u){
            food += (sea[i][u] < sharkM && sea[i][u]) ? 1 : 0;
            visited[i][u] = 0;
        }
        if(!food)
            break;
            
        hunt();
        
        if(que.empty())
            break;
        else{
            std::sort(que.begin(), que.end(), compare);
            launchTime(que[0].row, que[0].col, que[0].dist);
        }
        
        if(eat == sharkM){
            eat = 0;
            ++sharkM;
        }

        que.clear();
    }
    printf("%d", distance);
    
    return 0;
}
