#include<iostream>
#include<algorithm>
#define pp std::pair<double, double>
#define x first
#define y second

int T;
double N, M, n, m, margin[4]; // left, right, top, bottom
pp in1, in2;

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%lf %lf", &N, &M);
        scanf("%lf %lf %lf %lf", &in1.x, &in1.y, &in2.x, &in2.y);
        scanf("%lf %lf", &n, &m);
        margin[0] = in1.x;
        margin[1] = N - in2.x;
        margin[2] = M - in2.y;
        margin[3] = in1.y;
        double ans = 1e9;
        if(margin[2] + margin[3] >= m){
            ans = std::min(ans, std::max((double)0, m - margin[2]));
            ans = std::min(ans, std::max((double)0, m - margin[3]));
        }
        if(margin[0] + margin[1] >= n){
            ans = std::min(ans, std::max((double)0, n - margin[0]));
            ans = std::min(ans, std::max((double)0, n - margin[1]));
        }
        if(ans == 1e9)
            printf("-1\n");
        else 
            printf("%.9lf\n", ans);
    }
    return 0;
}
