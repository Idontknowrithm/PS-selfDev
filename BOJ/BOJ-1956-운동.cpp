// 모든 정점을 시작으로 다익스트라 돌려서 시작점으로 도착할 수 있으면 가능,
// 아니면 불가능으로 했는데, 그냥 플로이드 와샬로 돌려서도 가능했음

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

const int MAX = 405, INF = 1000000000;
int V, E;
std::vector<pp> graph[MAX];

int dijk(int start){
    int dist[MAX];
    std::priority_queue<pp, std::vector<pp>, std::greater<pp>> pq;
    for(int i = 0; i < MAX; ++i)
        dist[i] = INF;
    dist[start] = 0;
    pq.push({start, 0});
    while(!pq.empty()){
        int curV = pq.top().first, curD = pq.top().second;
        pq.pop();
        if(curD > dist[curV]) continue;

        for(int i = 0; i < graph[curV].size(); ++i){
            int nextV = graph[curV][i].first, wei = graph[curV][i].second;
            if(!dist[nextV] || dist[nextV] > dist[curV] + wei){
                dist[nextV] = dist[curV] + wei;
                pq.push({nextV, dist[nextV]});
            }
        }
    }
    return (!dist[start]) ? INF : dist[start];
}

int main() {
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    int ans = INF;
    for(int i = 1; i <= V; ++i){
        ans = std::min(ans, dijk(i));
    }
    printf("%d", (ans == INF) ? -1 : ans);
    return 0;
}
