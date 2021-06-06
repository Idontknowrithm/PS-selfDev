// 무리하게 bfs로만 생각을 할 필요가 없을 것 같다.
// bfs로 풀 때 중복이 많이 생길 것 같거나, bfs로 풀다가 문제가 계속 생기는 상황이라면
// 충분히 dfs를 생각할 수 있어야 한다.

#include<iostream>
#include<queue>
#include<algorithm>
#include<set>

typedef struct{
    int r, c, alphabet, len;
}data;
bool operator <(data a, data b){
    if(a.alphabet == b.alphabet)
        if(a.r == b.r)
            if(a.c == b.c)
                return a.len < b.len;
            else 
                return a.c < b.c;
        else 
            return a.r < b.r;
    else
        return a.alphabet < b.alphabet;
}

int y[4] = {0, -1, 0, 1};
int x[4] = {1, 0, -1, 0};
int R, C, visited[25][25];
std::string board[25];

bool possible(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}
int move(){
    int ans = 0;
    std::queue<data> bfs;
    std::set<data> overlap_check;
    bfs.push({0, 0, (1 << (board[0][0] - 'A')), 1});
    visited[0][0] = 1;
    while(!bfs.empty()){
        data tmp = bfs.front();
        bfs.pop();
        ans = std::max(ans, tmp.len);
        for(int i = 0; i < 4; ++i){
            if(possible(tmp.r + y[i], tmp.c + x[i]) &&
               visited[tmp.r + y[i]][tmp.c + x[i]] <= tmp.len + 1 && 
               !(tmp.alphabet & (1 << (board[tmp.r + y[i]][tmp.c + x[i]] - 'A')))){
                data next; int tmpalpha = board[tmp.r + y[i]][tmp.c + x[i]] - 'A';
                visited[tmp.r + y[i]][tmp.c + x[i]] = tmp.len + 1;
                next.r = tmp.r + y[i];
                next.c = tmp.c + x[i];
                next.alphabet = tmp.alphabet | (1 << tmpalpha);
                next.len = tmp.len + 1;
                if(overlap_check.find(next) != overlap_check.end()) continue;
                bfs.push(next);
                overlap_check.insert(next);
            }
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for(int i = 0; i < R; ++i)
        std::cin >> board[i];
    std::cout << move();
    return 0;
}
