// 수의 범위 제한 세심하게 고려
// int형 제한이라도 그것들을 더할 경우가 있다면?

#include<iostream>
#include<algorithm>

const long long INF = 4000000000;
long long N, diff = INF, ans[3], liquid[5005];

int main() {
    scanf("%lld", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lld", &liquid[i]);
    std::sort(liquid, liquid + N);
    for(int i = 0; i < N; ++i){
        long long criteria = liquid[i];
        int ptr1 = ((!i) ? 1 : 0), ptr2 = ((i == N - 1) ? N - 2 : N - 1);
        while(ptr1 < ptr2){
            if(std::abs(criteria + liquid[ptr1] + liquid[ptr2]) < diff){
                diff = std::abs(criteria + liquid[ptr1] + liquid[ptr2]);
                ans[0] = criteria; ans[1] = liquid[ptr1]; ans[2] = liquid[ptr2];
            }
            if(criteria + liquid[ptr1] + liquid[ptr2] < 0){
                ptr1 += (ptr1 + 1 == i) ? 2 : 1;
            }
            else{
                ptr2 -= (ptr2 - 1 == i) ? 2 : 1;
            }
        }
    }
    if(ans[0] > ans[1]) std::swap(ans[0], ans[1]);
    if(ans[1] > ans[2]) std::swap(ans[1], ans[2]);
    if(ans[0] > ans[1]) std::swap(ans[0], ans[1]);
    printf("%lld %lld %lld", ans[0], ans[1], ans[2]);
    return 0;
}
