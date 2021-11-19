#include<iostream>
#include<algorithm>
#include<cmath>

int X, Y;
double D, T;

int main() {
    double len, ans, tmp, shortest;
    scanf("%d %d %lf %lf", &X, &Y, &D, &T);
    len = sqrt(X * X + Y * Y);
    shortest = ans = len;
    for(int i = 1;; ++i){
        shortest -= D;
        if(i > 1 && shortest < 0){
            ans = std::min(ans, i * T);
            break;
        }
    }
    for(int i = 1;; ++i){
        
        tmp = std::abs(len - D * i);
        if(tmp > len) break;
        ans = std::min(ans, tmp + T * i);
    }
    printf("%.10lf", ans);
    return 0;
}
