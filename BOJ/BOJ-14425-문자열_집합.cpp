#include<iostream>
#include<set>

std::set<std::string> str_set;
int N, M, ans;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        std::string input;
        std::cin >> input;
        str_set.insert(input);
    }
    for(int i = 0; i < M; ++i){
        std::string input;
        std::cin >> input;
        if(str_set.find(input) != str_set.end())
            ++ans;
    }
    std::cout << ans;
    return 0;
}
