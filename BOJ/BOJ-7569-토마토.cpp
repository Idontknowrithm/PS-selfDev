// BFS문제를 DFS로 접근하다 시간초과
// 그래프 탐색 문제면 어떻게든 탐색하려고 하기 보다 먼저
// 그래프 탐색 방식 부터 생각하고 시작하기

#include<iostream>
#include<vector>
#include<queue>

typedef struct{
	int height, row, col;
}location;

int N, M, H;	  std::queue<location> bfs;
int box[100][100][100], day[100][100][100]; // N : row, M : col

void riping(int h, int n, int m){
	int refH, refN, refM;
	bfs.push({h, n, m});
	day[h][n][m] = 0;
	while(!bfs.empty()){
		refH = bfs.front().height;
		refN = bfs.front().row;
		refM = bfs.front().col;

		if(refH < H - 1){
			if(box[refH + 1][refN][refM] != -1 && day[refH + 1][refN][refM] > day[refH][refN][refM] + 1){
				box[refH + 1][refN][refM] = 1;
				day[refH + 1][refN][refM] = day[refH][refN][refM] + 1;
				bfs.push({refH + 1, refN, refM});
			}
		}
		if(refH > 0){
			if(box[refH - 1][refN][refM] != -1 && day[refH - 1][refN][refM] > day[refH][refN][refM] + 1){
				box[refH - 1][refN][refM] = 1;
				day[refH - 1][refN][refM] = day[refH][refN][refM] + 1;
				bfs.push({refH - 1, refN, refM});
			}
		}
		if(refN < N - 1){
			if(box[refH][refN + 1][refM] != -1 && day[refH][refN + 1][refM] > day[refH][refN][refM] + 1){
				box[refH][refN + 1][refM] = 1;
				day[refH][refN + 1][refM] = day[refH][refN][refM] + 1;
				bfs.push({refH, refN + 1, refM});
			}
		}
		if(refN > 0){
			if(box[refH][refN - 1][refM] != -1 && day[refH][refN - 1][refM] > day[refH][refN][refM] + 1){
				box[refH][refN - 1][refM] = 1;
				day[refH][refN - 1][refM] = day[refH][refN][refM] + 1;
				bfs.push({refH, refN - 1, refM});
			}
		}
		if(refM < M - 1){
			if(box[refH][refN][refM + 1] != -1 && day[refH][refN][refM + 1] > day[refH][refN][refM] + 1){
				box[refH][refN][refM + 1] = 1;
				day[refH][refN][refM + 1] = day[refH][refN][refM] + 1;
				bfs.push({refH, refN, refM + 1});
			}
		}
		if(refM > 0){
			if(box[refH][refN][refM - 1] != -1 && day[refH][refN][refM - 1] > day[refH][refN][refM] + 1){
				box[refH][refN][refM - 1] = 1;
				day[refH][refN][refM - 1] = day[refH][refN][refM] + 1;
				bfs.push({refH, refN, refM - 1});
			}
		}
		bfs.pop();
	}
}

int main () {
	location temp; 	int ans = 0;
	std::vector<location> ripen;
	bool possible = true;
	
	scanf("%d %d %d", &M, &N, &H);
	for(int i = 0; i < H; ++i)
	for(int u = 0; u < N; ++u)
	for(int k = 0; k < M; ++k){
		scanf("%d", &box[i][u][k]);
		day[i][u][k] = 1000000;
		if(box[i][u][k] == 1)
			ripen.push_back({i, u, k});
	}
	for(int i = 0 ; i < ripen.size(); ++i)
		riping(ripen[i].height, ripen[i].row, ripen[i].col);
	for(int i = 0; i < H; ++i)
	for(int u = 0; u < N; ++u)
	for(int k = 0; k < M; ++k){
		ans = (day[i][u][k] != 1000000 && day[i][u][k] > ans) ? day[i][u][k] : ans;
		possible = (box[i][u][k] == 0) ? false : possible;
	}
	if(possible)
		printf("%d", ans);
	else 
		printf("-1");
	return 0;
}
