// 2차원 DP 연습 필요
// 코너 케이스에 대해 조금 더 깊게 생각할 필요 

#include<iostream>
#include<algorithm>
#define pp std::pair<int, int>

int N, K, cache[105][100005];
pp input[105];

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; ++i){
        int W, V;
        scanf("%d %d", &W, &V);
        input[i].first = W;
        input[i].second = V;
    }
    for(int i = 1; i <= N; ++i){
        for(int u = 1; u <= K; ++u){
            if(input[i].first <= u)
                cache[i][u] = std::max(cache[i - 1][u], cache[i - 1][u - input[i].first] + input[i].second);
            else 
                cache[i][u] = cache[i - 1][u];
        }
    }
    int max = -1;
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= K; ++u)
        max = (cache[i][u] > max) ? cache[i][u] : max;
    printf("%d", max);

    return 0;
}
