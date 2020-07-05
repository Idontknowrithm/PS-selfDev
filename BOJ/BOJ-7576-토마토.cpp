// 처음에 토마토 데이터 저장공간과 날짜 계산을 따로 기록하고 있었으나 시간초과
// 이런 과정에서 토마토가 있는 공간(1)도 탐색 목표에 넣다 보니 시간초과 나는 듯

#include<iostream>
#include<queue>
#include<vector>

typedef struct{
	int row, col;
}location;

std::queue<location> bfs;
int M, N, tomato[1000][1000]; // N : row, M : col;

void riping(){
	int refR, refC;

	while(!bfs.empty()){
		refR = bfs.front().row;
		refC = bfs.front().col;

		if(refR < N - 1){
			if(tomato[refR + 1][refC] == 0){
				tomato[refR + 1][refC] = tomato[refR][refC] + 1;
				bfs.push({refR + 1, refC});
			}
		}
		if(refR > 0){
			if(tomato[refR - 1][refC] == 0){
				tomato[refR - 1][refC] = tomato[refR][refC] + 1;
				bfs.push({refR - 1, refC});
			}
		}
		if(refC < M - 1){
			if(tomato[refR][refC + 1] == 0){
				tomato[refR][refC + 1] = tomato[refR][refC] + 1;
				bfs.push({refR, refC + 1});
			}
		}
		if(refC > 0){
			if(tomato[refR][refC - 1] == 0){
				tomato[refR][refC - 1] = tomato[refR][refC] + 1;
				bfs.push({refR, refC - 1});
			}
		}
		bfs.pop();
	}
}

int main () {
	bool possible = true; int ans;
	std::vector<location> ripened;

	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < M; ++u){
		scanf("%d", &tomato[i][u]);
		if(tomato[i][u] == 1)
			bfs.push({i, u});
	}
	riping();
	
	ans = 0;

	for(int i = 0; i < N; ++i)
	for(int u = 0; u < M; ++u){
		ans = (tomato[i][u] > ans) ? tomato[i][u] : ans;
		possible = (tomato[i][u] == 0) ? false : possible;
	}
	printf("%d", (possible) ? ans - 1 : -1);
	return 0;
}
