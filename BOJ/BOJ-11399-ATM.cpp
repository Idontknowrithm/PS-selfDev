#include<iostream>
#include<algorithm>

int main () {
	int N, temp, ans = 0, P[1000];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &P[i]);
	std::sort(P, P + N);
	for(int i = 0; i < N; ++i){
		temp = 0;
		for(int j = 0; j < i + 1; ++j)
			temp += P[j];
		ans += temp;
	}
	printf("%d", ans);
	return 0;
}
