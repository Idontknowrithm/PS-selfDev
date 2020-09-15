#include<iostream>

int main () {
    long long N, arr[40];
    arr[0] = arr[1] = 1;
    for(int i = 2; i <= 35; ++i){
        arr[i] = 0;
        for(int u = 0; u < i; ++u){
            arr[i] += arr[u] * arr[i - u - 1];
        }
    }
    scanf("%lld", &N);
    printf("%lld", arr[N]);

    return 0;
}
