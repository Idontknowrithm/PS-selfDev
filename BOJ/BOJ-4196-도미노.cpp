// 보통의 알고리즘 문제는 더러운 연산을 요구하지 않는다. 따라서
// 요구하는 알고리즘을 깨끗하게 응용할 생각을 해야할 것 같다

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

const int MAX = 100005;
int T, N, M, belong[MAX], in_degree[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_scc, graph[MAX], r_graph[MAX];

void DFS(int cur){
    visited[cur] = true;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        if(!visited[next])
            DFS(next);
    }
    stk.push(cur);
}
void r_DFS(int cur){
    visited[cur] = true;
    mini_scc.push_back(cur);
    for(int i = 0; i < r_graph[cur].size(); ++i){
        int next = r_graph[cur][i];
        if(!visited[next])
            r_DFS(next);
    }
}
void SCC(){
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        if(visited[cur]) continue;

        mini_scc.clear();
        r_DFS(cur);
        for(int i = 0; i < mini_scc.size(); ++i){
            belong[mini_scc[i]] = mini_scc[0];
        }
        in_degree[mini_scc[0]] = 0;
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(belong, -1, sizeof(belong));
        memset(in_degree, -1, sizeof(in_degree));
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < MAX; ++i){
            graph[i].clear();
            r_graph[i].clear();
        }
        scanf("%d %d", &N, &M);
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            r_graph[b].push_back(a);
        }

        for(int i = 1; i <= N; ++i)
            if(!visited[i])
                DFS(i);

        memset(visited, false, sizeof(visited));
        SCC();
        int ans = 0;
        for(int i = 1; i <= N; ++i){
            for(int u = 0; u < graph[i].size(); ++u){
                int next = graph[i][u];
                if(belong[i] != belong[next]){
                    ++in_degree[belong[next]];
                }
            }
        }
        for(int i = 1; i <= N; ++i)
            ans += (!in_degree[i]) ? 1 : 0;
        printf("%d\n", ans);
    }
    return 0;
}
