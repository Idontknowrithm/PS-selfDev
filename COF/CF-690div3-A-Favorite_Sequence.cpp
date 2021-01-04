#include<iostream>

int main(){
    int T, N, arr[305];
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &arr[i]);
        if(N & 1){
            for(int i = 0; i < N / 2; ++i)
                printf("%d %d ", arr[i], arr[N - i - 1]);
            printf("%d\n", arr[N / 2]);
        }
        else{
            for(int i = 0; i < N / 2; ++i)
                printf("%d %d ", arr[i], arr[N - i - 1]);
            puts("");
        }
    }
    return 0;
}
