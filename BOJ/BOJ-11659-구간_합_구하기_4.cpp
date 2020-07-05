#include<iostream>

int main () {
	int N, M, start, end, arr[100010], sum[100010] = {0,};

	scanf("%d %d", &N, &M);
	scanf("%d", &arr[1]);
	sum[1] = arr[1];

	for(int i = 2; i < N + 1; ++i){
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	for(int i = 0; i < M; ++i){
		scanf("%d %d", &start, &end);
		printf("%d\n", sum[end] - sum[start - 1]);
	}

	return 0;
}
