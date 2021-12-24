// LCA 탐색 방법과 비슷한 알고리즘으로 접근
// 먼저 wei_sparse로 각 노드의 2^i 부모까지의 거리를 재어 놓고,
// 1 쿼리(두 노드 사이의 거리)가 들어왔을 때는 a와 lca의 거리, b와
// lca의 거리를 합하여 답을 내고, 2 쿼리(a 노드에서 b노드까지 가는
// 경로 중 k번째 노드)는 먼저 k 번째 노드가 a와 lca 사이에 있는지,
// b와 lca 사이에 있는지 확인하고 a와 lca 사이에 있으면 그대로 계산,
// b와 lca 사이에 있으면 k에서 a와 lca 사이의 거리를 뺀 후 계산한다
// 여기에서 실수한 점은 1 쿼리에서 거리를 계산할 때, a와 b에서 lca로
// 올라가면서 계산할 때 노드도 같이 계속 올라가주어야 했는데 이 계산을
// 안함. 다시 말하면
// ll tmpa = a;
// if(sqroot[i] <= a_len){
//     ans += wei_sparse[tmpa][i];
//     tmpa = sparse[tmpa][i];
//     a_len -= sqroot[i];
// }
// 이런 식으로 tmpa를 지정해서 거리를 계산할 기준 노드를 함께 계속
// 올려줘야 하는데 이걸 무시하고
// if(sqroot[i] <= a_len){
//     ans += wei_sparse[a][i];
//     a_len -= sqroot[i];
// }
// 이렇게 계산함. 이렇게 계산하면 거리가 계속 겹쳐서 이상한 값을 내게 됨

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
#define pp std::pair<ll, ll>

const ll MAX = 100005, lgMAX = 17;
const ll sqroot[18] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048,
                       4096, 8192, 16384, 32768, 65536, 131072};
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
        for(ll u = lgMAX - 1; u >= 0; --u){
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
    ll tmpa = a, tmpb = b, ans = 0, lca_node = LCA(a, b);
    ll a_len = depth[a] - depth[lca_node];
    ll b_len = depth[b] - depth[lca_node];
    for(ll i = lgMAX - 1; i >= 0; --i){
        
        if(sqroot[i] <= a_len){
            ans += wei_sparse[tmpa][i];
            tmpa = sparse[tmpa][i];
            a_len -= sqroot[i];
        }
        if(sqroot[i] <= b_len){
            ans += wei_sparse[tmpb][i];
            tmpb = sparse[tmpb][i];
            b_len -= sqroot[i];
        }
    }
    return ans;
}
ll k_node(ll a, ll b, ll k){
    --k;
    ll ans, lca_node = LCA(a, b);
    ll a_len = depth[a] - depth[lca_node];
    ll b_len = depth[b] - depth[lca_node];
    if(k == a_len)
        return lca_node;
    else if(k < a_len){
        ans = a;
        for(ll i = lgMAX - 1; i >= 0; --i){
            if(k >= sqroot[i]){
                ans = sparse[ans][i];
                k -= sqroot[i];
            }
        }
        return ans;
    }
    else{
        ans = b;
        k = b_len - (k - a_len);
        for(ll i = lgMAX - 1; i >= 0; --i){
            if(k >= sqroot[i]){
                ans = sparse[ans][i];
                k -= sqroot[i];
            }
        }
        return ans;
    }
}

int main() {
    memset(depth, -1, sizeof(depth));
    memset(sparse, -1, sizeof(sparse));
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
