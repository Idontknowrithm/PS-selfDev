// 알고리즘 설계는 맞았는데 초기화값 문제 때문에 해멘 문제
// 처음에는 INF 값과 DP 함수의 예외 처리값을 큰 생각없이 
// lower bound보다 낮은 값을 사용했는데 시간 초과가 났다
// 일단 INF를 최대로 하고 DP 함수의 예외 처리값을 그보다 낮지만
// lower bound보다는 작은 값을 사용해서 통과했는데 이에 대한
// 정확한 문제는 정확히는 모르겠다
// 일단 추측으로는 캐시가 INF값이 아니면 캐시 값을 그대로 반환하도록
// 했는데, 이 INF값과 예외 처리값에 혼란이 오게되면 캐시 값을 그대로
// 반환해야하는 경우에도 그러지 않고 아래의 코드를 실행하게 되어 여기에서
// 시간 초과가 발생한 것으로 예상된다


#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long

const ll INF = 999999999;
ll N, M, input[105], cache[105][105][2];

ll DP(ll idx, ll cnt, ll swch){
    if(cnt > M) return -32768 * 100;
    if(idx >= N){
        if(swch && cnt == M - 1)
            return 0;
        if(!swch && cnt == M)
            return 0;
        return -32768 * 100;
    }
    ll &ret = cache[idx][cnt][swch];
    if(ret != -INF) return ret;

    ret = std::max(ret, DP(idx + 1, cnt, 1) + input[idx]);
    if(swch)
        ret = std::max(ret, DP(idx + 1, cnt + 1, 0));
    else
        ret = std::max(ret, DP(idx + 1, cnt, 0));
    
    return ret;
}

int main() {
    for(int i = 0; i < 105; ++i)
    for(int u = 0; u < 105; ++u){
        cache[i][u][0] = -INF;
        cache[i][u][1] = -INF;
    }
    scanf("%lld %lld", &N, &M);
    for(ll i = 0; i < N; ++i)
        scanf("%lld", &input[i]);
    printf("%lld", DP(0, 0, 0));

    return 0;
}
