// 공식 유도 중 오류가 난 듯

#include<iostream>
#include<algorithm>
#include<cmath>

double X1, Y1, r1, X2, Y2, r2, len_between, ans;

int main() {
    scanf("%lf %lf %lf %lf %lf %lf", &X1, &Y1, &r1, &X2, &Y2, &r2);
    if(r1 > r2){
        std::swap(X1, X2);
        std::swap(Y1, Y2);
        std::swap(r1, r2);
    }
    len_between = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
    if(r1 + r2 <= len_between)
        printf("0");
    else if(len_between + r1 <= r2){
        ans = M_PI * r1 * r1;
        printf("%.3lf", ans);
    }
    else if(r1 * r1 + len_between * len_between >= r2 * r2){
        double hi = M_PI / 2, lo = 0;
        for(int i = 0; i < 500; ++i){
            double mid = (hi + lo) / 2;
            double exp = r2 * cos(mid) + r1 * sqrt(1 - (r2 * r2)/(r1 * r1) * sin(mid) * sin(mid));
            if(exp > len_between)
                lo = mid;
            else 
                hi = mid;
        }
        double l1 = r2 * cos(hi), l2 = len_between - l1;
        ans = r2 * r2 * hi - l2 * r2 * sin(hi);
        ans += r1 * r1 * acos(l1 / r1) - l1 * sqrt(r1 * r1 - l1 * l1);
        printf("%.3lf", ans);
    }
    else{
        double hi = M_PI / 2, lo = 0;
        for(int i = 0; i < 100; ++i){
            double mid = (hi + lo) / 2;
            double exp = r1 * r1 * sin(mid) * sin(mid) + len_between * len_between + 
                         2 * len_between * r1 * cos(mid) + r1 * r1 * cos(mid) * cos(mid);
            if(exp > r2 * r2)
                lo = mid;
            else 
                hi = mid;
        }
        double theta2 = asin(r1 * sin(hi) / r2);
        printf("%.3lf\n", theta2);
        ans = 0.5 * r1 * r1 * (2 * M_PI - 2 * hi) + r1 * r1 * sin(hi) * cos(hi);
        ans += r2 * r2 * theta2 - r2 * r2 * sin(theta2) * cos(theta2);
        printf("%.3lf", ans);
    }
    return 0;
}
