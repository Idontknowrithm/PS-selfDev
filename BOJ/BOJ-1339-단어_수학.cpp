#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>

int N, ans, alpha[30];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::string input;
        std::cin >> input;

        for(int u = input.size() - 1, digit = 1; u >= 0; --u, digit *= 10)
            alpha[input[u] - 'A'] += digit;
    }
    std::vector<pp> sorter;
    for(int i = 0; i < 26; ++i)
        sorter.push_back({alpha[i], i});

    std::sort(sorter.begin(), sorter.end(), std::greater<pp>());

    for(int i = 0; i < 10; ++i)
        ans += sorter[i].first * (9 - i);
    
    std::cout << ans;
    return 0;
}
