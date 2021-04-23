// 정점, 간선 수 보고 플로이드일지, 다익일지 판단하기
// 플로이드 = N^3, 다익 = Elog(V)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pp std::pair<int, int>
#define INF 50000000
typedef struct{
    int v, weight;
}data;
bool operator<(data a, data b){
    return a.weight > b.weight;
}

int N, M, X, ans, path[1005], home_to_X[1005];
std::vector<pp> graph[1005];

void shortest(int start){
    std::priority_queue<data> dijk;

    for(int i = 1; i <= N; ++i){
        path[i] = INF;
        dijk.push({i, INF});
    }
    path[start] = 0;
    dijk.push({start, 0});
    while(!dijk.empty()){
        data tmp = dijk.top();
        dijk.pop();
        for(int i = 0; i < graph[tmp.v].size(); ++i){
            int next_v = graph[tmp.v][i].first, next_w = graph[tmp.v][i].second;
            if(path[tmp.v] + next_w < path[next_v]){
                path[next_v] = path[tmp.v] + next_w;
                dijk.push({next_v, path[tmp.v] + next_w});
            }
        }
    }
}

int main() {
    int a, b, t;
    scanf("%d %d %d", &N, &M, &X);
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &a, &b, &t);
        graph[a].push_back({b, t});
    }
    for(int i = 1; i <= N; ++i){ // home to X
        if(i == X) continue;
        shortest(i);
        home_to_X[i] = path[X];
    }
    shortest(X);
    for(int i = 1; i <= N; ++i){
        ans = (ans < home_to_X[i] + path[i]) ? home_to_X[i] + path[i] : ans;
    }
    printf("%d", ans);
    return 0;
}
