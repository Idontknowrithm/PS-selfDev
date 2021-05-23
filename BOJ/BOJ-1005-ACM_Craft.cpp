#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

int T, N, K, W, cache[1005], duration[1005], prev[1005];
std::vector<int> graph[1005];

void ACMcraft(int start){
    std::queue<int> bfs;
    bfs.push(start);
    cache[start] = duration[start];
    while(!bfs.empty()){
        int tmp = bfs.front();
        bfs.pop();
        for(int i = 0; i < graph[tmp].size(); ++i){
            if(cache[graph[tmp][i]] < cache[tmp] + duration[graph[tmp][i]]){
                cache[graph[tmp][i]] = cache[tmp] + duration[graph[tmp][i]];
                bfs.push(graph[tmp][i]);
            }
        }
    }
}

int main(){
    int ia, ib;
    for(scanf("%d", &T); T > 0; --T){
        memset(cache, 0, sizeof(cache));
        memset(prev, 0, sizeof(prev));
        scanf("%d %d", &N, &K);
        for(int i = 1; i <= N; ++i){
            scanf("%d", &duration[i]);
        }
        for(int i = 0; i < K; ++i){
            scanf("%d %d", &ia, &ib);
            graph[ia].push_back(ib);
            ++prev[ib];
        }
        scanf("%d", &W);
        for(int i = 1; i <= N; ++i)
            if(!prev[i]) ACMcraft(i);
        printf("%d\n", cache[W]);
        for(int i = 0; i < 1005; ++i)
            graph[i].clear();
    }
    return 0;
}
