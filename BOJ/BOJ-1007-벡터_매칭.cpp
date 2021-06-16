#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>
#define row first
#define col second

int T, N;
double ans, tmp;
std::vector<pp> input;

int main() {
    int ia, ib;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d %d", &ia, &ib);
            input.push_back({ia, ib});
        }
    }
    return 0;
}
