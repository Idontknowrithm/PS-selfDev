// float 형을 사용할 때는 최대한 적은 수식을 거치게끔 해야함
// 또는 최대한 간단한 식을 사용하기

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
        printf("0.000");
    else if(len_between + r1 <= r2){
        ans = M_PI * r1 * r1;
        printf("%.3lf", ans);
    }
    else{
        double theta1 = acos((r1 * r1 + len_between * len_between - r2 * r2) / (2 * r1 * len_between));
        double theta2 = acos((r2 * r2 + len_between * len_between - r1 * r1) / (2 * r2 * len_between));
        double ans1 = (r1 * r1 * theta1) - (r1 * r1 * sin(2 * theta1)) / 2;
        double ans2 = (r2 * r2 * theta2) - (r2 * r2 * sin(2 * theta2)) / 2;

        printf("%.3lf", ans1 + ans2);
    }
    return 0;
}
