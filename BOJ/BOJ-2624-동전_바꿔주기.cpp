지폐를 동전으로 바꾸는 문제인데, 동전의 수가 제한이 있다는 점이 다르다
주어진 동전으로 금액 T를 맞추는 DP 함수를 짜야하는데, 재귀로 짜기 위해서
금액 T에서 동전의 금액 만큼 빼가면서 탐색하는 top down 형태로 함수를 설계하자
점화식: DP(val) += DP(val - 특정 동전의 값)
여기서 동전의 종류에 대한 정보를 넣어야하므로
DP(val, coin) 동전 종류가 coin일 때 val을 만들기 까지 가능한 경우의 수

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

int T, K, cache[10005][105];
std::vector<pp> coins;

int DP(int val, int coin){
    if(!val) return 1;
    if(coin < 0) return 0;

    int &ret = cache[val][coin];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= coins[coin].second; ++i){
        if(val - coins[coin].first * i >= 0)
            ret += DP(val - coins[coin].first * i, coin - 1);
    }
    return ret;
}

int main() {
    scanf("%d\n%d", &T, &K);
    for(int i = 0; i < K; ++i){
        int p, n;
        scanf("%d %d", &p, &n);
        coins.push_back({p, n});
    }
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(T, K - 1));
    return 0;
}
