#include<iostream>

const int MAX = 500005;
int M, Q, sparse[MAX][25];

int main() {
    scanf("%d", &M);
    for(int i = 1; i <= M; ++i){
        scanf("%d", &sparse[i][1]);
    }
    for(int u = 2; u < 21; ++u)
    for(int i = 1; i <= M; ++i)
        sparse[i][u] = sparse[sparse[i][u - 1]][u - 1];
        
    
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i){
        int n, x, power = 1;
        scanf("%d %d", &n, &x);
        while(n){
            if(n & 1)
                x = sparse[x][power];

            ++power;
            n >>= 1;
        }
        printf("%d\n", x);
    }
    return 0;
}
