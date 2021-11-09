#include<iostream>
#define ll long long

std::string a, b;
ll ans, A[10005], B[10005];

int main() {
    std::cin >> a >> b;
    for(ll i = 0; i < a.size(); ++i)
        A[i] = a[i] - '0';
    for(ll i = 0; i < b.size(); ++i)
        B[i] = b[i] - '0';
    for(ll i = 0; i < a.size(); ++i)
    for(ll u = 0; u < b.size(); ++u)
        ans += A[i] * B[u];
    
    std::cout << ans;
    return 0;
}
