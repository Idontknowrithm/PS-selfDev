#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<std::string, std::string>

int N;
std::vector<std::string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", 
                                 "Bella", "Blue", "Betsy", "Sue"};
std::vector<pp> pairs;

int main() {
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::string a, b;
        std::cin >> a;
        for(int u = 0; u < 5; ++u)
            std::cin >> b;
        pairs.push_back({a, b});        
    }
    std::sort(cows.begin(), cows.end());
    do{
        int possible_pairs = 0;
        for(int i = 0; i < pairs.size(); ++i){
            bool can = false;
            for(int u = 0; u < 7; ++u){
                if(cows[u] == pairs[i].first && cows[u + 1] == pairs[i].second)
                    can = true;
                if(cows[u + 1] == pairs[i].first && cows[u] == pairs[i].second)
                    can = true;
            }
            if(can)
                ++possible_pairs;
        }
        if(possible_pairs == pairs.size()){
            for(int i = 0; i < cows.size(); ++i)
                std::cout << cows[i] << "\n";
            return 0;
        }
    }while(std::next_permutation(cows.begin(), cows.end()));
    return 0;
}
