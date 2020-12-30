// 3번 시도
// 문제 제대로 안봐서 무방향 이라는 조건과 답이 없을 때의 조건 놓침
// int MAX에 가까운 수를 다룰 때에는 overflow 관련 오류 조심
// 여기에서 MAX + MAX + MAX 가 가능한 부분을 처리 못해줌

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>
#define M 400000000

struct compare{
    bool operator()(pp a, pp b){
        return a.first > b.first;
    }
};

int V, E, K, startD[20005], oneD[20005], twoD[20005];
std::vector<pp> graph[20005];
std::priority_queue<pp, std::vector<pp>, compare> pqueue;
// WARNING: 1 start, not ZERO

void dijkstra(int start, int *arr){
    for(int i = 0; i < 20005; ++i)
        arr[i] = M;
    arr[start] = 0;
    for(int i = 0; i < V; ++i)
        pqueue.push({arr[i + 1], i + 1});
    
    while(pqueue.top().first != M){
        std::pair<int, int> temp = pqueue.top();
        pqueue.pop();

        for(int i = 0; i < graph[temp.second].size(); ++i){
            if(arr[graph[temp.second][i].second] > arr[temp.second] + graph[temp.second][i].first){
                arr[graph[temp.second][i].second] = arr[temp.second] + graph[temp.second][i].first;
                pqueue.push({arr[graph[temp.second][i].second], graph[temp.second][i].second});
            }
        }
    }

    while(!pqueue.empty())
        pqueue.pop();
}

int main(){
    int u, v, w, first, second;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    scanf("%d %d", &first, &second);

    dijkstra(1, startD); dijkstra(first, oneD); dijkstra(second, twoD);

    int temp, min = 399999999;
    temp = startD[first] + oneD[second] + twoD[V];
    min = (temp < min) ? temp : min;
    temp = startD[second] + twoD[first] + oneD[V];
    min = (temp < min) ? temp : min;

    if(min != 399999999)
        printf("%d", min); 
    else 
        printf("-1");
    return 0;
}
