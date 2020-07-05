// 벡터 안에서 충돌 같은 게 있었나봄. 입력값을 무게 기준으로 정렬 안했을 때 런타임 에러
// K*N 형식의 DP로 접근 까지는 맞았으나, 같은 물건 중복을 생각 못함.

#include<iostream>
#include<vector>
#include<algorithm>

int N, K, DP[100001] = {0,};
std::pair<int, int> input[110];
std::vector<int> trace[100001];

bool find(std::vector<int>* vec, int val){
	for(int i = 0; i < vec->size(); ++i)
		if(val == (*vec)[i])
			return true;
	return false;
}
bool cmp(std::pair<int, int> a, std::pair<int, int> b){
	return a.first < b.first;
}

int main () {
    int inp1, inp2, max = -1;
	
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &inp1, &inp2);
        input[i] = {inp1, inp2};
    }
	std::sort(input, input + N);
    for(int i = 0; i < K; ++i){
        for(int u = 0; u < N; ++u){
            if(i + input[u].first <= K && DP[i + input[u].first] < DP[i] + input[u].second && !find(&trace[i], input[u].first)){
				trace[i + input[u].first].clear();
				trace[i + input[u].first].assign(trace[i].begin(), trace[i].end());
				trace[i + input[u].first].push_back(input[u].first);
				DP[i + input[u].first] = DP[i] + input[u].second;
			}
        }
    }
	for(int i = 0; i <= K; ++i)
		max = (max < DP[i]) ? DP[i] : max;
    printf("%d", max);

    return 0;
}
