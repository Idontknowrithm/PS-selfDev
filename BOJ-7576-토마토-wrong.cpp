// timeout

#include<iostream>
#include<queue>
#include<vector>

typedef struct{
	int row, col;
}location;

std::queue<location> bfs;
int M, N, tomato[1000][1000], day[1000][1000]; // N : row, M : col;

void riping(int r, int c){
	int refR, refC;
	bfs.push({r, c});
	day[r][c] = 0;

	while(!bfs.empty()){
		refR = bfs.front().row;
		refC = bfs.front().col;

		if(refR < N - 1){
			if(tomato[refR + 1][refC] != -1 && day[refR + 1][refC] > day[refR][refC] + 1){
				tomato[refR + 1][refC] = 1;
				day[refR + 1][refC] = day[refR][refC] + 1;
				bfs.push({refR + 1, refC});
			}
		}
		if(refR > 0){
			if(tomato[refR - 1][refC] != -1 && day[refR - 1][refC] > day[refR][refC] + 1){
				tomato[refR - 1][refC] = 1;
				day[refR - 1][refC] = day[refR][refC] + 1;
				bfs.push({refR - 1, refC});
			}
		}
		if(refC < M - 1){
			if(tomato[refR][refC + 1] != -1 && day[refR][refC + 1] > day[refR][refC] + 1){
				tomato[refR][refC + 1] = 1;
				day[refR][refC + 1] = day[refR][refC] + 1;
				bfs.push({refR, refC + 1});
			}
		}
		if(refC > 0){
			if(tomato[refR][refC - 1] != -1 && day[refR][refC - 1] > day[refR][refC] + 1){
				tomato[refR][refC - 1] = 1;
				day[refR][refC - 1] = day[refR][refC] + 1;
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
		day[i][u] = 1000000;
		if(tomato[i][u] == 1)
			ripened.push_back({i, u});
	}
	for(int i = 0; i < ripened.size(); ++i)
		riping(ripened[i].row, ripened[i].col);
	
	ans = 0;

	for(int i = 0; i < N; ++i)
	for(int u = 0; u < M; ++u){
		ans = (day[i][u] != 1000000 && day[i][u] > ans) ? day[i][u] : ans;
		possible = (tomato[i][u] == 0) ? false : possible;
	}
	printf("%d", (possible) ? ans : -1);
	return 0;
}
