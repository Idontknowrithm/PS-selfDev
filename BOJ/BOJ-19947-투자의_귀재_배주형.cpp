#include<iostream>
#include<cmath>

double H, Y, year[30];


double DP(){
    // 1Y -> 5% 3Y -> 20% 5Y -> 35%
    for(int i = 0; i < Y; ++i){
        year[i + 1] = floor((year[i + 1] < year[i] * 1.05) ? year[i] * 1.05 : year[i + 1]);
        year[i + 3] = floor((year[i + 3] < year[i] * 1.20) ? year[i] * 1.20 : year[i + 3]);
        year[i + 5] = floor((year[i + 5] < year[i] * 1.35) ? year[i] * 1.35 : year[i + 5]);
    }
    return year[(int)Y];
}

int main() {
    scanf("%lf %lf", &H, &Y);
    year[0] = H;
    printf("%.0lf", floor(DP()));
    return 0;
}
