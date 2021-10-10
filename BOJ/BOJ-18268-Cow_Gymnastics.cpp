#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int K, N, ans, arr[15][25];

int main() {
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &arr[i][u]);
    for(int i = 1; i < N; ++i)
    for(int u = i + 1; u <= N; ++u){
        int one = 0, two = 0;
        for(int j = 0; j < K; ++j)
        for(int k = 0; k < N; ++k){
            if(arr[j][k] == i){
                ++one;
                break;
            }
            else if(arr[j][k] == u){
                ++two;
                break;
            }
        }
        if(!one || !two)
            ++ans;
    }
    printf("%d", ans);
    return 0;
}
