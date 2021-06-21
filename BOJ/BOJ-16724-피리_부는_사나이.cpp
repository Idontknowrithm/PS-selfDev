#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>
#define r first
#define c second

int N, M, ans, trace = 1, visited[1005][1005];
std::string pipe_map[1005];

pp direction(int R, int C){
    if(pipe_map[R][C] == 'D')
        return {R + 1, C};
    if(pipe_map[R][C] == 'U')
        return {R - 1, C};
    if(pipe_map[R][C] == 'L')
        return {R, C - 1};
    if(pipe_map[R][C] == 'R')
        return {R, C + 1};
}
void find_road(int R, int C){
    pp tmp = {R, C};
    visited[tmp.r][tmp.c] = trace;
    while(1){
        tmp = direction(tmp.r, tmp.c);
        if(visited[tmp.r][tmp.c] == trace){
            ++ans;
            break;
        }
        else if(visited[tmp.r][tmp.c]){
            break;
        }
        visited[tmp.r][tmp.c] = trace;
    }
    ++trace;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    for(int i = 0; i < N; ++i)
        std::cin >> pipe_map[i];
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(!visited[i][u])
            find_road(i, u);
    std::cout << ans;
    return 0;
}
