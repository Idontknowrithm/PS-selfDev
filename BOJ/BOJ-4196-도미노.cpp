#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

const int MAX = 100005;
int T, N, M, belong[MAX];
bool visited[MAX], starter[MAX];
std::stack<int> stk;
std::vector<int> mini_scc, scc_set[MAX], graph[MAX], r_graph[MAX];

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
        scc_set[mini_scc[0]] = mini_scc;
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(belong, -1, sizeof(belong));
        memset(visited, false, sizeof(visited));
        memset(starter, true, sizeof(starter));
        for(int i = 0; i < MAX; ++i){
            graph[i].clear();
            r_graph[i].clear();
            scc_set[i].clear();
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
            bool possible = true;
            if(scc_set[i].size() != 0){
                for(int u = 0; u < scc_set[i].size(); ++u){
                    int cur = scc_set[i][u];
                    for(int k = 0; k < r_graph[cur].size(); ++k){
                        int valid = r_graph[cur][k];
                        if(belong[valid] != -1 && belong[valid] != i)
                            possible = false;
                    }
                }
            }
            ans += (possible) ? 1 : 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
