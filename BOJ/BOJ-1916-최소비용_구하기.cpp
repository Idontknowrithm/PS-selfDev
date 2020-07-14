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

        for(int i = 0; i < graph[curV].size(); ++i){
            if(curD <= dist[curV] && dist[graph[curV][i].first] > curD + graph[curV][i].second){
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
