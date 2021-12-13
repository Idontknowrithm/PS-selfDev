#include<iostream>

const int MAX = 200005;
int M, Q, input[MAX], sparse[MAX][25];

int main() {
    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        scanf("%d", &input[i + 1]);
    }
    for(int i = 1; i <= M; ++i){
        sparse[i][1] = input[i];
        int power = 2;
        for(int u = 2; power <= M; ++u){
            sparse[i][u] = input[sparse[i][u - 1]];
            power *= 2;
        }
    }
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i){
        int n, x, power = 1;
        scanf("%d %d", &n, &x);
        while(n){
            if(n & 1)
                x = sparse[x][power];

            power += 1;
            n >>= 1;
        }
        printf("%d\n", x);
    }
    return 0;
}
