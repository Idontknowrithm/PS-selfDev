// abcbe
// abcba
// 이렇게 두 방향으로 답이 갈릴 수 있는 테케를 생각 못함

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
                int tmpi = 0;
                while(i + tmpi < input.size() && tmpi < res.size() && input[i + tmpi] == res[tmpi]){
                    ++tmpi;
                    if(tmpi == res.size()){
                        ans = true;
                        break;
                    }  
                    int origin = i + tmpi - 2, repl = tmpi;
                    while(origin >= 0 && repl < res.size() && input[origin] == res[repl]){
                        --origin; ++repl;
                    }
                    if(repl == res.size()){
                        ans = true;
                        break;
                    }
                }
                if(ans) break;
            }
        }
        if(ans) std::cout << "YES\n";
        else    std::cout << "NO\n";
    }
    return 0;
}
