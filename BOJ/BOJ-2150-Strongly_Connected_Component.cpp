// SCC를 찾는 문제인데 이를 찾는 알고리즘이 이미 존재함
// 코사라주 알고리즘으로 문제를 해결할 수 있는데, 주요 아이디어는
// 그래프의 모든 간선에 대해 역방향인 그래프를 만들고, 그래프에 대해
// dfs를 도는데 dfs를 탐색한 역순으로 stack에 노드 이름을 저장함
// 중간에 끊기면 노드 번호 순으로 다시 dfs로 탐색
// ex) 7까지의 노드가 있는 그래프에서 3-2-1 탐색하고 끊긴 후 4-7-5-6으로 탐색했다면
//     stack에는 1-2-3-6-5-7-4로 저장되어있어야 함
// 이후 stack의 top부터 하나씩 까면서 그 노드를 시작 삼아 역그래프에서 dfs 진행
// dfs가 진행된 묶음 단위로 SCC라 할 수 있음

#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


int V, E, num_ans, visited[10005], r_visited[10005];
std::vector<int> graph[10005], r_graph[10005], ans[10005], tmpans;
std::stack<int> SCC;

void dfs(int start){
    for(int i = 0; i < graph[start].size(); ++i){
        if(!visited[graph[start][i]]){
            visited[graph[start][i]] = 1;
            dfs(graph[start][i]);
            SCC.push(graph[start][i]);
        }
    }
}
void r_dfs(int start){
    for(int i = 0; i < r_graph[start].size(); ++i){
        if(!r_visited[r_graph[start][i]]){
            r_visited[r_graph[start][i]] = 1;
            r_dfs(r_graph[start][i]);
            tmpans.push_back(r_graph[start][i]);
        }
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
    for(int i = 1; i <= V; ++i){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
            SCC.push(i);
        }
    }
    while(!SCC.empty()){
        int tmp = SCC.top();
        SCC.pop();
        if(!r_visited[tmp]){
            r_visited[tmp] = 1;
            r_dfs(tmp);
            tmpans.push_back(tmp);
            std::sort(tmpans.begin(), tmpans.end());
            for(int i = 0; i < tmpans.size(); ++i)
                ans[tmpans[0]].push_back(tmpans[i]);
            tmpans.clear();
            ++num_ans;
        }
    }
    printf("%d\n", num_ans);
    for(int i = 1; i <= V; ++i){
        if(ans[i].size() > 0){
            for(auto u : ans[i])
                printf("%d ", u);
            puts("-1");
        }
    }
    return 0;
}
