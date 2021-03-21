#include<iostream>
#include<algorithm>

const int INF = 999999999;
int T, N, S, seq[105], cache[105][15];

int sqrt_err(int lo, int hi){ // [lo, hi)
    int mid, err = 0, sum = 0;
    
    for(int i = lo; i < hi; ++i)
        sum += seq[i];
    mid = (int)((double)sum / (hi - lo) + 0.5);
    for(int i = lo; i < hi; ++i){
        err += (seq[i] - mid) * (seq[i] - mid);
    }
    return err;
}
int DP(int start, int part){
    if(start == N - 1) return 0;

    int& ret = cache[start][part];
    if(ret != -1) return ret;
    ret = INF;

    if(part != 1)
        for(int i = 1; i + start < N; ++i){
            ret = std::min(ret, sqrt_err(start, start + i) + DP(start + i, part - 1));
        }
    else 
        ret = sqrt_err(start, N);
    
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
        printf("%d\n", DP(0, S));
    }
    return 0;
}
