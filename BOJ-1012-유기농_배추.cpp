#include<iostream>

int N, M, field[50][50], visited[50][50];

void search(int row, int col){
	if(row < 0 || row >= N || col < 0 || col >= M || visited[row][col])
		return;
	if(!field[row][col]){
		visited[row][col] = 1;
		return;
	}
	visited[row][col] = 1;
	search(row + 1, col);
	search(row, col + 1);
	search(row - 1, col);
	search(row, col - 1);
}

int main () {
	int T, row, col, worm, cabbage, minWorm;
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 50; ++i)
		for(int u = 0; u < 50; ++u)
			field[i][u] = visited[i][u] = 0;

		scanf("%d %d %d", &N, &M, &cabbage);
		for(int i = 0; i < cabbage; ++i){
			scanf("%d %d", &row, &col);
			field[row][col] = 1;
		}
		minWorm = 0;
		for(int i = 0; i < N; ++i)
		for(int u = 0; u < M; ++u)
			if(!visited[i][u] && field[i][u]){
				search(i, u);
				++minWorm;
			}
		printf("%d\n", minWorm);
	}
	return 0;
}
