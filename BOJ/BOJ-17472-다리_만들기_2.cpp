// 변수의 갱신 위치 잘 확인하기(원하는 곳에서 갱신되는가?)

#include<iostream>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>
#define ppp std::pair<int, std::pair<int, int>>
#define uno first
#define dos second.first
#define tres second.second

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, classifier = 1;
int islands[15][15], set[10], set_size[10], graph[10][10];
bool visited[15][15];
std::vector<ppp> edges;

int find_set(int num){
    if (set[num]==num)
        return num;
    int parent = find_set(set[num]);
    set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    if(first == second) return;

    if(set_size[first] < set_size[second])
        std::swap(first, second);

    set[second] = first;
    set_size[first] += set_size[second];
    set_size[second] = 0;
}
bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
void BFS(int r, int c){
    std::queue<pp> que;
    que.push({r, c});
    visited[r][c] = true;
    while(!que.empty()){
        int R = que.front().first, C = que.front().second;
        islands[R][C] = classifier;
        que.pop();
        for(int i = 0; i < 4; ++i){
            int rr = R + y[i], cc = C + x[i];
            if(possible(rr, cc) && !visited[rr][cc] && islands[rr][cc]){
                visited[rr][cc] = true;
                que.push({rr, cc});
            }
        }
    }
}
void classify(){
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        if(islands[i][u] && !visited[i][u]){
            BFS(i, u);
            ++classifier;
        }
    }
}
void connector(int r, int c){
    for(int i = 0; i < 4; ++i){
        int cur = islands[r][c];
        int tmpr = r, tmpc = c, len = 0;
        do{
            ++len;
            tmpr += y[i];
            tmpc += x[i];
        }while(possible(tmpr, tmpc) && !islands[tmpr][tmpc]);
        if(possible(tmpr, tmpc) && cur != islands[tmpr][tmpc] && len > 2){
            int next = islands[tmpr][tmpc];
            if(cur > next) std::swap(cur, next);
            if(graph[cur][next])
                graph[cur][next] = std::min(graph[cur][next], len - 1);
            else 
                graph[cur][next] = len - 1;
        }
    }
}
int main() {
    for(int i = 0; i < 10; ++i){
        set[i] = i;
        set_size[i] = 1;
    }
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &islands[i][u]);
    classify();
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        if(islands[i][u])
            connector(i, u);
            
    for(int i = 1; i < classifier; ++i)
    for(int u = 1; u < classifier; ++u)
        if(graph[i][u])
            edges.push_back({graph[i][u], {i, u}});
    std::sort(edges.begin(), edges.end());
    int ans = 0;
    for(int i = 0; i < edges.size(); ++i){
        int a = edges[i].dos, b = edges[i].tres;
        if(find_set(a) != find_set(b)){
            union_set(find_set(a), find_set(b));
            ans += edges[i].uno;
        }
        if(set_size[find_set(a)] == classifier - 1)
            break;
    }
    printf("%d", (set_size[find_set(1)] != classifier - 1) ? -1 : ans);
    return 0;
}
