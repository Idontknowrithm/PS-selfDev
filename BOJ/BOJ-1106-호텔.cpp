// 특정 값에 대한 범위 착오, 데이터 중간 중간 업데이트 되지 않는 현상에 대한 고려 

#include<iostream>
#define INF 2147483647

int C, N, cache[2005], city[105][2];

int main() {
    scanf("%d %d", &C, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &city[i][0], &city[i][1]);
    }
    for(int i = 0; i < 2005; ++i) cache[i] = INF;
    cache[0] = 0;
    for(int i = 0; i <= C; ++i){
        for(int u = 0; u < N; ++u){
            if(cache[i] != INF)
            cache[i + city[u][1]] = (cache[i + city[u][1]] > cache[i] + city[u][0]) ?
                                     cache[i] + city[u][0] : cache[i + city[u][1]];
        }
    }
    int min = INF;
    for(int i = C; i < 2005; ++i) min = (min > cache[i]) ? cache[i] : min;
    printf("%d", min);
    return 0;
}
