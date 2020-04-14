// BFS로 접근하다 런타임 맞은 케이스
// 분산되어있고 벡터 링크드리스트로 구현된 그래프라면 DFS 생각해보자

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int N, M, visited[10010] = {0,}, ans[10010] = {0,};
std::vector<int> graph[10010], realAns;

int traversal(int start){
	std::queue<int> bfs;
	int f;
	bfs.push(start);
	visited[start] = 1;
	while(!bfs.empty()){
		f = bfs.front();
		bfs.pop();
		if(!graph[f].empty())
			for(int i = 0; i < graph[f].size(); ++i){
				if(!(visited[graph[f][i]])){
					visited[graph[f][i]] = 1;
					bfs.push(graph[f][i]);
				}
			}
	}
}

int main () {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int inp1, inp2, temp;
	std::cin >> N >> M;
	for(int i = 0; i < M; ++i){
		std::cin >> inp1 >> inp2;
		graph[inp2].push_back(inp1);
	}
	for(int i = 1; i <= N; ++i){
		temp = 0;
		for(int u = 0; u <= N; ++u)
			visited[u] = 0;
		traversal(i);
		for(int u = 1; u <= N; ++u)
			temp += visited[u];
		ans[i] = temp;
	}
	temp = 0;
	for(int i = 1; i <= N; ++i)
		temp = (temp < ans[i]) ? ans[i] : temp;
	for(int i = 1; i <= N; ++i)
		if(ans[i] == temp)
			realAns.push_back(i);
	std::sort(realAns.begin(), realAns.end());

	for(int i = 0; i < realAns.size(); ++i)
		std::cout << realAns[i] << " ";

	return 0;
}
