#include<iostream>

int graph[1001][1001];
int visited[1001];

void dfs(int start, int vertex){
	for(int i = 1; i <= vertex; ++i){
		if(graph[start][i] && !visited[i]){
			visited[i] = 1;
			dfs(i, vertex);
		}
	}
}
int connectedComponent(int vertex){
	int ans = 0;
	for(int i = 1; i <= vertex; ++i){
		if(visited[i] == 1) continue;
		visited[i] = 1;
		dfs(i, vertex);
		++ans;
	}
	return ans;
}

int main () {
	int vertex, edge, inp[2];
	scanf("%d %d", &vertex, &edge);
	for(int i = 0; i < edge; ++i){
		scanf("%d %d", &inp[0], &inp[1]);
		++graph[inp[0]][inp[1]];
		++graph[inp[1]][inp[0]];
	}
	printf("%d", connectedComponent(vertex));
	return 0;
}
