#include<iostream>

int W, N, input[5005];
bool exist[800000];

int main () {
    scanf("%d %d", &W, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &input[i]);
    }
    for(int i = 0; i < N - 1; ++i){
        for(int u = i + 1; u < N; ++u){
            if(input[i] + input[u] < W && exist[W - input[i] - input[u]]){
                printf("YES");
                return 0;
            }
        }
        for(int u = 0; u < i; ++u)
            if(input[i] + input[u] < W)
                exist[input[i] + input[u]] = true;
    }
    printf("NO");
    return 0;
}
