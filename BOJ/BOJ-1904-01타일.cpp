#include<iostream>

int main(){
    int N, i, fib[3] = {1, 2, 3};
    scanf("%d", &N);
    if(N < 3){
        printf("%d", fib[N - 1]);
        return 0;
    }
    for(i = 2; i < N; ++i){
        fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
        fib[i % 3] %= 15746;
    }
    printf("%d", fib[(i - 1) % 3]);

    return 0;
}
