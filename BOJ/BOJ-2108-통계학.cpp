#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

int N, max = -5000, min = 5000, mode_max, num[500005], mode[8005];
double avg;
std::vector<int> mode_ans, acsending;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &num[i]);
        acsending.push_back(num[i]);
        avg += num[i];
        ++mode[(num[i] < 0) ? 8001 + num[i] : num[i]];
        max = std::max(max, num[i]);
        min = std::min(min, num[i]);
    }
    for(int i = 0; i <= 8000; ++i)
        mode_max = std::max(mode_max, mode[i]);
    for(int i = 0; i <= 8000; ++i)
        if(mode[i] == mode_max)
            mode_ans.push_back((i > 4000) ? i - 8001 : i);
    std::sort(mode_ans.begin(), mode_ans.end());
    std::sort(acsending.begin(), acsending.end());

    printf("%d\n", (int)std::round(avg / N));
    printf("%d\n", acsending[N / 2]);
    printf("%d\n", (mode_ans.size() == 1) ? mode_ans[0] : mode_ans[1]);
    printf("%d", max - min);

    return 0;
}
