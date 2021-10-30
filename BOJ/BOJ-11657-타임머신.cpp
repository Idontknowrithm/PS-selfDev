#include<iostream>
#include<algorithm>
#include<vector>
#define ppp std::pair<ll, std::pair<ll, ll>>
#define uno first
#define dos second.first
#define tres second.second
#define ll long long

const ll INF = 99999999999;
ll V, E, vertexes[505];
bool impossible = false;
std::vector<ppp> edges;

// Bellman-Ford
void BF(){
    for(int i = 0; i < V; ++i){
        for(int u = 0; u < edges.size(); ++u){
            ll &curV = vertexes[edges[u].uno];
            ll &nextV = vertexes[edges[u].dos];
            ll weight = edges[u].tres;
            if(curV != INF && curV + weight < nextV){
                nextV = curV + weight;
            }
        }
    }
    for(int i = 0; i < V; ++i){
        for(int u = 0; u < edges.size(); ++u){
            ll &curV = vertexes[edges[u].uno];
            ll &nextV = vertexes[edges[u].dos];
            ll weight = edges[u].tres;
            if(curV != INF && curV + weight < nextV){
                impossible = true;
                return;
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &V, &E);
    for(ll i = 0; i < E; ++i){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        edges.push_back({a, {b, c}});
    }
    for(ll i = 2; i <= V; ++i)
        vertexes[i] = INF;
    vertexes[1] = 0;

    BF();
    if(impossible)
        printf("-1");
    else
        for(int i = 2; i <= V; ++i)
            printf("%lld\n", (vertexes[i] == INF) ? -1 : vertexes[i]);

    return 0;
}
