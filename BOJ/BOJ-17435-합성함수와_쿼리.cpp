// sparse table(희소 배열)에 대해서 배우는 문제. 희소 배열 개념 자체는
// 흩뿌려진 배열을 적은 데이터를 사용하여 나타내는 것, 예를 들어 입력이 2차원으로
// 들어오고 10개만 들어온다면
// arr[10000][10000]을 선언해서 10개만 받을 수 있으나 데이터 손실이 크다. 따라서
// arr[10][3]을 하고, 3개의 배열에 {row, col, val}을 저장한다면 데이터 손실이
// 적을 수 있다. row, col은 val 값이 들어온 인덱스를 나타낸다
// 그러나 이런 곳에서 희소배열은 좀 달랐다. 지수적인 값만 담고 있는 것을 희소배열이라 했다
// 이 문제는 다음과 같다. f(x) = f_1(x), f(f(x)) = f_2(x) 이런 식인데, f_n(x) 일 때
// n과 x가 주어지면 답을 구하는 것이다. 이때 f_a(f_b(x)) = f_a+b(x)인 점을 이용하여
// n이 1, 2, 4, 8, ... 일 때만 값을 구해 그 값으로만 f_n을 찾는 방법을 사용했다

// 다시 정리해보면 f(f(x)) = f2(x), f2(f2(x)) = f4(x), ... 을 이용해서
// f(x)를 구하고, 이를 이용해서 f2를 구하고, 이를 이용해서 f4를 구하는 식으로 희소 배열을
// 구성한 뒤, 구해야하는 n(f_n(x)에서의 n)을 2진수로 만들어서 1이 있는 곳만 골라 희소배열에서
// 찾은 후 계속 중첩시켜주는 

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
