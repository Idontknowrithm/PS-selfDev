#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

const int MAX = 300005;
int N, S, cache[MAX][2];
std::vector<pp> images;

int DP(int idx, int incl, int prev){
    if(idx == N) return 0;

    int &ret = cache[idx][incl];
    if(ret != -1) return ret;

    ret = 0;
    if(incl){
        if(images[idx].first - prev >= S){
            ret = std::max(ret, DP(idx + 1, 0, images[idx].first) + images[idx].second);
            ret = std::max(ret, DP(idx + 1, 1, images[idx].first) + images[idx].second);
        }
        else{
            ret = std::max(ret, DP(idx + 1, 0, images[idx].first));
            ret = std::max(ret, DP(idx + 1, 1, images[idx].first));
        }
    }
    else{
        ret = std::max(ret, DP(idx + 1, 0, prev));
        ret = std::max(ret, DP(idx + 1, 1, prev));
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; ++i){
        int h, c;
        scanf("%d %d", &h, &c);
        images.push_back({h, c});
    }
    std::sort(images.begin(), images.end());
    for(int i = 0; i < N; ++i){
        printf("%d %d\n", images[i].first, images[i].second);
    }
    puts("");
    memset(cache, -1, sizeof(cache));

    int ans = std::max(DP(0, 0, 0), DP(0, 1, 0));
    printf("%d\n", ans);
    for(int i = 0; i < N; ++i)
        printf("%d %d\n", cache[i][0], cache[i][1]);
    return 0;
}
