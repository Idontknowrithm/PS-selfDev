#include<iostream>
#include<queue>

int catcha, subin, brother, visited[100001], dep[100001];

void bfs(int start){
	std::queue<int> que;
	que.push(start);
	visited[start] = 1;
	while(!que.empty() && !catcha){
		if(que.front() - 1 >= 0 && que.front() - 1 < 100001)
			if(!visited[que.front() - 1]){
				que.push(que.front() - 1);
				visited[que.front() - 1] = 1;
				dep[que.front() - 1] = dep[que.front()] + 1;
				catcha += (que.front() - 1 == brother) ? 1 : 0;
			}
		if(que.front() + 1 >= 0 && que.front() + 1 < 100001)
			if(!visited[que.front() + 1]){
				que.push(que.front() + 1);
				visited[que.front() + 1] = 1;
				dep[que.front() + 1] = dep[que.front()] + 1;
				catcha += (que.front() + 1 == brother) ? 1 : 0;
			}
		if(que.front() * 2 >= 0 && que.front() * 2 < 100001)
			if(!visited[que.front() * 2]){
				que.push(que.front() * 2);
				visited[que.front() * 2] = 1;
				dep[que.front() * 2] = dep[que.front()] + 1;
				catcha += (que.front() * 2 == brother) ? 1 : 0;
			}
		que.pop();
	}
}

int main () {
	scanf("%d %d", &subin, &brother);
	if(subin >= brother){
		printf("%d", subin - brother);
		return 0;
	}
	bfs(subin);
	printf("%d", dep[brother]);
}
