#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>

const int MAX = 100005;
int T, V, E, scc_groups[MAX], in_deg[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX];

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        if(!visited[next])
            dfs(next);
    }
    stk.push(cur);
}
void r_dfs(int cur){
    mini_ans.push_back(cur);
    visited[cur] = true;
    for(int i = 0; i < r_graph[cur].size(); ++i){
        int next = r_graph[cur][i];
        if(!visited[next])
            r_dfs(next);
    }
}
void SCC(){
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        if(visited[cur]) continue;

        mini_ans.clear();
        r_dfs(cur);

        int scc_idx = mini_ans[0];
        for(int i = 0; i < mini_ans.size(); ++i){
            scc_groups[mini_ans[i]] = scc_idx;
        }
        in_deg[scc_idx] = 0;
    }
}
void in_degree_cal(){
    for(int i = 0; i < V; ++i){
        for(int u = 0; u < r_graph[i].size(); ++u){
            int from = r_graph[i][u];
            if(scc_groups[i] != scc_groups[from])
                ++in_deg[scc_groups[i]];
        }
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(visited, false, sizeof(visited));
        memset(in_deg, -1, sizeof(in_deg));
        for(int i = 0; i < MAX; ++i){
            graph[i].clear();
            r_graph[i].clear();
        }
        while(!stk.empty())
            stk.pop();

        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            r_graph[b].push_back(a);
        }
        for(int i = 0; i < V; ++i)
            if(!visited[i])
                dfs(i);
                
        memset(visited, false, sizeof(visited));
        SCC();
        in_degree_cal();
        int start_size = 0, point = -1;
        for(int i = 0; i < V; ++i){
            start_size += (!in_deg[i]) ? 1 : 0;
            point = (!in_deg[i]) ? i : point;
        }
        if(start_size > 1)
            printf("Confused\n\n");
        else{
            for(int i = 0; i < V; ++i)
                if(scc_groups[i] == point)
                    printf("%d\n", i);
            puts("");
        }
    }
    return 0;
}
