// 아이디어 떠올리지 못했음
// 소수 -> 0.xx를 곱하면 더 줄어듦.
// 이를 이용해서 -> 0번째 부터 곱해가면서 젤 큰건 저장해놓으면서 쭉 가다가
// 곱해나가는 수가 0.xx가 되면 1로 바꾸고 거기서부터 다시 시작하기:
//   ㄴ 어차피 0.xx를 곱하면 줄어드니까 이를 없애고 다시 시작하는게 최대를 구할 수 있는 길
// 문제 자체에서 파악할 수 있는 특성을 빠르게 이해해야 함
// 문제 자체에서만 있는 특성들을 빠르게 파악하고, 이를 이용할 수 있는
// 알고리즘을 빠르게 떠올려 보는 것을 연습하면 좋을 듯


#include<iostream>

int main() {
    int N; bool overOne = false;
    double cache, ans = 0, dp[10005];

    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%lf", &dp[i]);
        overOne = (dp[i] < 1) ? overOne : true;
    }
    if(!overOne){
        double max = 0;
        for(int i = 0; i < N; ++i)
            max = (max < dp[i]) ? dp[i] : max;
        printf("%.3lf", max);
        return 0;
    }
    ans = cache = (dp[0] < 1) ? 1 : dp[0];
    for(int i = 1; i < N; ++i){
        cache = (cache * dp[i] < 1) ? 1 : cache * dp[i];
        ans = (cache > ans) ? cache : ans;
    }

    printf("%.3lf", ans);
    return 0;
}
