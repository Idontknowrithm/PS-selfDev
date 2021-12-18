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
