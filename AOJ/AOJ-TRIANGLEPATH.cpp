#include<iostream>
#include<algorithm>

int len, triangle[100][100], cache[100][100];

int pathSum(int y, int x){
	if(y == len - 1)
		return triangle[y][x];
	int& ref = cache[y][x];
	if(ref != -1)
		return ref;
	return ref = triangle[y][x] + std::max(pathSum(y + 1, x), pathSum(y + 1, x + 1));
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &len);
		for(int i = 0; i < len; ++i)
		for(int u = 0; u <= i; ++u){
			scanf("%d", &triangle[i][u]);
			cache[i][u] = -1;
		}
		printf("%d\n", pathSum(0, 0));
	}
	return 0;
}
