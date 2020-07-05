#include<iostream>
#include<algorithm>

typedef struct{
	int first;
	int second;
} pair;

pair data[100005];

bool compare(pair a, pair b){
	return a.first < b.first;
}

int main () {
	int N, end = 0, ans = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", &data[i].first, &data[i].second);
	}

	std::sort(data, data + N, compare);

	for(int i = 0; i < N; ++i){
		if(data[i].first >= end){
			end = data[i].second;
			++ans;
		}
		else 
			end = (end > data[i].second) ? data[i].second : end;
	}

	printf("%d", ans);
	return 0;
}
