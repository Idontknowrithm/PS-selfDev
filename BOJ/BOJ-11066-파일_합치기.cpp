#include<iostream>
#include<cstring>
#include<algorithm>

const int INF = 1000000000;
int T, K, input[505], cache[505][505];

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(cache, 0, sizeof(cache));
        scanf("%d", &K);
        for(int i = 0; i < K; ++i)
            scanf("%d", &input[i]);
        for(int i = 0; i < K; ++i)
            cache[i][i] = input[i];
        for(int i = 1; i < K; ++i){
            for(int u = 0; u < K - i; ++u){
                cache[u][u + i] = INF;
                for(int l = u; l < u + i; ++l){
                    int tmp = 0;
                    if(u == l) tmp += cache[u][l];
                    else       tmp += 2 * cache[u][l];
                    if(l + 1 == u + i) tmp += cache[l + 1][u + i];
                    else               tmp += 2 * cache[l + 1][u + i]; 
                    cache[u][u + i] = std::min(cache[u][u + i], tmp);
                }
            }
        }
        printf("%d\n", cache[0][K - 1]);
    }
    return 0;
}
