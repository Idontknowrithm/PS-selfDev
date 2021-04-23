// double과 int의 형 변환에서 오류가 생긴 듯
// int를 double로 바꿔야 하는 부분이 있으면 안전하게
// 처음부터 double로 받
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define pp std::pair<double, double>

int N; double ans = 0;
std::vector<pp> dots;

double outer_product(pp a, pp b, pp c){
    double ans;
    pp AB = {b.first - a.first, b.second - a.second};
    pp AC = {c.first - a.first, c.second - a.second};
    ans = AB.first * AC.second - AB.second * AC.first;
    ans /= 2;
    return ans;
}

int main(){
    double x, y;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf", &x, &y);
        dots.push_back({x, y});
    }
    for(int i = 1; i < N - 1; ++i){
        ans += outer_product(dots[0], dots[i], dots[i + 1]);
    }
    printf("%.1lf", ans < 0 ? -ans : ans);
    return 0;
}
