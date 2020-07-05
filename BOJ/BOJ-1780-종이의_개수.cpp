#include<iostream>

int N, ansP, ansZ, ansN, paper[2500][2500];

void cutting(int startR, int startC, int size){
	int pos = 0, neg = 0, zer = 0;
	for(int i = startR; i < startR + size; ++i)
	for(int u = startC; u < startC + size; ++u){
		pos += (paper[i][u] ==  1) ? 1 : 0;
		zer += (paper[i][u] ==  0) ? 1 : 0;
		neg += (paper[i][u] == -1) ? 1 : 0;
	}
	if(pos == size * size){
		++ansP;
		return;
	}
	else if(zer == size * size){
		++ansZ;
		return;
	}
	else if(neg == size * size){
		++ansN;
		return;
	}
	cutting(startR, startC, size / 3);
	cutting(startR, startC + size / 3, size / 3);
	cutting(startR, startC + size / 3 * 2, size / 3);
	cutting(startR + size / 3, startC, size / 3);
	cutting(startR + size / 3, startC + size / 3, size / 3);
	cutting(startR + size / 3, startC + size / 3 * 2, size / 3);
	cutting(startR + size / 3 * 2, startC, size / 3);
	cutting(startR + size / 3 * 2, startC + size / 3, size / 3);
	cutting(startR + size / 3 * 2, startC + size / 3 * 2, size / 3);
}

int main () {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	for(int u = 0; u < N; ++u)
		scanf("%d", &paper[i][u]);
	cutting(0, 0, N);
	printf("%d\n%d\n%d", ansN, ansZ, ansP);
	return 0;
}
