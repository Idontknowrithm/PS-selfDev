// 문제 조건 잘 보자.. ㅠㅠ
// 가능하지 않을 때 -1 출력하는 걸 간과해버렸다

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define pp std::pair<int, int>

const int INF = 1000000;
int N, cache[55];
std::string str, words[55], sorted_words[55], sorted_matrix[55][55];

std::string str_sort(std::string arg){
    for(int i = 0; i < arg.size() - 1; ++i)
    for(int u = i; u < arg.size() - 1; ++u)
        if(arg[u] > arg[u + 1]){
            char t;
            t = arg[u + 1]; arg[u + 1] = arg[u]; arg[u] = t;
        }
    return arg;
}

int cost(int start, int word_idx){
    int word_size = words[word_idx].size();
    
    if(start + word_size > str.size()) return INF;
    // std::cout << "cost: 1-> " << sorted_words[word_idx] << " 2-> " << sorted_matrix[start][start + word_size] << std::endl;
    if(sorted_words[word_idx] != sorted_matrix[start][start + word_size]) return INF;
    int ret = 0;
    for(int i = 0; i < word_size; ++i)
        if(words[word_idx][i] != str[start + i])
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
        ret = std::min(ret, DP(start + words[i].size()) + cost(start, i));
    return ret;
}

int main() {
    std::string tmp;
    memset(cache, -1, sizeof(cache));
    std::cin >> str >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> words[i];
        tmp = words[i];
        std::sort(tmp.begin(), tmp.end());
        sorted_words[i] = tmp;
    }
    int str_N = str.size();
    for(int i = 0; i < str_N; ++i)
    for(int u = i + 1; u <= str_N; ++u){
        tmp = "";
        for(int k = i; k < u; ++k)
            tmp += str[k];
        std::sort(tmp.begin(), tmp.end());
        sorted_matrix[i][u] = tmp;
    }
    int ans = DP(0);
    if(ans == INF)
        std::cout << -1 << std::endl;
    else
        std::cout << ans << std::endl;
    return 0;
}
