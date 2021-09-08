// 특별한 생각 없이 선형적인 시간 복잡도로 DP 하려고 했음
// DP 과정에서 정렬이 필요한 경우, 또는 정렬된 데이터가 주어지는 경우
// 이분 탐색을 이용한 그리디를 생각해볼 필요가 있다

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

const int MAX = 300005;
int N, S, cache[MAX];
std::vector<pp> images;
std::vector<int> height;

int DP(int idx){
    if(idx == N) return 0;

    int &ret = cache[idx];
    if(ret != -1) return ret;
    int next_h = height[idx] + S;
    int next_idx = std::lower_bound(height.begin(), height.end(), next_h) - height.begin();
    ret = std::max(DP(idx + 1), DP(next_idx) + images[idx].second);
    return ret;
}

int main() {
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; ++i){
        int h, c;
        scanf("%d %d", &h, &c);
        images.push_back({h, c});
    }
    std::sort(images.begin(), images.end());
    for(int i = 0; i < images.size(); ++i)
        height.push_back(images[i].first);
    memset(cache, -1, sizeof(cache));

    printf("%d\n", DP(0));
    return 0;
}
