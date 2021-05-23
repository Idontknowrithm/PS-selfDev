// 2차원 배열 이용한 DP 문제
// N개의 앱이 활성화 되어있고, 각각 mi의 메모리를 잡아먹고 있고,
// 이때 각 앱을 비활성화 시킬 수 있는데 이때 드는 비용이 각각 ci인데,
// 여기서 앱 몇 개를 꺼서 M 바이트 이상을 확보해야 함.
// 이 과정에서 비용을 가장 최소화 할 수 있는 방법을 구해야 하는 게 문제

// 처음에 N과 M에 관해서 테이블을 작성하려 노력했는데, M이 천만..?
// --> M이 아닌 비용(c)에 대해서 테이블을 작성해야 했다
// 2차원 테이블을 작성하는 DP에 대해서는 어떤 요소를 테이블 행과 열로 정할 지에
// 대해서 고민해봐야 함.
// 배낭 알고리즘이라는데 주요 점화식은
//
// if(u - cost[i] >= 0)
//     DP[i][u] = std::max(DP[i][u], DP[i - 1][u - cost[i]] + mem[i]);
// DP[i][u] = std::max(DP[i][u], DP[i - 1][u]);
//
// i번째 앱을 비활성화 하는게 더 많은 메모리를 얻을 수 있는가?
// 불가능할 시에는 i번째 앱을 그대로 활성화 해둔다.


#include<iostream>
#include<algorithm>

const int INF = 10000005;
int N, M, ans = INF, mem[105], cost[105], DP[105][10005];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &mem[i]);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &cost[i]);
    for(int i = 1; i <= N; ++i){
        for(int u = 0; u < 20; ++u){
            if(u - cost[i] >= 0)
                DP[i][u] = std::max(DP[i][u], DP[i - 1][u - cost[i]] + mem[i]);
            DP[i][u] = std::max(DP[i][u], DP[i - 1][u]);
            if(DP[i][u] >= M)
                ans = std::min(ans, u);
        }
    }
    printf("%d", ans);
    return 0;
}
