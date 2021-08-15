#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define pp std::pair<int, int>

typedef struct{
	int curI, dist, pastI;
}tuple;
typedef struct{
    int next, &val;
}node;
struct cmp{
	bool operator()(const tuple &a, const tuple &b){
		return a.dist > b.dist;
	}
};

const int INF = 500005;
int N, M, S, D, graph[505][505], dist[505], trace[505][505], trace_size[505];
std::priority_queue<tuple, std::vector<tuple>, cmp> que;
std::vector<node> vec_graph[505];

void trace_cpy(int dest, int src){
    for(int i = 0; i < trace_size[src]; ++i)
        trace[dest][i] = trace[src][i];
    trace_size[dest] = trace_size[src];
}

void Dijkstra(int start){
	int curV, D, pastV;
	for(int i = 0; i < N; ++i)
		dist[i] = INF;
	dist[start] = 0;
	for(int i = 0; i < N; ++i)
		que.push({i, dist[i], -1});
	
	while(que.top().dist != INF){
		curV = que.top().curI;
		pastV = que.top().pastI;
        D = que.top().dist;
		que.pop();
        if(D > dist[curV]) continue;
        for(int i = 0; i < vec_graph[curV].size(); ++i){
            int new_edge = D + vec_graph[curV][i].val;
            if(dist[i] > new_edge){
                dist[i] = new_edge;
                que.push({i, new_edge, curV});
                if(pastV == -1)
                    trace[i][trace_size[i]++] = curV;
                else{
                    trace_cpy(i, curV);
                    trace[i][trace_size[i]++] = curV;
                }
            }
        }
	}
}

int main() {
    scanf("%d %d", &N, &M);
    while(N || M){
        for(int i = 0; i < 505; ++i)
        for(int u = 0; u < 505; ++u)
            graph[i][u] = INF;
        scanf("%d %d", &S, &D);
        for(int i = 0; i < M; ++i){
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            graph[u][v] = p;
            vec_graph[u].push_back({v, graph[u][v]});
        }
        int min = INF;
        Dijkstra(S);
        min = dist[D];
        while(min == dist[D]){
            for(int i = 0; i < trace_size[D] - 1; ++i)
                graph[trace[D][i]][trace[D][i + 1]] = INF;
            graph[trace[D][trace_size[D] - 1]][D] = INF;
            memset(trace_size, 0, sizeof(trace_size));
            Dijkstra(S);
        }
        printf("%d\n", (dist[D] >= INF) ? -1 : dist[D]);

        scanf("%d %d", &N, &M);
        for(int i = 0; i < 505; ++i)
            vec_graph[i].clear();
    }
}
