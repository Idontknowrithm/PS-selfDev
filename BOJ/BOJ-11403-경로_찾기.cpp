#include<iostream>
#include<queue>

int N, graph[200][200];

int find(int start, int dest){
	std::queue<int> bfs;
	int visited[200] = {0,};
	bfs.push(start);
	while(!bfs.empty()){
		for(int i = 0; i < N; ++i){
			if(graph[bfs.front()][i] && !visited[i]){
				visited[i] = 1;
				bfs.push(i);
			}
		}
		bfs.pop();
	}
	if(visited[dest])
		return 1;
	else 
		return 0;
}

int main () {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < N; ++u)
		scanf("%d", &graph[i][u]);
	for(int i = 0; i < N; ++i){
		for(int u = 0; u < N; ++u)
			printf("%d ", find(i, u));
		printf("\n");
	}
	return 0;
}
