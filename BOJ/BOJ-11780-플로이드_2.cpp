// 반복으로 답이 안나올 것 같거나 구현이 어렵게 느껴진다면
// 재귀로의 전환을 생각해봐야함

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

const int INF = 1000000005;
int N, M, graph[105][105], floyd[105][105], cache[105][105];
std::vector<int> trace;

void path_finder(int start, int end){
    if(!cache[start][end]){
        trace.push_back(start);
        trace.push_back(end);
        return;
    }
    path_finder(start, cache[start][end]);
    trace.pop_back();
    path_finder(cache[start][end], end);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u)
        graph[i][u] = INF;

    for(int i = 0; i < M; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = std::min(graph[a][b], c);
    }
    
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int u = 1; u <= N; ++u){
                if(i == u) continue;
                if(graph[i][k] + graph[k][u] < graph[i][u]){
                    graph[i][u] = graph[i][k] + graph[k][u];
                    cache[i][u] = k;
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u)
            printf("%d ", (graph[i][u] == INF) ? 0 : graph[i][u]);
        puts("");
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u){
            if(graph[i][u] == INF){
                printf("0\n");
            }
            else{
                trace.clear();
                path_finder(i, u);
                printf("%d ", trace.size());
                for(int k = 0; k < trace.size(); ++k)
                    printf("%d ", trace[k]);
                puts("");
            }
        }
    }
    return 0;
}
