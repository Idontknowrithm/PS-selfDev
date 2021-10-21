분할 정복과 스위핑 알고리즘인데, 스위핑의 느낌은 강하지 않고 
적당한 분할 정복과 상수 커팅 정도가 주요 알고리즘이라 볼 수 있겠다
먼저 분할 기준은 x축(가로선)에 수직인 선으로 한다
기준 선으로 한 면을 두 면으로 나누고, 각 면에서 최소값을 찾는다
이때 최적해가 각 면이 아닌 면과 면을 가로질러 있을 수 있기 때문에
이도 따로 구해준다. 즉
최적해 = min((A면 최소), (B면 최소), (A면에서 한 점, B면에서 한 점을 고른 최소))

#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

const int INF = 1000000005;
int N;
std::vector<pp> dots;

int dist_cal(pp a, pp b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    y = x * x + y * y;
    return y;
}

// Divide and Conquer
int DAC(int start, int end){
    if(start == end) return INF;
    if(start == end + 1) return dist_cal(dots[start], dots[end]);

    int dist_min = dist_cal(dots[start], dots[end]);
    int mid = (start + end) / 2;
    dist_min = std::min(dist_min, DAC(start, mid));
    dist_min = std::min(dist_min, DAC(mid + 1, end));

    std::vector<pp> between;
    int standard = dots[mid].first;
    for(int i = mid; i >= start; --i){
        if((standard - dots[i].first) * (standard - dots[i].first) > dist_min)
            break;
        between.push_back({dots[i].second, dots[i].first});
    }
    for(int i = mid + 1; i <= end; ++i){
        if((dots[i].first - standard) * (dots[i].first - standard) > dist_min)
            break;
        between.push_back({dots[i].second, dots[i].first});
    }
    if(!between.size())
        return dist_min;
    std::sort(between.begin(), between.end());
    int size = between.size();
    for(int i = 0; i < size - 1; ++i){
        int ix = between[i].second, iy = between[i].first;
        for(int u = i + 1; u < size; ++u){
            int ux = between[u].second, uy = between[u].first;
            int x_d = (ux - ix) * (ux - ix);
            int y_d = (uy - iy) * (uy - iy);
            if(y_d >= dist_min)
                break;
            if(x_d >= dist_min)
                continue;
            dist_min = std::min(dist_min, x_d + y_d);
        }
    }
    return dist_min;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        dots.push_back({a, b});
    }
    std::sort(dots.begin(), dots.end());
    printf("%d", DAC(0, N - 1));
    return 0;
}
