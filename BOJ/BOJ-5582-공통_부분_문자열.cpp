#include<iostream>
#include<algorithm>

int ans, cache[4005][4005];
std::string inp1, inp2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> inp1 >> inp2;
    for(int i = 0; i < inp1.size(); ++i){
        for(int u = 0; u < inp2.size(); ++u){
            if(inp1[i] == inp2[u]){
                cache[i + 1][u + 1] = cache[i][u] + 1;
            }
        }
    }
    for(int i = 1; i <= inp1.size(); ++i)
    for(int u = 1; u <= inp2.size(); ++u)
        ans = (ans < cache[i][u]) ? cache[i][u] : ans;
    std::cout << ans;
    return 0;
}
