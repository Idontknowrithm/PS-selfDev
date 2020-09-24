#include<iostream>

#define INF 2147483647
int N, inpS, inpE, inpV, route, city[105][105];

int main() {
    scanf("%d\n%d", &N, &route);
    for(int i = 0; i < 105; ++i)
    for(int u = 0; u < 105; ++u)
        city[i][u] = INF;
    for(int i = 0; i < 105; ++i)
        city[i][i] = 0;
    for(int i = 0; i < route; ++i){
        scanf("%d %d %d", &inpS, &inpE, &inpV);
        city[inpS][inpE] = (city[inpS][inpE] > inpV) ? inpV : city[inpS][inpE];
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u){
            for(int k = 1; k <= N; ++k){
                if(city[u][i] == INF || city[i][k] == INF){
                    continue;
                }
                city[u][k] = (city[u][k] > city[u][i] + city[i][k]) ? city[u][i] + city[i][k] : city[u][k];
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= N; ++u)
            printf("%d ", (city[i][u] == INF) ? 0 : city[i][u]);
        puts("");
    }
    return 0;
}
