#include<iostream>
#include<cstring>

std::string input;
int N, cache[45];

int DP(int idx){
    if(idx == N) return 1;

    int &ret = cache[idx];
    if(ret != -1) return ret;

    ret = 0;
    int tmp = input[idx] - '0';
    if(tmp > 0)
        ret += DP(idx + 1);
    
    if(idx < N - 1 && tmp){
        tmp *= 10;
        tmp += input[idx + 1] - '0';
        if(tmp < 35)
            ret += DP(idx + 2);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> input;
    N = input.size();

    std::cout << DP(0);
}
