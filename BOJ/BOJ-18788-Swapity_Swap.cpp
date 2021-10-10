// 시간이 넉넉한데 규칙을 모르겠다? -> 그냥 다 해봐서 규칙 찾아서 그걸로 문제를 풀자

#include<iostream>

int N, K, a1, a2, b1, b2;
int permutation[105];

void reverse(int start, int end){
    int tmp[105];
    for(int i = start; i <= end; ++i)
        tmp[i - start] = permutation[i];
    for(int i = start; i <= end; ++i)
        permutation[end + start - i] = tmp[i - start];
}

int main(){
    for(int i = 0; i < 105; ++i)
        permutation[i] = i + 1;
    scanf("%d %d\n%d %d\n%d %d", &N, &K, &a1, &a2, &b1, &b2);
    int tmp = 0;
    while(1){
        reverse(a1 - 1, a2 - 1);
        reverse(b1 - 1, b2 - 1);
        ++tmp;
        int ans = 0;
        for(int i = 0; i < N - 1; ++i)
            ans += (permutation[i] < permutation[i + 1]) ? 1 : 0;
        if(ans == N - 1) break;
    }
    K %= tmp;
    for(int i = 0; i < K; ++i){
        reverse(a1 - 1, a2 - 1);
        reverse(b1 - 1, b2 - 1);
    }
    for(int i = 0; i < N; ++i)
        printf("%d\n", permutation[i]);
    return 0;
}
