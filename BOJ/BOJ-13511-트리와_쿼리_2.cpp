#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
#define pp std::pair<ll, ll>

const ll MAX = 100005, lgMAX = 17;
ll N, M, depth[MAX], sparse[MAX][25], wei_sparse[MAX][25];
std::vector<pp> graph[MAX];

void DFS(ll cur){
    for(ll i = 0; i < graph[cur].size(); ++i){
        ll next = graph[cur][i].first;
        ll wei = graph[cur][i].second;
        if(depth[next] == -1){
            sparse[next][0] = cur;
            wei_sparse[next][0] = wei;
            depth[next] = depth[cur] + 1;
            DFS(next);
        }
    }
}
void set_sparse(){
    for(ll i = 0; i < lgMAX; ++i)
    for(ll u = 2; u <= N; ++u){
        ll parent = sparse[u][i];
        if(parent != -1){
            sparse[u][i + 1] = sparse[parent][i];
            wei_sparse[u][i + 1] = wei_sparse[parent][i] + wei_sparse[u][i];
        }
    }
}
ll LCA(ll a, ll b){
    if(depth[a] < depth[b]) 
        std::swap(a, b);
    ll diff = depth[a] - depth[b];
    for(ll u = 0; diff; ++u){
        if(diff & 1) a = sparse[a][u];
        diff >>= 1;
    }
    if(a != b){
        for(ll u = lgMAX; u >= 0; --u){
            if(sparse[a][u] != -1 && sparse[a][u] != sparse[b][u]){
                a = sparse[a][u];
                b = sparse[b][u];
            }
        }
        a = sparse[a][0];
    }
    return a;
}
ll cost(ll a, ll b){
    ll lca_node = LCA(a, b);
    ll a_len = depth[lca_node] - depth[a];
    ll b_len = depth[lca_node] - depth[b];
}
ll k_node(ll a, ll b, ll k){

}

int main() {
    memset(depth, -1, sizeof(depth));
    memset(sparse, -1, sizeof(sparse));
    memset(wei_sparse, -1, sizeof(wei_sparse));
    scanf("%lld", &N);
    for(ll i = 0; i < N - 1; ++i){
        ll a, b, w;
        scanf("%lld %lld %lld", &a, &b, &w);
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    depth[1] = 0;
    DFS(1);
    set_sparse();

    scanf("%lld", &M);
    for(ll i = 0; i < M; ++i){
        ll query, u, v, k;
        scanf("%lld", &query);
        if(query == 1){
            scanf("%lld %lld", &u, &v);
            printf("%lld\n", cost(u, v));
        }
        else{
            scanf("%lld %lld %lld", &u, &v, &k);
            printf("%lld\n", k_node(u, v, k));
        }
    }
    return 0;
}
