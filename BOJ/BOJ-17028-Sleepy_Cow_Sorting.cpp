#include<iostream>

int N, cows[105];
bool not_sorted[105];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &cows[i]);
    for(int i = 0; i < N - 1; ++i)
        if(cows[i] > cows[i + 1])
            not_sorted[i] = true;
    for(int i = N - 1; i >= 0; --i)
        if(not_sorted[i]){
            printf("%d", i + 1);
            return 0;
        }
    printf("0");
    return 0;
}
