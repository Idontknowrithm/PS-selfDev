#include<iostream>

int main () {
    int N, RGB[1001][3];

    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < 3; ++u)
        scanf("%d", &RGB[i][u]);
    for(int i = 1; i < N; ++i){
        RGB[i][0] += (RGB[i - 1][1] > RGB[i - 1][2]) ? RGB[i - 1][2] : RGB[i - 1][1];
        RGB[i][1] += (RGB[i - 1][0] > RGB[i - 1][2]) ? RGB[i - 1][2] : RGB[i - 1][0];
        RGB[i][2] += (RGB[i - 1][0] > RGB[i - 1][1]) ? RGB[i - 1][1] : RGB[i - 1][0];
    }
    if(RGB[N - 1][0] > RGB[N - 1][1])
        printf("%d", (RGB[N - 1][1] > RGB[N - 1][2]) ? RGB[N - 1][2] : RGB[N - 1][1]);
    else
        printf("%d", (RGB[N - 1][0] > RGB[N - 1][2]) ? RGB[N - 1][2] : RGB[N - 1][0]);
    return 0;
}
