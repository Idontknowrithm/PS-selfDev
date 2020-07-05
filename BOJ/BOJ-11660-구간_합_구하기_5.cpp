#include<iostream>

int arr[1050][1050] = {0,};

int main () {
	int N, M, input, ans, r1, c1, r2, c2;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i)
	for(int u = 1; u <= N; ++u){
		scanf("%d", &input);
		arr[i][u] = arr[i][u - 1] + input;
	}
	for(int i = 0; i < M; ++i){
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		ans = 0;
		for(int u = r1; u <= r2; ++u){
			ans += arr[u][c2] - arr[u][c1 - 1];		
		}
		printf("%d\n", ans);
	}
	return 0;
}
