#include<iostream>

int main () {
    int N, arr[3] = {1, 1, 2};
    scanf("%d", &N);
    if(N < 3){
        printf("%d", arr[N]);
        return 0;
    }
    int i;
    for(i = 0; i < N - 2; ++i){
        arr[(i + 3) % 3] = arr[(i + 2) % 3] + arr[(i + 1) % 3];
        arr[0] %= 10; arr[1] %= 10; arr[2] %= 10;
    }
    printf("%d", arr[(i + 2) % 3]);
    return 0;
}
