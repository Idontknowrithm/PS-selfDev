#include<iostream>
#include<string>

int ansr, ansc, ans, cache[1005][1005];
std::string input1, input2, str_cache[1005][1005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> input1 >> input2;
    for(int i = 0; i < 1005; ++i)
        str_cache[0][i] = str_cache[i][0] = "";
    for(int i = 1; i <= input1.size(); ++i){
        for(int u = 1; u <= input2.size(); ++u){
            if(input1[i - 1] == input2[u - 1]){
                cache[i][u] = cache[i - 1][u - 1] + 1;
                str_cache[i][u] = str_cache[i - 1][u - 1];
                str_cache[i][u].push_back(input1[i - 1]);
            }
            else{
                if(cache[i - 1][u] < cache[i][u - 1]){
                    cache[i][u] = cache[i][u - 1];
                    str_cache[i][u] = str_cache[i][u - 1];
                }
                else{
                    cache[i][u] = cache[i - 1][u];
                    str_cache[i][u] = str_cache[i - 1][u];
                }
            }
        }
    }
    for(int i = 1; i <= input1.size(); ++i)
    for(int u = 1; u <= input2.size(); ++u){
        if(cache[i][u] > ans){
            ans = cache[i][u];
            ansr = i; ansc = u;
        }
    }
    std::cout << ans << "\n";
    std::cout << str_cache[ansr][ansc];
    return 0;
}
