#include<iostream>
#define INF 2147483647
int main() {
    int N, arr[100010];
    for(int i = 1; i <= 100000; ++i)
        arr[i] = INF;
    for(int i = 0; i <= 100000; ++i){
        arr[i + 1] = (arr[i + 1] > arr[i] + 1) ? arr[i] + 1 : arr[i + 1];
        arr[i + 2] = (arr[i + 2] > arr[i] + 1) ? arr[i] + 1 : arr[i + 2];
        arr[i + 5] = (arr[i + 5] > arr[i] + 1) ? arr[i] + 1 : arr[i + 5];
        arr[i + 7] = (arr[i + 7] > arr[i] + 1) ? arr[i] + 1 : arr[i + 7];
    }
    scanf("%d", &N);
    printf("%d", arr[N]);

    return 0;
}
