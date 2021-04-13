#include<iostream>
#include<vector>

std::string input;
std::vector<int> sat;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while(1){
        std::cin >> input;
        if(input[0] == '0' && input.size() == 1) return 0;
        else{
            for(int i = 1; i < input.size(); ++i){
                int nested = 0;
                for(int u = 0; u < sat.size(); ++u){
                    if(i % sat[u] == 0) ++nested;
                }
                if(((nested & 1) && input[i] == '0') ||
                    !(nested & 1) && input[i] == '1'){
                    sat.push_back(i);
                }
            }
            for(int i = 0; i < sat.size(); ++i)
                std::cout << sat[i] << " ";
                std::cout << "\n";
        }
        sat.clear();
    }
}
