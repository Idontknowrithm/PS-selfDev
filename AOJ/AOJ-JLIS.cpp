#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 2147483647

int T, N, M, a[105], b[105], cache[105][105];

int lis(int astart, int bstart){
    int &ret = cache[astart + 1][bstart + 1];
    if(ret) return ret;

    ret = 2;
    for(int i = astart + 1; i < N; ++i)
        if(astart == -1 || a[astart] < a[i])
            ret = std::max(ret, lis(i, bstart) + 1);
    for(int i = bstart + 1; i < M; ++i)
        if(bstart == -1 || b[bstart] < b[i])
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
