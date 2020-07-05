#include<iostream>

int field[500][500];

int main () {
	int N, M, B, height, ans = 2147483647, min = 2147483647, max = -1;
	scanf("%d %d %d", &N, &M, &B);
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < M; ++j){
		scanf("%d", &field[i][j]);
		min = (min > field[i][j]) ? field[i][j] : min;
		max = (max < field[i][j]) ? field[i][j] : max;
	}
	for(int i = max; i >= min; --i){
		int tempI = B, tempA = 0;
		for(int j = 0; j < N; ++j){
			for(int k = 0; k < M; ++k){
				if(i < field[j][k]){
					tempA += (field[j][k] - i) * 2;
					tempI += field[j][k] - i;
				}
				else if(i > field[j][k]){
					tempA += i - field[j][k];
					tempI -= i - field[j][k];
				}
			}
		}
		if(tempI >= 0 && ans > tempA){
			ans = tempA;
			height = i;
		}
	}
	printf("%d %d", ans, height);
	return 0;
}
