// DP 캐시를 필요 이상으로 많은 공간을 잡음. 1차원으로 가능했는데 2차원으로 잡음
// -> DP 안에서 포문을 돌리는 방법으로 1차원 캐시로 해결할 수 있었는데, 틀린 이유는

// int DP(int idx, int cost){
//     if(idx == N) return 0;

//     int &ret = cache[cost];
//     if(ret != -1) return ret;

//     ret = 0;
//     int cur_cal = candies[idx].first, cur_cost = candies[idx].second;
//     if(cur_cost + cost <= M){
//         ret = std::max(ret, DP(idx + 1, cur_cost + cost) + cur_cal);
//         ret = std::max(ret, DP(idx, cur_cost + cost) + cur_cal);
//     }
//     ret = std::max(ret, DP(idx + 1, cost));

//     return ret;
// }
// 이런 식으로 포문 없이 모든 경우의 수를 탐색하려고 했는데 이런 식이면
// 중간에 캐시에 적절한 오답이 캐싱되어 정답은 아니지만 max 알고리즘에서
// 채택될만한 값이 계속 채택되어 정작 정답이 max 알고리즘에서 채택되지 않아서
// 오답을 내게 됨

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int N, M, cache[10005];
std::vector<pp> candies;

int DP(int cost){
    int &ret = cache[cost];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < candies.size(); ++i){
        int cur_cal = candies[i].first, cur_cost = candies[i].second;
        if(cur_cost + cost <= M)
            ret = std::max(ret, DP(cur_cost + cost) + cur_cal);
    }
    return ret;
}

int main() {
    while(1){
        candies.clear();
        memset(cache, -1, sizeof(cache));
        int candy, cost, cal;
        double cost_d;
        scanf("%d %lf", &candy, &cost_d);
        if(!candy) break;
        cost = cost_d * 100 + 0.5;
        N = candy;
        M = cost;
        for(int i = 0; i < N; ++i){
            scanf("%d %lf", &cal, &cost_d);
            cost = cost_d * 100 + 0.5;
            candies.push_back({cal, cost});
        }
        printf("%d\n", DP(0));
    }
    return 0;
}
