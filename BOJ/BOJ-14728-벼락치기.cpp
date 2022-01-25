#include<iostream>
#include<algorithm>
#include<cstring>

//        0: time 1: score
int N, T, q_data[105][2], cache[105][10005];

int DP(int chap, int time){
    if(time > T) return -100005;
    if(chap == N) return 0;

    int &ret = cache[chap][time];
    if(ret != -1) return ret;

    ret = 0;
    ret = std::max(ret, DP(chap + 1, time));
    ret = std::max(ret, DP(chap + 1, time + q_data[chap][0]) + q_data[chap][1]);

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &q_data[i][0], &q_data[i][1]);
    
    printf("%d", DP(0, 0));
    return 0;
}
