#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

std::vector<int> node[100010];
int N, parents[100010], visited[100010];

void findParents(){
	std::queue<int> bfs;
	bfs.push(1);
	while(!bfs.empty()){
		for(int i = 0; i < node[bfs.front()].size(); ++i)
			if(!visited[node[bfs.front()][i]]){
				visited[node[bfs.front()][i]] = 1;
				parents[node[bfs.front()][i]] = bfs.front();
				bfs.push(node[bfs.front()][i]);
			}
		bfs.pop();
	}
}

int main () {
	int R, C;
	scanf("%d", &N);
	for(int i = 0; i < N - 1; ++i){
		scanf("%d %d", &R, &C);
		node[R].push_back(C);
		node[C].push_back(R);
	}
	findParents();
	for(int i = 2; i <= N; ++i)
		printf("%d\n", parents[i]);
	
	return 0;
}
