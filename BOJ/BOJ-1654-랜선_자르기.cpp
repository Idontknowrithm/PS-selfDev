#include<iostream>
#include<vector>

int K, N;
long long int search(long long int start, int* lan){
	long long int lanNum, mid, end = 0, ans = 0;
	for(int i = 0; i < K; ++i)
		end += lan[i];
	end /= N;
	while(start <= end){
		lanNum = 0;
		mid = (start + end) / 2;
		for(int i = 0; i < K; ++i)
			lanNum += lan[i] / mid;
		if(lanNum < N)
			end = mid - 1;
		else if(lanNum >= N){
			ans = (mid > ans) ?  mid : ans;
			start = mid + 1;
		}
	}
	return ans;
}

int main () {
	int max, lan[10010];
	long long int tempMax, sum = 0;	
	scanf("%d %d", &K, &N);
	for(int i = 0; i < K; ++i)
		scanf("%d", &lan[i]);
	max = search(1, lan);

	printf("%d", max);
	return 0;
}
