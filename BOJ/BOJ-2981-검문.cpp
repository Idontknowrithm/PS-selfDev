#include<iostream>
#include<algorithm>
#include<vector>

int N, num[105], sub[105];
std::vector<int> ans;

int GCD(int a, int b){
    if(!a) return b;
    if(!b) return a;
    if(a < b) std::swap(a, b);
    return GCD(b, a % b);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &num[i]);
    std::sort(num, num + N);
    for(int i = 0; i < N - 1; ++i)
        sub[i] = num[i + 1] - num[i];
    int tmp_gcd = sub[0];
    for(int i = 1; i < N - 1; ++i){
        tmp_gcd = GCD(tmp_gcd, sub[i]);
    }
    for(int i = 2; i * i <= tmp_gcd; ++i)
        if(tmp_gcd % i == 0){
            ans.push_back(i);
            ans.push_back(tmp_gcd / i);
        }
    ans.push_back(tmp_gcd);
    std::sort(ans.begin(), ans.end());
    printf("%d ", ans[0]);
    for(int i = 1; i < ans.size(); ++i)
        if(ans[i] != ans[i - 1])
            printf("%d ", ans[i]);
    return 0;
}
