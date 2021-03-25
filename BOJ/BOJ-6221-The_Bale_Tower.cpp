#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N, cache[25];
std::vector<pp> bale;

int DP(int start){
    if(start == bale.size() - 1) return 1;

    int &ret = cache[start];
    if(ret) return ret;

    ret = 1;
    for(int i = start + 1; i < bale.size(); ++i){
        if(bale[start].first  > bale[i].first && 
           bale[start].second > bale[i].second)
            ret = std::max(ret, DP(i) + 1);
    }
    return ret;
}

int main() {
    int ia, ib;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", &ia, &ib);
        bale.push_back({ia, ib});
    }
    std::sort(bale.begin(), bale.end(), std::greater<pp>());

    int MX = 0;
    for(int i = 0; i < bale.size(); ++i)
        MX = std::max(MX, DP(i));
    printf("%d", MX);

    return 0;
}
