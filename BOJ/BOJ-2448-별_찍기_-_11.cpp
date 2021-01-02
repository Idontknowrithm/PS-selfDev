// 재귀 함수를 다룰 때 재귀로 점프했을 때 어디에서 시작하는 지 생각하기
// rec(n / 2, 0, 0); 이라고 하면 다음에 떨어질 때도 같은 곳에서 떨어지니
// rec(n / 2, startR, startC); 라고 하여 올바르게 재귀를 반영

#include<iostream>
#include<cstring>

char buf[5000][10000];
void rec(int n, int startR, int startC){
    if(n == 0) return;
    rec(n / 2, startR, startC);
    rec(n / 2, startR + 3 * (n / 2), startC);
    rec(n / 2, startR + 3 * (n / 2), startC + 3 * n);
    strcpy(&buf[startR][startC], "*\n");
    strcpy(&buf[startR + 1][startC], "* *\n");
    strcpy(&buf[startR + 2][startC], "*****\n");
}

int main(){
    int N;
    scanf("%d", &N);
    rec(N / 3, 0, 0);
    for(int i = 0; i < 5000; ++i){
        for(int u = 0; u < i * 2; ++u)
            if(buf[i][u] != '*') buf[i][u] = ' ';
    }
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < N - i - 1; ++u)
            printf(" ");
        for(int u = 0; u < i * 2 + 1; ++u)
            printf("%c", buf[i][u]);
        for(int u = 0; u < N - i - 1; ++u)
            printf(" ");
        printf("\n");
    }
    return 0;
}
