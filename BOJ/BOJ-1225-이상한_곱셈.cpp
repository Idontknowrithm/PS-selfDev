#include<iostream>

std::string a, b;
int ans, A[10005], B[10005];

int main() {
    std::cin >> a >> b;
    for(int i = 0; i < a.size(); ++i)
        A[i] = a[i] - '0';
    for(int i = 0; i < b.size(); ++i)
        B[i] = b[i] - '0';
    for(int i = 0; i < a.size(); ++i)
    for(int i = 0; i < b.size(); ++i)
        ans += A[i] * B[i];
    
    std::cout << ans;
    return 0;
}
