#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

const int MAX = 20005;
int T, V, E, scc_groups[MAX], in_vertex[MAX], bool_ans[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX];

void conntector(int a, int b){
    a = (a < 0) ? 20001 + a : a;
    b = (b < 0) ? 20001 + b : b;
    graph[a].push_back(b);
    ++in_vertex[b];
    r_graph[b].push_back(a);
}
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
    }
}
void topol_sort(){
    std::queue<int> que;
    for(int i = 1; i <= 20000; ++i)
        if(!in_vertex[i])
            que.push(i);
    while(!que.empty()){
        int cur = que.front();
        int abs = (cur > 10000) ? 20001 - cur : cur;
        que.pop();
        if(bool_ans[abs] == -1)
            bool_ans[abs] = (cur > 10000) ? 1 : 0;
            
        for(int i = 0; i < graph[cur].size(); ++i){
            int next = graph[cur][i];
            if(--in_vertex[next] == 0)
                que.push(next);
        }
    }
}

int main() {
    memset(bool_ans, -1, sizeof(bool_ans));
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        conntector(-a, b);
        conntector(-b, a);
    }
    for(int i = 1; i <= V; ++i){
        if(!visited[i])
            dfs(i);
        if(!visited[20001 - i])
            dfs(20001 - i);
    }
            
    memset(visited, false, sizeof(visited));
    SCC();
    for(int i = 1; i <= V; ++i){
        if(scc_groups[i] == scc_groups[20001 - i]){
            printf("0");
            return 0;
        }
    }
    printf("1\n");
    topol_sort();
    for(int i = 1; i <= V; ++i)
        printf("%d ", bool_ans[i]);
    return 0;
}
