// 입력 범위 숙지하기 --> longlong 안해서 틀림

#include<iostream>
#include<vector>

std::vector<int> trees;
int N, M;

int search(int max){
	int mid, start = 0, end = max, ans = 0;
	long long int hayday;

	while(start <= end){
		mid = (start + end) / 2;
		hayday = 0;
		for(int i = 0; i < trees.size(); ++i)
			hayday += (trees[i] - mid > 0) ? trees[i] - mid : 0;
		if(hayday >= M){
			ans = (mid > ans) ? mid : ans;
			start = mid + 1;
		}
		else 
			end = mid - 1;
	}
	return ans;
}

int main () {
	int inp, max = -1;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", &inp);
		max = (inp > max) ? inp : max;
		trees.push_back(inp);
	}
	printf("%d", search(max));
	return 0;
}
