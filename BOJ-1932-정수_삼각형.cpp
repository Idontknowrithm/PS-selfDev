#include<iostream>

int main () {
    int N, max = 0, triangle[500][500];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u <= i; ++u)
        scanf("%d", &triangle[i][u]);
    for(int i = 1; i < N; ++i){
        triangle[i][0] += triangle[i - 1][0];
        for(int u = 1; u < i; ++u){
            triangle[i][u] += (triangle[i - 1][u - 1] > triangle[i - 1][u]) ? triangle[i - 1][u - 1] : triangle[i - 1][u];
        }
        triangle[i][i] += triangle[i - 1][i - 1];
    }
    for(int i = 0; i < N; ++i)
        max = (triangle[N - 1][i] > max) ? triangle[N - 1][i] : max;
    printf("%d", max);
    return 0;
}
