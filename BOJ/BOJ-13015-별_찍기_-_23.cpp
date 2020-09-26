#include<iostream>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        printf("*");
    for(int i = 0; i < 2 * (N - 2) + 1; ++i)
        printf(" ");
    for(int i = 0; i < N; ++i)
        printf("*");
    puts("");
    for(int i = 0; i < N - 2; ++i){
        for(int u = 0; u < i + 1; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < N - 2; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < 2 * (N - i - 2) - 1; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < N - 2; ++u)
            printf(" ");
        printf("*");
        puts("");
    }
    for(int i = 0; i < N - 1; ++i)
        printf(" ");
    printf("*");
    for(int i = 0; i < N - 2; ++i)
        printf(" ");
    printf("*");
    for(int i = 0; i < N - 2; ++i)
        printf(" ");
    printf("*");
    puts("");
    for(int i = 0; i < N - 2; ++i){
        for(int u = 0; u < N - i - 2; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < N - 2; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < i * 2 + 1; ++u)
            printf(" ");
        printf("*");
        for(int u = 0; u < N - 2; ++u)
            printf(" ");
        printf("*");
        puts("");
    }
    for(int i = 0; i < N; ++i)
        printf("*");
    for(int i = 0; i < 2 * (N - 2) + 1; ++i)
        printf(" ");
    for(int i = 0; i < N; ++i)
        printf("*");
}
