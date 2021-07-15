// 우선순위 큐에 최근에 갱신된 근처 정점들을 마구 넣다보면
// 이미 최소 비용으로 갱신된 dist 배열을 다시 방문해서 의미없는 탐색을 할 수 있음
// for문에 들어가서 if함수를 호출만 해도 많은 비용이 들 수 있으므로
// 이러한 케이스는 for문으로 들어가기 전에 continue 처리를 해줘야 함

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define pp std::pair<int, int>
#define INF 2147483647

struct compare{
    bool operator () (const pp &a, const pp &b){
        return a.second > b.second;
    }
};
int N, M, start, dest, w, dist[1005];
std::vector<pp> graph[1005];



int dijkstra(){
    std::priority_queue<pp, std::vector<pp>, compare> que;
    int curV, curD;
    for(int i = 0; i <= N; ++i)
        dist[i] = INF;
    dist[start] = 0;
    for(int i = 1; i <= N; ++i)
        que.push({i, dist[i]});
    
    while(que.top().second != INF){
        curV = que.top().first;
        curD = que.top().second;
        que.pop();
        
        if(curD > dist[curV]) continue; // 이 부분이 관건이었음
        
        for(int i = 0; i < graph[curV].size(); ++i){
            if(dist[graph[curV][i].first] > curD + graph[curV][i].second){ // <-- 여기 있었음
                dist[graph[curV][i].first] = curD + graph[curV][i].second;
                que.push({graph[curV][i].first, curD + graph[curV][i].second});
            }
        }
    }
    return dist[dest];
}

int main () {
    int inpS, inpD;
    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &inpS, &inpD, &w);
        graph[inpS].push_back({inpD, w});
    }

    scanf("%d %d", &start, &dest);
    
    printf("%d", dijkstra());

    return 0;
}
