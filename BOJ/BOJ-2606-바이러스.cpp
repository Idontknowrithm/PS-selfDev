#include<iostream>
#include<queue>

int graph[101][101], visited[101];

void bfs(int start, int vertex){
	std::queue<int> que;
	que.push(start);
	while(!que.empty()){
		for(int i = 1; i <= vertex; ++i){
			if(!visited[i] && graph[que.front()][i]){
				visited[i] = 1;
				que.push(i);
			}
		}
		que.pop();
	}
}

int main () {
	int vertex, edge, ans = 0, inp[2];
	scanf("%d\n%d", &vertex, &edge);
	for(int i = 0; i < edge; ++i){
		scanf("%d %d", &inp[0], &inp[1]);
		graph[inp[0]][inp[1]] = 1;
		graph[inp[1]][inp[0]] = 1;
	}
	bfs(1, vertex);
	for(int i = 1; i <= vertex; ++i)
		ans += visited[i];
	printf("%d", ans - 1);
	return 0;
}
