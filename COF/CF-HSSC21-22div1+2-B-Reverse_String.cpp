#include<iostream>

int N;
std::string input, res;

int main() {
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> input >> res;
        bool ans = false;
        for(int i = 0; i < input.size(); ++i){
            if(input[i] == res[0]){
                int tmp = i, tmpi = 0;
                while(i + tmpi < input.size() && tmpi < res.size() && input[i + tmpi] == res[tmpi])
                    ++tmpi;
                if(tmpi == res.size()){
                    ans = true;
                    break;
                }
                --tmpi;
                while()
            }
        }
        if(ans) std::cout << "YES\n";
        else    std::cout << "NO\n";
    }
    return 0;
}
