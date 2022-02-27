#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cstring>
#include<cmath>
#define pp std::pair<int, int>
#define ppp std::pair<int, std::pair<int, int>>
#define ll long long
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL)
#define test std::cout << "ok"
#define endl std::cout << "\n"

const int MAX = 100005;
int V, E, ans, scc_idx, scc_group[MAX], scc_size[MAX], reprstt[MAX];
bool visited[MAX], can[MAX];
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
        scc_size[scc_idx] = mini_ans.size();
        reprstt[scc_idx] = mini_ans[0];
        for(int i = 0; i < mini_ans.size(); ++i)
            scc_group[mini_ans[i]] = scc_idx;
        ++scc_idx;
    }
}
void BFS(int start){
    std::queue<int> que;

    visited[start] = true;
    can[start] = false;
    que.push(start);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(int i = 0; i < r_graph[cur].size(); ++i){
            int next = r_graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                can[next] = false;
                que.push(next);
            }
        }
    }
}

int main() {
    memset(can, true, sizeof(can));

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

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < scc_idx; ++i){
        if(scc_size[i] > 1){
            BFS(reprstt[i]);
        }
    }
    for(int i = 1; i <= V; ++i)
        if(can[i])
            ++ans;
    printf("%d", ans);

    return 0;
}
