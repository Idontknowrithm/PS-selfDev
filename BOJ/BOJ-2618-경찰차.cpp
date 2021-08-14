// DP 과정에서 흔적 찍는 문제
// 원래 나는 벡터 배열 만들어서 재귀 안에서 벡터배열에다 흔적을 찍어놓았는데
// 흔적 찍기용 재귀함수를 따로 만들어서 해결하는 방법도 있음
// 재귀 알고리즘은 DP 함수와 똑같이 가져면서 재귀 분기할 때마다 최소값으로 
// 타고 들어가면서 흔적 출력함.
// 그리디 같지만 이미 DP함수를 돌면서 cache에 최소값이 저장되어 있으므로 
// 그때그때 최소값을 찾더라도 이미 optimal한 답이 됨
// 결론: 이미 완성된 cache를 이용하여 흔적 출력을 하자

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define pp std::pair<int, int>

const int INF = 2000000000;
int N, W, cache[1005][1005];
std::vector<pp> query;
std::vector<int> trace[1005];

// 0: (1, 1) N+1: (N, N)
int dist(int pol1, int pol2){
    int tmp = std::abs(query[pol1].first - query[pol2].first) + 
              std::abs(query[pol1].second - query[pol2].second);
    return tmp;
}
// int DP(int pol1, int pol2, int cur){
//     printf("DP: %d %d %d\n", pol1, pol2, cur);
//     if(cur == W) return 0;

//     int &ret = cache[pol1][pol2];
//     if(ret != -1) return ret;

//     ret = INF;
//     int tmp = DP(cur + 1, pol2, cur + 1) + dist(pol1, cur + 1);
//     if(ret > tmp){
//         ret = tmp;
//         trace[cur] = trace[cur + 1];
//         trace[cur].push_back(1);
//     }
//     tmp = DP(pol1, cur + 1, cur + 1) + dist(pol2, cur + 1);
//     if(ret > tmp){
//         ret = tmp;
//         trace[cur] = trace[cur + 1];
//         trace[cur].push_back(2);
//     }
//     return ret;
// }
int DP(int pol1, int pol2, int cur){
    if(cur == W) return 0;

    int &ret = cache[pol1][pol2];
    if(ret != -1) return ret;

    ret = INF;
    ret = std::min(ret, DP(cur + 1, pol2, cur + 1) + dist(pol1, cur + 1));
    ret = std::min(ret, DP(pol1, cur + 1, cur + 1) + dist(pol2, cur + 1));
    return ret;
}
void tracking(int pol1, int pol2, int cur){
    if(cur == W) return;
    int ret1 = DP(cur + 1, pol2, cur + 1) + dist(pol1, cur + 1);
    int ret2 = DP(pol1, cur + 1, cur + 1) + dist(pol2, cur + 1);
    if(ret1 < ret2){
        printf("1\n");
        tracking(cur + 1, pol2, cur + 1);
    }
    else{
        printf("2\n");
        tracking(pol1, cur + 1, cur + 1);
    }
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d\n%d", &N, &W);
    query.push_back({1, 1});
    for(int i = 0; i < W; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        query.push_back({a, b});
    }
    query.push_back({N, N});
    printf("%d\n", DP(0, W + 1, 0));
    tracking(0, W + 1, 0);
    return 0;
}
