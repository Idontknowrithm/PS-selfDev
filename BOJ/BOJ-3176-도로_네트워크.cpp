// sparse를 채울 때는 N번째 위의 부모 하나를 찾는 거라 2, 4, 8 순으로 
// 뛰어 올라가도 된다고 생각되는데 len_sparse를 채울 때는 N번째 위의 부모"까지의"
// 모든 간선을 보고 거기에서 최대 최소를 구해야하는 것 아닌가라는 생각이 들어서
// O(N)의 시간동안 위로 거슬러 올라가면서 최대 최소를 구해야되는 것으로 착각했다
// 그러나 다시 생각해보면, 모든 정점에 대해서 각 정점에 대한 하나 위의 부모를
// 잇는 간선의 최대 최소를 구했고, 그 다음은 모든 정점에 대해서 각 정점에 대한
// 둘 위의 부모를 잇는 간선의 최대 최소를 구해야 하는데 이때는 모든 정점에 대한
// 하나 위의 부모를 있는 간선에 대한 정보가 있으니 한 선으로 연결된 정보 두 개를
// 이으면 된다. 그러면 모든 정점에 대해서 각 정점에 대해서 둘 위의 부모를 잇는 
// 간선에 대한 최대 최소가 있다. 여기에서 이제 각 정점의 넷 위의 부모를 잇는 
// 간선에 대한 최대 최소를 구하려면 어차피 모든 정점에 대해서 둘 위의 부모를 잇는
// 간선에 대한 정보가 있을 것이므로, 이 둘 간선 정보를 두 개 합치면 넷 간선 정보가
// 나올 것이고, 이에 따라 넷 간선에 대한 최대 최소의 정보는 넷 간선을 모두 고려하는
// 원래 내가 착각했던 O(N)으로 돌아야만 가능할 것 같았던 최대 최소의 해를 가지고
// 있는 것이다

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 100005, lgMAX = 17;
int N, M, depth[MAX], sparse[MAX][25];
pp len_sparse[MAX][25]; // max, min
std::vector<pp> graph[MAX];

void DFS(int cur){
    for(int i = 0; i < graph[cur].size(); ++i){
        int nextn = graph[cur][i].first, nextw = graph[cur][i].second;
        if(depth[nextn] == -1){
            len_sparse[nextn][0] = {nextw, nextw};
            sparse[nextn][0] = cur;
            depth[nextn] = depth[cur] + 1;
            DFS(nextn);
        }
    }
}
void set_sparse(){
    for(int i = 0; i < lgMAX; ++i)
    for(int u = 2; u <= N; ++u){
        if(sparse[u][i] != -1){
            int parent = sparse[u][i];
            sparse[u][i + 1] = sparse[parent][i];
            len_sparse[u][i + 1].first = 
                std::max(len_sparse[u][i].first, len_sparse[parent][i].first);
            len_sparse[u][i + 1].second = 
                std::min(len_sparse[u][i].second, len_sparse[parent][i].second);
        }
    }
}
pp LCA(int a, int b){
    int min_val = 1000005, max_val = 0;
    if(depth[a] < depth[b]) 
        std::swap(a, b);
    int diff = depth[a] - depth[b];
    for(int u = 0; diff; ++u){
        if(diff & 1){
            max_val = std::max(max_val, len_sparse[a][u].first);
            min_val = std::min(min_val, len_sparse[a][u].second);
            a = sparse[a][u];
        }
        diff >>= 1;
    }
    if(a != b){
        for(int u = lgMAX; u >= 0; --u){
            if(sparse[a][u] != -1 && sparse[a][u] != sparse[b][u]){
                max_val = std::max(max_val, len_sparse[a][u].first);
                min_val = std::min(min_val, len_sparse[a][u].second);
                a = sparse[a][u];
                max_val = std::max(max_val, len_sparse[b][u].first);
                min_val = std::min(min_val, len_sparse[b][u].second);
                b = sparse[b][u];
            }
        }
        max_val = std::max(max_val, len_sparse[a][0].first);
        min_val = std::min(min_val, len_sparse[a][0].second);
        max_val = std::max(max_val, len_sparse[b][0].first);
        min_val = std::min(min_val, len_sparse[b][0].second);
    }
    return {max_val, min_val};
}

int main() {
    memset(len_sparse, -1, sizeof(len_sparse));
    memset(depth, -1, sizeof(depth));
    memset(sparse, -1, sizeof(sparse));
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    depth[1] = 0;
    DFS(1);
    set_sparse();

    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        pp ans = LCA(a, b);
        printf("%d %d\n", ans.second, ans.first);
    }
    return 0;
}
