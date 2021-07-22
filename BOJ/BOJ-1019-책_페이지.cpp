// 특별한 알고리즘이 떠오르지 않는다면 작은 예제부터 하나씩
// 필기해가면서 일반적인 규칙 찾기

#include<iostream>
#define ll long long

ll N, digit = 1, start = 1, nums[15];

void calc(ll n, ll digit){
    while(n > 0){
        nums[n % 10] += digit;
        n /= 10;
    }
}

int main() {
    scanf("%lld", &N);
    while(start != N){
        while(start % 10 != 0 && start != N)
            calc(start++, digit);
        while(N % 10 != 9 && start != N)
            calc(N--, digit);
        if(start == N){
            calc(N, digit);
            break;
        }
        for(int i = 0; i < 10; ++i)
            nums[i] += (N / 10 - start / 10 + 1) * digit;
        digit *= 10;
        N /= 10; start /= 10;
    }
    if(N == 1) calc(N, digit);
    for(int i = 0; i < 10; ++i)
        printf("%lld ", nums[i]);
    return 0;
}
