#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N;
std::vector<pp> lecs; //{val, idx} idx 1: start, 0: end

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int start, end;
        scanf("%d %d", &start, &end);
        lecs.push_back({start, 1});
        lecs.push_back({end, 0});
    }
    std::sort(lecs.begin(), lecs.end());

    int nested = 0, ans = 0;
    for(int i = 0; i < lecs.size(); ++i){
        nested += (lecs[i].second == 0) ? -1 : 1;
        ans = std::max(ans, nested);
    }
    printf("%d", ans);
    return 0;
}
