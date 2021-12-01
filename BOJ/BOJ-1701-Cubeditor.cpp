#include<iostream>
#include<algorithm>
#include<cstring>

int pi[5005];

void get_failure(const std::string &N, int start){
    int m = N.size();

    int begin = 1, matched = 0;

    while(begin + matched < m){
        if(N[begin + matched + start] == N[matched + start]){
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(!matched)
                ++begin;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}

int main() {
    int ans = 0;
    std::string input;
    std::cin >> input;
    for(int i = 0; i < input.size(); ++i){
        memset(pi, 0, sizeof(pi));
        get_failure(input, i);
        for(int u = 0; u < input.size() - i; ++u)
            ans = std::max(ans, pi[u]);
    }
    std::cout << ans;
    return 0;
}
