// 단절선: 현재 정점에서 바로 윗 부모가 아닌 다른 연결된 노드로 탐색했을 때
//        dfs tree 상 정점 번호가 현재 정점보다 클 때 현재 정점과 탐색한 정점을
//        잇는 간선이 단절선
// 정점 고유번호: 정점 번호
// dfs tree 상의 번호: dfs 번호
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define pp std::pair<int, int>

const int MAX_V = 100005;
bool cutV[MAX_V];
int V, E, ans, order_ptr, order[MAX_V];
std::vector<int> graph[MAX_V];
std::vector<pp> ans_edges;

// 현재 정점 번호가 cur이고, 그 정점의 부모 정점번호가 parent일 때
// cur에서 갈 수 있는 dfs번호 중 가장 작은 값 반환
int find_cutV(int cur, int parent){
    // ret = order[cur]: 만약 연결되어있는 자식노드가 없으면
    //   갈 수 있는 가장 높은 dfs 번호는 자신이므로 미리 ret에 저장
    int ret = order[cur] = order_ptr++;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        // cur의 부모로 연결된 간선은 제외해야 하므로
        if(next == parent) continue;
        // 탐색 대상인 자식 노드를 처음 방문했을때(order 배열이
        // update 되지 않았을 때
        if(order[next] == -1){
            // 자식 노드에서 갈 수 있는 가장 작은 dfs 번호를 저장
            int order_max = find_cutV(next, cur);
            // 갈 수 있는 가장 작은 dfs 번호가 cur의 dfs번호보다 크다면
            // next와 cur를 있는 간선이 단절선
            if(order_max > order[cur])
                ans_edges.push_back({std::min(next, cur), std::max(next, cur)});
            
            // 반환 값이 가장 작은 dfs 번호이므로 이를 반영
            ret = std::min(ret, order_max);
        }
        else{
            // 탐색 대상인 자식 노드가 이미 update 되어있다면
            // dfs 탐색할 필요가 없고, 가장 작은 dfs 번호만 
            // 반환하면 되므로 이를 반영
            ret = std::min(ret, order[next]);
        }
    }
    return ret;
}

int main() {
    memset(order, -1, sizeof(order));
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= V; ++i)
        if(order[i] == -1)
            find_cutV(i, 0);
    printf("%d\n", ans_edges.size());
    std::sort(ans_edges.begin(), ans_edges.end());
    for(int i = 0; i < ans_edges.size(); ++i)
        printf("%d %d\n", ans_edges[i].first, ans_edges[i].second);
        
    return 0;
}
