#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>
#define INF 500000000

typedef struct{
    int v, weight;
}data;

bool operator <(data a, data b){
    return (a.weight == b.weight) ? a.v > b.v : a.weight > b.weight;
}

int N, M, start, end, len[1005];
std::vector<pp> graph[1005];
std::vector<int> path[1005];

void path_finder(){
    std::priority_queue<data> dijk;
    for(int i = 1; i <= N; ++i){
        dijk.push({i, INF});
        len[i] = INF;
    }
    len[start] = 0;
    dijk.push({start, 0});
    path[start].push_back(start);
    
    while(!dijk.empty()){
        data tmp = dijk.top();
        dijk.pop();
        for(int i = 0; i < graph[tmp.v].size(); ++i){
            if(tmp.weight + graph[tmp.v][i].second < len[graph[tmp.v][i].first]){
                len[graph[tmp.v][i].first] = tmp.weight + graph[tmp.v][i].second;
                dijk.push({graph[tmp.v][i].first, tmp.weight + graph[tmp.v][i].second});
                path[graph[tmp.v][i].first] = path[tmp.v];
                path[graph[tmp.v][i].first].push_back(graph[tmp.v][i].first);
            }
        }
    }
}

int main() {
    int a, b, w;
    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back({b, w});
    }
    scanf("%d %d", &start, &end);
    
    path_finder();

    printf("%d\n%d\n", len[end], path[end].size());
    for(int i = 0; i < path[end].size(); ++i)
        printf("%d ", path[end][i]);
    return 0;
}
