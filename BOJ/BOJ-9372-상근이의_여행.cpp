// 낚시...

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int T, N, M;

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d", &N, &M);
        std::vector<pp> airplanes;
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            airplanes.push_back({a, b});
        }
        printf("%d\n", N - 1);
    }
    return 0;
}
