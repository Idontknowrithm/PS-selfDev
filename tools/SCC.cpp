// Kosaraju

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>

const int MAX = 10005;
int V, E, ans_size;
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX], ans[MAX];

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
        std::sort(mini_ans.begin(), mini_ans.end());
        ans[mini_ans[0]] = mini_ans;
        ++ans_size;
    }
}

int main() {
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        r_graph[b].push_back(a);
    }
    for(int i = 1; i <= V; ++i)
        if(!visited[i])
            dfs(i);
            
    memset(visited, false, sizeof(visited));
    SCC();
    printf("%d\n", ans_size);
    for(int i = 1; i <= V; ++i){
        if(ans[i].size()){
            for(int u = 0; u < ans[i].size(); ++u)
                printf("%d ", ans[i][u]);
            puts("-1");
        }
    }
    return 0;
}
