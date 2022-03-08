#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

const int MAX = 100005, lgMAX = 17;
int N, M, depth[MAX], sparse[MAX][25];
std::vector<int> graph[MAX];

void DFS(int cur){
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        if(depth[next] == -1){
            sparse[next][0] = cur;
            depth[next] = depth[cur] + 1;
            DFS(next);
        }
    }
}
void set_sparse(){
    for(int i = 0; i < lgMAX; ++i)
    for(int u = 2; u <= N; ++u){
        if(sparse[u][i] != -1)
            sparse[u][i + 1] = sparse[sparse[u][i]][i];
    }
}
int LCA(int a, int b){
    if(depth[a] < depth[b]) 
        std::swap(a, b);
    int diff = depth[a] - depth[b];
    for(int u = 0; diff; ++u){
        if(diff & 1) a = sparse[a][u];
        diff >>= 1;
    }
    if(a != b){
        for(int u = lgMAX; u >= 0; --u){
            if(sparse[a][u] != -1 && sparse[a][u] != sparse[b][u]){
                a = sparse[a][u];
                b = sparse[b][u];
            }
        }
        a = sparse[a][0];
    }
    return a;
}

int main() {
    memset(depth, -1, sizeof(depth));
    memset(sparse, -1, sizeof(sparse));
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    depth[1] = 0;
    DFS(1);
    set_sparse();

    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}
