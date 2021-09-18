// 점화식을 생각해내지 못한 문제
// 문제에서 주어진 조건만 보면 어디서부터, 어떻게 쌓아가야하는지에 대한
// 아이디어를 떠올리기 힘듦
// DP라고 생각되는 문제를 보았을 때는 N에 대해서, N이 1일 때부터 쌓여가는 모양,
// N일 때부터 내려가는 모양, 또는 N - 1에서 N으로 갈 때 어떻게 되는 지에 대해서
// 먼저 관찰을 해야함
// 여기서는 N - 1에서 N으로 갈 때에 대해 관찰했으면 풀렸을 문제
// 빌딩을 높은 순으로 놓는다고 생각했을 때, 
// i - 1에서 i로 갈 때 현재 놓여진 모든 빌딩보다 작은 빌딩을 놓을 것이고,
// 이때 가장 왼쪽에 놓아서 L을 증가시키거나, 가장 오른쪽에 놓아서 R을 증가시키거나,
// 혹은 중간 즈음에 놓아서 L과 R 둘 다 건드리지 않는 경우, 이 세 경우가 합쳐져 i 경우를 만듬
// -> n, l, r = n-1,l-1,r + n-1,l,r-1 + (n-1,l,r)*(n-2)

#include<iostream>
#include<cstring>
#define ll long long

const ll MAX = 105, MOD = 1000000007;
ll N, L, R, buildings[MAX], cache[MAX][MAX][MAX];

ll DP(ll n, ll l, ll r){
    if(!l || !r || !n || l + r > n + 1) return 0;
    ll &ret = cache[n][l][r];
    if(ret != -1) return ret;
    ret = 0;
    ret = DP(n - 1, l - 1, r) + DP(n - 1, l, r - 1) + (DP(n - 1, l, r) * (n - 2)) % MOD;
    ret %= MOD;
    return ret;
}

int main() {
    scanf("%lld %lld %lld", &N, &L, &R);
    memset(cache, -1, sizeof(cache));
    cache[1][1][1] = 1;
    printf("%lld", DP(N, L, R));
    return 0;
}
