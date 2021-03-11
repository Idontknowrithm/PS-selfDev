// 일단 N - 3 에 3을 더한다고 경우의 수가 추가되는 것이 아니네..

#include<iostream>
#include<algorithm>
#define INF 2147483647

int T, N, cache[100005];

int solve(int N, int prev){
    if(N == 0) return 0;
    
	int &ret = cache[N];
	if(ret) return ret;
	
	ret = INF;
	
	if(prev != 1)
		ret = std::min(ret, (solve(N - 1, 1) + 1) % 1000000009);
	if(prev != 2)
		ret = std::min(ret, (solve(N - 2, 2) + 1) % 1000000009);
	if(prev != 3)
		ret = std::min(ret, (solve(N - 3, 3) + 1) % 1000000009);
    
    return ret;
}

int main() {
	for(scanf("%d", &T); T > 0; --T){
		scanf("%d", &N);
		printf("%d\n", solve(N, 0));
	}
	return 0;
}
