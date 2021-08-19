#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define pp std::pair<int, int>

const int INF = 10000000;
int N, cache[55];
std::string str, words[55];

int cost(int start, std::string word){
    int ret = 0;
    for(int i = 0; i < word.size(); ++i)
        if(word[i] != str[start + i])
            ++ret;
    return ret;
}
int DP(int start){
    if(start == str.size()) return 0;
    else if(start > str.size()) return INF;

    int &ret = cache[start];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < N; ++i)
        ret = std::min(ret, DP(start + words[i].size()) + cost(start, words[i]));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    std::cin >> str >> N;
    for(int i = 0; i < N; ++i)
        std::cin >> words[i];
    std::cout << DP(0);
    return 0;
}
