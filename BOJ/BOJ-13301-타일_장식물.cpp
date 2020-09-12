#include<iostream>

int main () {
    long long N, arr[3] = {4, 6, 10};
    scanf("%lld", &N);
    if(N < 3){
        printf("%lld", arr[N-1]);
        return 0;
    }
    int i;
    for(i = 0; i < N - 2; ++i){
        arr[(i + 2) % 3] = arr[(i + 1) % 3] + arr[(i + 3) % 3];
    }
    printf("%lld", arr[(i + 1) % 3]);
    return 0;
}
