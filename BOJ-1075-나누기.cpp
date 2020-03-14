#include<iostream>

int main () {
	int N, F, ans = 0;
	scanf("%d\n%d", &N, &F);
	N /= 100; N *= 100;
	while(N % F != 0){
		++ans;
		++N;
	}
	if(ans < 10)
		printf("0%d", ans);
	else 
		printf("%d", ans);
	return 0;
}
