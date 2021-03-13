#include<iostream>

int N, M, pak, mono;

int main() {
    int pakmin = 1005, monomin = 10005;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &pak, &mono);
        pakmin = (pakmin > pak) ? pak : pakmin;
        monomin = (monomin > mono) ? mono : monomin;
    }
    if(monomin * 6 < pakmin)
        printf("%d", monomin * N);
    else if((N % 6) * monomin < pakmin)
        printf("%d", (N / 6) * pakmin + (N % 6) * monomin);
    else
        printf("%d", (N / 6) * pakmin + pakmin);
    return 0;
}
