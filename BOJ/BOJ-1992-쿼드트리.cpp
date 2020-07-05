#include<iostream>

int N, video[64][64];

void quadTree(int startR, int startC, int size){
    int black = 0, white = 0;
    for(int i = startR; i < startR + size; ++i)
    for(int u = startC; u < startC + size; ++u){
        black += (video[i][u]) ? 1 : 0;
        white += (video[i][u]) ? 0 : 1;
    }
    if(black == size * size){
        printf("1");
        return;
    }
    else if(white == size * size){
        printf("0");
        return;
    }
    printf("(");
    quadTree(startR, startC, size / 2);
    quadTree(startR, startC + size / 2, size / 2);
    quadTree(startR + size / 2, startC, size / 2);
    quadTree(startR + size / 2, startC + size / 2, size / 2);
    printf(")");
}

int main () {
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < N; ++u)
            video[i][u] = getchar() - '0';
        getchar();
    }
    quadTree(0, 0, N);
    return 0;
}
