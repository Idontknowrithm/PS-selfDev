#include<iostream>
int main () {
	int T, big, data[2][50], ans[50]; // 0 : weight, 1 : height
	scanf("%d", &T);
	for(int i = 0; i < T; ++i)
		scanf("%d %d", &data[0][i], &data[1][i]);
		
	for(int i = 0; i < T; ++i){
		big = 0;
		for(int j = 0; j < T; ++j){
			if(i == j) continue;
			big += (data[0][i] < data[0][j] && data[1][i] < data[1][j]) ? 1 : 0;
		}
		ans[i] = big + 1;
	}
	for(int i = 0; i < T; ++i)
		printf("%d ", ans[i]);
	return 0;
}
