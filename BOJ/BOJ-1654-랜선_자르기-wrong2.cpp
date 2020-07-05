// runtime error

#include<iostream>
#include<vector>

int K, N;
int search(long long int start, long long int end, int* lan){
	int lanNum, mid, ans = 0;
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
	for(int i = 0; i < K; ++i){
		scanf("%d", &lan[i]);
		sum += lan[i];
	}
	tempMax = sum / N;
	max = search(1, tempMax, lan);

	printf("%d", max);
	return 0;
}
