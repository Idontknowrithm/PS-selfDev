#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 2147483647

typedef struct{
	int curI, dist, pastI;
}tuple;
struct cmp{
	bool operator()(const tuple &a, const tuple &b){
		return a.dist > b.dist;
	}
};

std::priority_queue<tuple, std::vector<tuple>, cmp> que;
std::vector<std::pair<int, int>> graph[20001];
int V, E, start, vtx1, vtx2, weight, distance[20001];

void Dijkstra(int start){
	int curV, D;
	for(int i = 0; i <= V; ++i)
		distance[i] = INF;
	distance[start] = 0;
	for(int i = 1; i <= V; ++i)
		que.push({i, distance[i], -1});
	
	while(que.top().dist != INF){
		curV = que.top().curI;
		D = que.top().dist;
		que.pop();
		for(int i = 0; i < graph[curV].size(); ++i){
			if(D <= distance[curV] && distance[graph[curV][i].first] > D + graph[curV][i].second){
				distance[graph[curV][i].first] = D + graph[curV][i].second;
				que.push({graph[curV][i].first, D + graph[curV][i].second, curV});
			}
		}
	}
}

int main (){
	scanf("%d %d\n%d", &V, &E, &start);
	for(int i = 0; i < E; ++i){
		scanf("%d %d %d", &vtx1, &vtx2, &weight);
		graph[vtx1].push_back({vtx2, weight});
	}
	Dijkstra(start);

	for(int i = 1; i <= V; ++i){
		if(distance[i] == INF)
			printf("INF\n");
		else 
			printf("%d\n", distance[i]);
	}
	
	return 0;
}
