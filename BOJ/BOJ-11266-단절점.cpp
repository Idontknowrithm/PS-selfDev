

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

const int MAX = 10005;
bool cutV[MAX];
int V, E, ans, order_ptr, order[MAX], visited[MAX];
std::vector<int> graph[MAX];

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
    }
    for(int i = 1; i <= V; ++i)
        if(!visited[i])
            find_cutV(i, true);
    for(int i = 1; i <= V; ++i)
        ans += (cutV[i]) ? 1 : 0;
    printf("%d\n", ans);
    for(int i = 1; i <= V; ++i)
        if(cutV[i])
            printf("%d ", i);
    return 0;
}
