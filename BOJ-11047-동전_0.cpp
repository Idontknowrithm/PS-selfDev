#include<iostream>

int main (){
    int N, K, ans = 0, coin[10];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", &coin[i]);
    for(int i = N - 1; i >= 0; --i){
        ans += K / coin[i];
        K %= coin[i];
    }
    printf("%d", ans);
    return 0;
}
