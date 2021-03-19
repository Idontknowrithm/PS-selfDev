#include<iostream>

double H, Y, year[30];


double DP(){
    // 1Y -> 5% 3Y -> 20% 5Y -> 35%
    for(int i = 0; i < Y; ++i){
        year[i + 1] = (year[i + 1] < (H + year[i]) * 0.05) ? (H + year[i]) * 0.05 : year[i + 1];
        year[i + 3] = (year[i + 3] < (H + year[i]) * 0.20) ? (H + year[i]) * 0.20 : year[i + 1];
        year[i + 5] = (year[i + 5] < (H + year[i]) * 0.35) ? (H + year[i]) * 0.35 : year[i + 1];
    }
}

int main() {
    scanf("%lf %lf", &H, &Y);
    printf("%.0lf", DP() + H);
    return 0;
}
