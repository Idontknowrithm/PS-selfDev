// 가까운 거리의 최단경로는 충분히 bfs로 가능하다는 생각으로
// 문제를 접근하는 실수를 저지름
// 보고 적당히 노드 적고 최단 경로 필요할 것 같은 곳에는 플로이드 와샬 쓰기
// (n^3 정도 안쪽으로 들어온다면..?)

#include<iostream>
#include<algorithm>

const int INF = 999999;
int N, M, R, ans, items[105], graph[105][105];

int main() {
    int a, b, l;
    for(int i = 0; i < 105; ++i)
    for(int u = 0; u < 105; ++u)
        graph[i][u] = (i == u) ? 0 : INF;
    
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &items[i]);
    for(int i = 0; i < R; ++i){
        scanf("%d %d %d", &a, &b, &l);
        graph[a][b] = l;
        graph[b][a] = l;
    }
    for(int k = 1; k <= N; ++k)
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u)
        if(graph[i][u] > graph[i][k] + graph[k][u]){
            graph[i][u] = graph[i][k] + graph[k][u];
        }
    
    for(int i = 1; i <= N; ++i){
        int tmp = items[i];
        for(int u = 1; u <= N; ++u){
            if(i == u) continue;
            tmp += (graph[i][u] <= M) ? items[u] : 0;
        }
        ans = (ans < tmp) ? tmp : ans;
    }
    printf("%d", ans);
    return 0;
}
