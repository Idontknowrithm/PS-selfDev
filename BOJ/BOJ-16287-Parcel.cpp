// N개의 값 중 4개를 선정해서 값 합을 W로 맞춰야 함
// 문제의 답을 바꾸지 않는 선에서 임의의 규칙을 만들어 중복을 줄일 수 있는 아이디어가 있었음
// 먼저 a+b+c+d=W 인 a, b, c, d를 찾아야 하는데, 이 식을 a+b=W-c-d로 바꾸고,
// 이 식에서 1 <= a < b <= N인 a, b를 완전탐색 하면서, 1 <= c < d < a인
// c, d값 중에서 a+b=W-c-d를 만족하는 c, d,값을 찾는 문제로 바꿀 수 있는데, 이때
// c < d < a < b라는 규칙을 추가했으나 이 규칙은 답에 영향을 주지 않음. 이유는
// a, b, c, d는 N개의 값에서 임의로 뽑은 것이므로, 모두 섞일 수 있고 섞일 수 있다는 것은
// 정렬되도 상관없다는 것.

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
