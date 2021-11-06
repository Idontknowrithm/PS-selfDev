// n << 1의 순서를 가장 밑에서 가장 위로 올리니까
// 갑자기 된다..

#include<iostream>
#include<cstring>

int INF = 100005;
int N, K, cache[100005], trace[100005];

int DP(int n){
    if(n < 0 || n > 100000) return INF;
    if(n == K) return 0;

    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = INF;
    int tmp;
    tmp = DP(n << 1) + 1;
    if(tmp < ret){
        ret = tmp;
        trace[n] = (n << 1);
    }
    tmp = DP(n + 1) + 1;
    if(tmp < ret){
        ret = tmp;
        trace[n] = n + 1;
    }
    tmp = DP(n - 1) + 1;
    if(tmp < ret){
        ret = tmp;
        trace[n] = n - 1;
    }
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    memset(cache, -1, sizeof(cache));
    memset(trace, -1, sizeof(trace));
    printf("%d\n", DP(N));
    int ptr = N;
    while(ptr != -1){
        printf("%d ", ptr);
        ptr = trace[ptr];
    }
    return 0;
}
