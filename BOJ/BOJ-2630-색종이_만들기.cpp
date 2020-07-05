#include<iostream>

int N, ansB, ansW, paper[150][150];

void cutting(int startR, int startC, int size){
	int color = 0;
	for(int i = startR; i < startR + size; ++i)
	for(int u = startC; u < startC + size; ++u)
		color += paper[i][u];
	if(color == size * size){
		++ansB;
		return;
	}
	else if(!color){
		++ansW;
		return;
	}
	cutting(startR, startC, size / 2);
	cutting(startR, startC + size / 2, size / 2);
	cutting(startR + size / 2, startC, size / 2);
	cutting(startR + size / 2, startC + size / 2, size / 2);
}

int main () {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < N; ++u)
		scanf("%d", &paper[i][u]);
	cutting(0, 0, N);
	printf("%d\n%d", ansW, ansB);
	return 0;
}
