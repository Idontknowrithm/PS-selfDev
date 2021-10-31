// 메모리 초과 이유: 인트 대신 롱롱 씀(인트일 때 150메가 정도 쓰는데
// 롱롱은 인트 두 배니까 어쩔 수 없긴 한데 이렇게 메모리 제한 주는 건 너무했네)
// 시간 초과 이유: 우선순위 큐의 비교부분에서 거리가 비교대상이 되어야 했는데
// 주 비교대상이 정점 번호로 되어있었음
// 최단거리에서 cost라는 제약이 걸려있었음 -> 메모이제이션으로 해결해야했던 문제
// DP의 그 dfs스러운 알고리즘이 필요한 건 아니었고, 그냥 메모이제이션만
// DP스럽게 해주면 됐음

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define ppp std::pair<int, std::pair<int, int>>
#define uno first
#define dos second.first
#define tres second.second

const int MAX = 105, INF = 1000000005;
int T, N, M, K, cache[MAX][10005];
std::vector<ppp> graph[MAX];

int dijk(){
    std::priority_queue<ppp, std::vector<ppp>, std::greater<ppp>> pq;
    for(int i = 0; i < MAX; ++i)
    for(int u = 0; u < 10005; ++u)
        cache[i][u] = INF;
    cache[1][0] = 0;
    pq.push({0, {0, 1}});

    while(!pq.empty()){
        int curD = pq.top().uno, curC = pq.top().dos, curV = pq.top().tres;
        pq.pop();
        if(curD > cache[curV][curC]) continue;

        for(int i = 0; i < graph[curV].size(); ++i){
            int nextV = graph[curV][i].uno;
            int c = graph[curV][i].dos, d = graph[curV][i].tres;
            if(curC + c <= M && cache[nextV][curC + c] > curD + d){
                cache[nextV][curC + c] = curD + d;
                pq.push({curD + d, {curC + c, nextV}});
            }    
        }
    }
    int ans = INF;
    for(int i = 0; i < 10005; ++i)
        ans = std::min(ans, cache[N][i]);
    return ans;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < K; ++i){
            int u, v, c, d;
            scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u].push_back({v, {c, d}});
        }
        memset(cache, -1, sizeof(cache));
        int ans = dijk();
        if(ans == -1 || ans >= INF)
            printf("Poor KCM\n");
        else 
            printf("%d\n", ans);
        for(int i = 0; i < MAX; ++i)
            graph[i].clear();
    }
    return 0;
}
