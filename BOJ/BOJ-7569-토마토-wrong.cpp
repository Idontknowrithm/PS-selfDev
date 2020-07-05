// timeout

#include<iostream>
#include<vector>

typedef struct{
	int height, row, col;
}location;

int N, M, H;
int box[100][100][100], day[100][100][100]; // N : row, M : col

void riping(int h, int n, int m, int time){
	if(h < 0 || h >= H || n < 0 || n >= N || m < 0 || m >= M)
		return;
	if(day[h][n][m] < time || box[h][n][m] == -1)
		return;
	box[h][n][m] = 1;
	day[h][n][m] = time;
	riping(h + 1, n, m, time + 1);
	riping(h - 1, n, m, time + 1);
	riping(h, n + 1, m, time + 1);
	riping(h, n, m + 1, time + 1);
	riping(h, n - 1, m, time + 1);
	riping(h, n, m - 1, time + 1);
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
		if(box[i][u][k] == 1){
			temp.height = i;
			temp.row = u;
			temp.col = k;
			ripen.push_back(temp);
		}
	}
	for(int i = 0 ; i < ripen.size(); ++i)
		riping(ripen[i].height, ripen[i].row, ripen[i].col, 0);
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
