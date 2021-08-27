#include<iostream>
#include<cstring>
#include<algorithm>

const int INF = 10000000;
int N, M, working_day[105], cache[105][205]; // days, coupons

int DP(int day, int coupon){
    if(day > N) return 0;

    int &ret = cache[day][coupon];
    if(ret != -1) return ret;
    ret = INF;
    if(working_day[day])
        ret = DP(day + 1, coupon);
    if(coupon >= 3)
        ret = std::min(ret, DP(day + 1, coupon - 3));
    ret = std::min(ret, DP(day + 1, coupon) + 10000);
    ret = std::min(ret, DP(day + 3, coupon + 1) + 25000);
    ret = std::min(ret, DP(day + 5, coupon + 2) + 37000);
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int wd;
        scanf("%d", &wd);
        working_day[wd] = 1;
    }
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(1, 0));
    return 0;
}
