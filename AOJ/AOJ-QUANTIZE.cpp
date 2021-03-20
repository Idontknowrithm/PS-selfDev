#include<iostream>
#include<algorithm>
#include<cmath>

const int INF = 999999999;
int T, N, S, seq[105], cache[105][15];

int sqrt_err(int lo, int hi){ // [lo, hi)
    int mid, err = 0, sum = 0;
    
    for(int i = lo; i < hi; ++i)
        sum += seq[i];
    mid = (int)round((double)sum / (hi - lo));
    for(int i = lo; i < hi; ++i){
        err += (seq[i] - mid) * (seq[i] - mid);
    }
    return err;
}
int DP(int start, int part){
    if(start == N) return 0;
    if(part == 0) return 0;

    int& ret = cache[start][part];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = 1; i + start <= N; ++i)
        ret = std::min(ret, sqrt_err(start, start + i) + DP(start + i, part - 1));
    
    printf("arr\n");
    for(int i = 0; i < 4; ++i){
        for(int u = 0; u < 10; ++u)
            printf("%d ",cache[u][i]);
        puts("");
    }
    return ret;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d", &N, &S);
        for(int i = 0; i < N; ++i)
            scanf("%d", &seq[i]);
        std::sort(seq, seq + N);
        for(int i = 0; i < 105; ++i)
        for(int u = 0; u < 15; ++u)
            cache[i][u] = -1;
        printf("///////////////////////////////\n");
        printf("%d\n", DP(0, S));
    }
    return 0;
}
