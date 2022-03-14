#include<iostream>
#include<cstring>

int N, M, things[105][105], comparable[105];

int main() {
    memset(things, 1, sizeof(things));
    scanf("%d\n%d", &N, &M);

    for(int i = 0; i < M; ++i){
        int a, b;

        scanf("%d %d", &a, &b);
        things[a - 1][b - 1] = 1;    
    }
    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int u = 0; u < N; ++u){
                if(things[i][u] > things[i][k] + things[k][u])
                    things[i][u] = things[i][k] + things[k][u];
            }
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = i + 1; u < N; ++u){
        if(things[i][u] != things[104][104] ||
           things[u][i] != things[104][104]){
            ++comparable[i];
            ++comparable[u];
        }
        
    }
    for(int i = 0; i < N; ++i)
        printf("%d\n", N - comparable[i] - 1);
        
    return 0;
}
