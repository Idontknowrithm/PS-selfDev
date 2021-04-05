#include<iostream>
#include<vector>

int T;
std::string str;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int z = 1; z <= T; ++z){
        std::cin >> str;
        if(str.size() == 1){
            std::cout << "Case #" << z << ": 1\n";
            continue;
        }
        std::vector<long long> times;
        times.push_back((str[0] == str[1]) ? 1 : 2);
        for(int i = 1; i < str.size() - 1; ++i){
            if(str[i] == str[i - 1] && str[i] == str[i + 1]) times.push_back(1);
            else if(str[i] == str[i - 1] || str[i - 1] == str[i + 1] || str[i + 1] == str[i]) times.push_back(2);
            else times.push_back(3);
        }
        times.push_back((str[str.size() - 1] == str[str.size() - 2]) ? 1 : 2);
        long long ans = 1;
        for(int i = 0; i < times.size(); ++i){
            ans *= times[i];
            ans %= 1000000007;
        }
        std::cout << "Case #" << z << ": " << ans << "\n";
    }
    return 0;
}
