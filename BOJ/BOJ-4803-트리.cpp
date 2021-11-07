#include<iostream>
#include<cstring>
#include<queue>

const int MAX = 505;
int N, M;
bool cycle, graph[MAX][MAX], visited[MAX];

void DFS(int start, int prev){
    if(cycle) return;
    for(int i = 1; i <= N; ++i){
        if(i != start && i != prev && graph[start][i] && visited[i]){
            cycle = true;
            return;
        }
        if(i != start && graph[start][i] && !visited[i]){
            visited[i] = true;
            DFS(i, start);
            visited[i] = false;
        }
    }
}
void BFS(int start){
    std::queue<int> que;
    que.push(start);
    visited[start] = true;
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        for(int i = 1; i <= N; ++i){
            if(graph[start][i] && !visited[i]){
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

int main() {
    for(int T = 1; ; ++T){
        scanf("%d %d", &N, &M);
        if(!N && !N) break;

        memset(graph, false, sizeof(graph));
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a][b] = true;
            graph[b][a] = true;
        }
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int i = 1; i <= N; ++i){
            if(visited[i]) continue;
            cycle = false;
            visited[i] = true;
            DFS(i, -1);
            visited[i] = false;
            if(!cycle) ++ans;
            BFS(i);
        }
        printf("Case %d: ", T);
        if(!ans)
            printf("No trees.\n");
        else if(ans == 1)
            printf("There is one tree.\n");
        else 
            printf("A forest of %d trees.\n", ans);
    }
    return 0;
}
