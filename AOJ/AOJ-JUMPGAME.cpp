#include<iostream>

int N, field[100][100], cache[100][100];

int jump(int y, int x){
	if(y >= N || x >= N)
		return 0;
	else if(y ==  N - 1 && x == N - 1)
		return 1;
	
	int& ref = cache[y][x];
	if(ref != -1)
		return ref;
	return ref = jump(y + field[y][x], x) || jump(y, x + field[y][x]);
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		for(int u = 0; u < N; ++u){
			scanf("%d", &field[i][u]);
			cache[i][u] = -1;
		}
		if(jump(0, 0))
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
