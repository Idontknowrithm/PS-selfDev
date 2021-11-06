#include<iostream>
#include<cstring>
#include<vector>

int N, M, graph[105][105], floyd[105][105], cache[105][105];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = c;
    }
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u)
        floyd[i][u] = (i == u) ? 0 : 1000000005;

    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u){
            if(i == u) continue;
            for(int k = 1; k <= N; ++k){
                if(i == k || k == u || !graph[i][k] || !graph[k][u]) continue;
                if(!graph[i][u] || graph[i][k] + graph[k][u] < graph[i][u]){
                    graph[i][u] = graph[i][k] + graph[k][u];
                    cache[i][u] = k;
                    cache[k][u] = u;
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u)
            printf("%d ", graph[i][u]);
        puts("");
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u){
            if(!cache[i][u]){
                printf("0\n");
            }
            else{
                std::vector<int> trace;
                int tmp = cache[i][u];
                while(tmp != u){
                    trace.push_back(tmp);
                    tmp = cache[tmp][u];
                }
                trace.push_back(tmp);
                printf("%d ", trace.size());
                for(int k = 0; k < trace.size(); ++k)
                    printf("%d ", trace[i]);
                puts("");
            }
        }
    }
    return 0;
}
