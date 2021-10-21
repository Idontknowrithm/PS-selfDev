#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int N, nested;
std::vector<pp> lines;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int start, end;
        scanf("%d %d", &start, &end);
        lines.push_back({start, 1});
        lines.push_back({end, 0});
    }
    std::sort(lines.begin(), lines.end());
    int ans = 0;
    int tmp_pos = lines[0].first;
    nested = 1;
    for(int i = 1; i < lines.size(); ++i){
        ans += (nested) ? lines[i].first - tmp_pos : 0;
        nested += (lines[i].second) ? 1 : -1;
        tmp_pos = lines[i].first;
    }
    printf("%d", ans);
    return 0;
}
