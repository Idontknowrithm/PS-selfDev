#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 500005;
int N, M, S, P, ans, scc_idx = 1;
int scc_group[MAX], atm[MAX], scc_atm[MAX], tmp_ans[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<pp> edges;
std::set<pp> edge_filter;
std::vector<int> mini_ans, rest, graph[MAX], r_graph[MAX], scc_graph[MAX];

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
        for(int i = 0; i < mini_ans.size(); ++i)
            scc_group[mini_ans[i]] = scc_idx;
        
        ++scc_idx;
    }
    --scc_idx;
}
void BFS(){
    std::queue<int> que;
    que.push(scc_group[S]);
    tmp_ans[scc_group[S]] = scc_atm[scc_group[S]];
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(int i = 0; i < scc_graph[cur].size(); ++i){
            int next = scc_graph[cur][i];
            if(tmp_ans[next] < tmp_ans[cur] + scc_atm[next]){
                tmp_ans[next] = tmp_ans[cur] + scc_atm[next];
                que.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        r_graph[b].push_back(a);
        edges.push_back({a, b});
    }
    for(int i = 0; i < N; ++i)
        scanf("%d", &atm[i + 1]);
    scanf("%d %d", &S, &P);
    for(int i = 0; i < P; ++i){
        int a;
        scanf("%d", &a);
        rest.push_back(a);
    }
    for(int i = 1; i <= N; ++i)
        if(!visited[i])
            dfs(i);
            
    memset(visited, false, sizeof(visited));
    SCC();
    
    for(int i = 1; i <= N; ++i){
        scc_atm[scc_group[i]] += atm[i];
    }
    for(int i = 0; i < edges.size(); ++i){
        int a = edges[i].first, b = edges[i].second;
        if(scc_group[a] != scc_group[b])
            edge_filter.insert({scc_group[a], scc_group[b]});
    }
    for(auto i : edge_filter)
        scc_graph[i.first].push_back(i.second);
    
    BFS();
    for(int i = 0; i < rest.size(); ++i)
        ans = std::max(ans, tmp_ans[scc_group[rest[i]]]);
    
    printf("%d", ans);
    return 0;
}
