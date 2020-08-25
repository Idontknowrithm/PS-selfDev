#include<iostream>
#include<cmath>

int main () {
    int N, M, target, ptr, start, ans = 0, arr[55];

    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i)
        arr[i - 1] = i;
    start = 0;
    for(int i = 0; i < M; ++i){
        scanf("%d", &target);
        for(int i = 0; i < N; ++i)
            if(arr[i] == target){
                ptr = i;
                break;
            }
    
        ans += (abs(start - ptr) < N - abs(start - ptr)) ? abs(start - ptr) : N - abs(start - ptr); 
        start = (ptr + 1 >= N) ? 0 : ptr;
        ptr = 0;
        for(int i = 0; i < N; ++i)
            if(arr[i] != target)
                arr[ptr++] = arr[i];
        --N;
    }
    printf("%d", ans);

    return 0;
}
