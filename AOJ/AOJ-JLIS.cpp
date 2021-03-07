// 아 long long을 int로만 바꿨는데 돌아감 진짜 억울하다
// int_min 근처에서 무슨 일이 있는 것 같은데 확실히 

#include<iostream>
#include<algorithm>
#include<cstring>
#define INF  2147483647
#define NNF -2147483648

int T, N, M;
int a[105], b[105], cache[105][105];
int lis(int astart, int bstart){
    int at, bt, maxt, &ret = cache[astart + 1][bstart + 1];
    if(ret) return ret;

    ret = 0;
    at = (astart == -1) ? NNF : a[astart];
    bt = (bstart == -1) ? NNF : b[bstart];
    maxt = (at < bt) ? bt : at;

    for(int i = astart + 1; i < N; ++i)
        if(maxt < a[i])
            ret = std::max(ret, lis(i, bstart) + 1);
    for(int i = bstart + 1; i < M; ++i)
        if(maxt < b[i])
            ret = std::max(ret, lis(astart, i) + 1);
    
    return ret;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d", &N, &M);
        memset(cache, 0, (105 * 105) << 2);
        
        for(int i = 0; i < N; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < M; ++i)
            scanf("%d", &b[i]);

        // a[-1] == b[-1] == -INF
        printf("%d\n", lis(-1, -1));
    }
    return 0;
}
