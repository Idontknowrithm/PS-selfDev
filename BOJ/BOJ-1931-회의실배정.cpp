// #include<iostream>
// #include<algorithm>

// typedef struct{
// 	int first;
// 	int second;
// } pair;

// pair data[100005];

// bool compare(pair a, pair b){
// 	return a.first < b.first;
// }

// int main () {
// 	int N, end = 0, ans = 0;
// 	scanf("%d", &N);
// 	for(int i = 0; i < N; ++i){
// 		scanf("%d %d", &data[i].first, &data[i].second);
// 	}

// 	std::sort(data, data + N, compare);

// 	for(int i = 0; i < N; ++i){
// 		if(data[i].first >= end){
// 			end = data[i].second;
// 			++ans;
// 		}
// 		else 
// 			end = (end > data[i].second) ? data[i].second : end;
// 	}

// 	printf("%d", ans);
// 	return 0;
// }

// vector, pair 처럼 자동 정렬 가능한 자료구조 위주로 사용합시다
// (struct 같은 임의 자료구조 사용을 줄이자는 말)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>
#define INF 2147483647

int N, max, prev_end_time;
std::vector<pp> meeting;

int main() {
    int a, b;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &a, &b);
        meeting.push_back({b, a});
    }
    // WARNING: meeting sequences reversed
    std::sort(meeting.begin(), meeting.end());

    for(int i = 0 ; i < meeting.size(); ++i){
        if(prev_end_time <= meeting[i].second){
            prev_end_time = meeting[i].first;
            ++max;
        }
    }
    printf("%d", max);
    return 0;
}
