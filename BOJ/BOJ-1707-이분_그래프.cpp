// 이분 그래프의 개념: visited를 하나는 1, 그 다음은 2, 그 다음은 1 순으로 기록했을 때,
//                  인접한 노드 끼리의 visited 값이 달라야 함
// 사이클이있으면 이분 그래프가 안되는 줄 알았다

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

const int MAX = 20005;
int K, V, E, visited[MAX];
bool bipartite;
std::vector<int> graph[MAX];

void BFS(int start){
    std::queue<int> que;
    que.push(start);
    visited[start] = 1;
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        for(int i = 0; i < graph[tmp].size(); ++i){
            int next = graph[tmp][i];
            if(tmp != next && visited[next] == visited[tmp]){
                bipartite = false;
                return;
            }
            if(!visited[next]){
                visited[next] = (visited[tmp] == 1) ? 2 : 1;
                que.push(next);
            }
        }
    }
}

int main() {
    for(scanf("%d", &K); K > 0; --K){
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(visited, 0, sizeof(visited));
        bipartite = true;
        for(int i = 1; i <= V; ++i){
            if(!visited[i]){
                BFS(i);
            }
        }
        printf("%s\n", (!bipartite) ? "NO" : "YES");
        for(int i = 0; i <= V; ++i)
            graph[i].clear();
    }
    return 0;
}
