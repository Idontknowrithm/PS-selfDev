#include<iostream>
#include<cstring>

int N, K, T, str[405][405], rev[405][405];

int main() {
    memset(str, 1, sizeof(str));
    memset(rev, 1, sizeof(rev));

    scanf("%d %d", &N, &K);

    for(int i = 0; i < K; ++i){
        int a, b;

        scanf("%d %d", &a, &b);
        str[a - 1][b - 1] = 1;
        rev[b - 1][a - 1] = 1;
    }
    for(int k = 0; k < N; ++k)
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        if(str[i][k] + str[k][u] < str[i][u])
            str[i][u] = str[i][k] + str[k][u];
        if(rev[i][k] + rev[k][u] < rev[i][u])
            rev[i][u] = rev[i][k] + rev[k][u];
    }
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        int a, b;

        scanf("%d %d", &a, &b);
        if(str[a - 1][b - 1] < str[404][404])
            puts("-1");
        else if(rev[a - 1][b - 1] < rev[404][404])
            puts("1");
        else 
            puts("0");
    }
    return 0;
}
