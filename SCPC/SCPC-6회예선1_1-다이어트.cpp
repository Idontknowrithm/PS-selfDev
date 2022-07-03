// 두 배열에서 하나씩 뽑아 더한 값이 최소가 되도록 -> 정렬 후 그리디

#include<iostream>
#include<algorithm>
#define ll long long

const ll MAX = 200005;
ll T, N, K, A[MAX], B[MAX];

int main() {
    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        scanf("%lld %lld", &N, &K);
        for(ll i = 0; i < N; ++i)
            scanf("%lld", &A[i]);
        for(ll i = 0; i < N; ++i)
            scanf("%lld", &B[i]);
        
        std::sort(A, A + N);
        std::sort(B, B + N);

        ll ans = 0;

        for(ll i = 0; i < K; ++i)
            ans = std::max(ans, A[i] + B[K - i - 1]);

        printf("Case #%lld\n%lld\n", z, ans);    
    }
    return 0;
}
