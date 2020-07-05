#include<iostream>
#include<algorithm>

typedef struct {
	int r, c, s;
}round;

int N, M, arr[50][50], tempArr[50][50];

void rounding(int r, int c, int s){
	int temp;
	for(int i = 1; i <= s; ++i){
		temp = tempArr[r - i][c - i];
		for(int u = 0; u < i * 2; ++u)
			tempArr[r + u - i][c - i] = tempArr[r + u - i + 1][c - i];
		for(int u = 0; u < i * 2; ++u)
			tempArr[r + i][c + u - i] = tempArr[r + i][c + u - i + 1];
		for(int u = 0; u < i * 2; ++u)
			tempArr[r - u + i][c + i] = tempArr[r - u + i - 1][c + i];
		for(int u = 0; u < i * 2 - 1; ++u)
			tempArr[r - i][c + i - u] = tempArr[r - i][c + i - u - 1];
		tempArr[r - i][c - i + 1] = temp;
	}
}

int main () {
	int K, tempM, ans = 2147483647, permTable[6] = {0, 1, 2, 3, 4, 5};
	round data[6];
	
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < M; ++u)
		scanf("%d", &arr[i][u]);
	for(int i = 0; i < K; ++i)
		scanf("%d %d %d", &data[i].r, &data[i].c, &data[i].s);
	
	do {
		for(int i = 0; i < N; ++i)
		for(int u = 0; u < M; ++u)
			tempArr[i][u] = arr[i][u];
		for(int i = 0; i < K; ++i)
			rounding(data[permTable[i]].r - 1, data[permTable[i]].c - 1, data[permTable[i]].s);
		for(int i = 0; i < N; ++i){
			tempM = 0;
			for(int u = 0; u < M; ++u)
				tempM += tempArr[i][u];
			ans = (tempM < ans) ? tempM : ans;
		}
	}while(std::next_permutation(permTable, permTable + K));
	printf("%d", ans);
}
