#include<iostream>
#include<cstring>
#include<vector>

const int MAX = 505;
int T, N, M, is_visited, graph[MAX][MAX], rank[MAX], topological[MAX];
bool cycle, visited[MAX], tmp_visited[MAX];

void DFS(int start, int prev){
    if(tmp_visited[start]){
        cycle = true;
        return;
    }
    visited[start] = true;
    for(int i = 1; i <= N; ++i){
        if(graph[start][i] && i != prev){
            tmp_visited[start] = true;
            DFS(i, start);
            tmp_visited[start] = false;
        }
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(graph, 0, sizeof(graph));
        memset(topological, 0, sizeof(topological));
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &rank[i]);
        for(int i = 0; i < N - 1; ++i)
        for(int u = i + 1; u < N; ++u){
            graph[rank[i]][rank[u]] = 1;
            ++topological[rank[u]];
        }            
        
        scanf("%d", &M);
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            if(graph[a][b]){
                graph[a][b] = 0;
                graph[b][a] = 1;
                --topological[b];
                ++topological[a];
            }
            else{
                graph[a][b] = 1;
                graph[b][a] = 0;
                --topological[a];
                ++topological[b];
            }
        }
        cycle = false;
        is_visited = 0;
        for(int i = 1; i <= N; ++i){
            if(!topological[i]){
                tmp_visited[i] = true;
                DFS(i, -1);
                break;
            }
        }
        for(int i = 1; i <= N; ++i)
            is_visited += (visited[i]) ? 1 : 0;
        if(cycle || is_visited != N){
            printf("IMPOSSIBLE\n");
            continue;
        }
        std::vector<int> ans;
        bool question = false;
        while(ans.size() != N){
            int equal = 0, idx;
            for(int i = 1; i <= N; ++i){
                if(!topological[i]){
                    ++equal;
                    idx = i;
                }
            }
            if(equal != 1){
                question = true;
                break;
            }
            ans.push_back(idx);
            topological[idx] = 10000005;
            for(int i = 1; i <= N; ++i){
                if(graph[idx][i])
                    --topological[i];
            }
        }
        if(question)
            printf("?\n");
        else{
            for(int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            puts("");
        }
    }
    return 0;
}
