#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define pp std::pair<int, int>

const int MAX_V = 100005;
bool cutV[MAX_V];
int V, E, ans, order_ptr, order[MAX_V], visited[MAX_V];
std::vector<int> graph[MAX_V];
std::vector<pp> edges;

int find_cutV(int cur, bool is_root){
    visited[cur] = 1;
    int child = 0, ret = order[cur] = order_ptr++;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        if(order[next] == -1){
            ++child;
            int order_max = find_cutV(next, false);
            if(!is_root && order_max >= order[cur])
                cutV[cur] = true;
            
            ret = std::min(ret, order_max);
        }
        else{
            ret = std::min(ret, order[next]);
        }
    }
    if(is_root && child >= 2)
        cutV[cur] = true;
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
        if(a < b)
            edges.push_back({a, b});
        else 
            edges.push_back({b, a});
    }
    std::sort(edges.begin(), edges.end());
    for(int i = 1; i <= V; ++i)
        if(!visited[i])
            find_cutV(i, true);
    for(int i = 1; i <= E; ++i)
        ans += (cutV[edges[i].first] && cutV[edges[i].second]) ? 1 : 0;
    printf("%d\n", ans);
    for(int i = 1; i <= V; ++i)
        if(cutV[edges[i].first] && cutV[edges[i].second])
            printf("%d %d\n", edges[i].first, edges[i].second);
    return 0;
}
