// 그냥 수학 문제. i, j 쌍과 주어지는 배열 값에 대해 i*j-k(a_i|a_j)의 최대값 찾기
// 먼저 값의 크기에 대해서 i*j는 값 복잡도가 O(n^2)이고, k(a_i|a_j)의 값 복잡도는
// O(100*n), 왜냐하면 k <= 100이고, a_i|a_j의 최대 크기는 2n이기 때문
// 일단 i*j 크기가 조금 더 영향력 있다는 것을 알 수 있음
// 문제 조건에 따라 i < j이기 때문에 i 혹은 j의 범위 제한을 찾으면 시간복잡도를 줄일 수 있음
// 여기서 정답 조건에서 i가 가질 수 있는 최소값을 찾아보자
// 먼저 i를 인자로 가지면서 가장 큰 함수값을 가질 수 있는 f의 경우는
// 인자를 i, n으로 가지고, a_i = 0, a_n = 0일 때 f가 가장 크다
// 이때 f(i,n) = i*n - k*0 = i*n
// 그리고 f 자체에서 가장 큰 값을 가질 수 있는 경우는 인자가 n, n - 1일 때인데, 
// 이때 가장 작을 수 있는 경우는 a_n|a_n-1 = 2n일 경우임
// f(n-1,n) = n(n-1) - k(2n) = n^2 - n - 2kn
// 여기서 f(i,n) > f(n-1,n), 즉 i*n > n^2 - n - 2kn -> i > n - 1 - 2k
// 따라서 i는 n - 2k 미만일 때 절대 최대값을 가질 수 없다.
// 이렇게 f(i,n)과 f(n-1,n)을 비교한 이유는,
// i를 최소로 가지는 인자가 운이 좋아 최대값을 가질 때와
// f가 가질 수 있는 최대값에서 운이 나빠 최소값을 가지는 경우를 비교한 것
// 따라서 i가 n-2k 미만일 때는 최대값을 가지는 f(n-1,n)에서 운이 나빠서
// n^2 - n - 2kn가 됨에도 불구하고 이보다 더 클 수 없기 때문에, 다시말해
// absolutely 최대값이 될 수 없기 때문에 탐색할 필요가 없다는 것

#include<iostream>
#include<algorithm>
#define ll long long
 
ll T, N, K, ans, input[100005];
 
int main() {
    for(scanf("%lld", &T); T > 0; --T){
        ans = -2000000005;
        scanf("%lld %lld", &N, &K);
        for(ll i = 1; i <= N; ++i)
            scanf("%lld", &input[i]);
        ll bound = N - 2 * K - 5;
        bound = (bound <= 0) ? 1 : bound;
        for(ll i = bound; i < N; ++i)
        for(ll u = i + 1; u <= N; ++u)
            ans = std::max(ans, i * u - K * (input[i] | input[u]));
        
        printf("%lld\n", ans);
    }
    return 0;
}
