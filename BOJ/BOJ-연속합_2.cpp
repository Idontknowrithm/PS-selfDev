// 정답의 범위를 정확히 파악하자!
// - 정답의 범위가 음수일 수 있는 데도 불구하고 
//   최소 정답 값을 0으로 지정해서 틀림
// 내가 설정한 자료구조의 코너 케이스를 신중히 고려하지 않았

#include<iostream>
#include<algorithm>
#define MAX 100005

const int ep = -2147000000;
int N, ans = ep, seq[MAX], left_cache[MAX], right_cache[MAX];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &seq[i]);
		left_cache[i] = std::max(left_cache[i - 1] + seq[i], seq[i]);
	}
	for(int i = N; i > 0; --i)
		right_cache[i] = std::max(right_cache[i + 1] + seq[i], seq[i]);
	
	for(int i = 1; i <= N; ++i)
		ans = std::max(ans, left_cache[i]);
	
	for(int i = 2; i < N; ++i)
		ans = std::max(ans, left_cache[i - 1] + right_cache[i + 1]);
	
	printf("%d", ans);
	return 0;
}
