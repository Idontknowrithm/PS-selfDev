#include<iostream>
#include<algorithm>
#include<set>
#define INF 2147483647

int T, cache[10005];
std::string input;

int valcalc(int start, int len){
    std::set<int> diff;
    for(int i = 0; i < len - 1; ++i){
        diff.insert(input.at(start + i + 1) - input.at(start + i));
    }
    if(diff.size() == 1 && diff.find(0)  != diff.end()) return 1;
    if(diff.size() == 1 && diff.find(1)  != diff.end()) return 2;
    if(diff.size() == 1 && diff.find(-1) != diff.end()) return 2;
    if(diff.size() == 1)                                return 5;
    if(len == 3 && input[start] == input[start + 2])    return 4;
    if(len == 4 && input[start] == input[start + 2] &&
                   input[start + 1] == input[start + 3])return 4;
    if(len == 5 && input[start] == input[start + 2] &&
                   input[start + 1] == input[start + 3] &&
                   input[start + 2] == input[start + 4])return 4;
                                                        return 10;     
}
int mindiff(int start){
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = INF;
    if(input.size() - (start + 3) > 2){
        std::cout << input.size() - (start + 3) << "111" << std::endl;
        ret = std::min(ret, valcalc(start, 3) + mindiff(start + 3));
    }
    if(input.size() - (start + 4) > 2){
        std::cout << input.size() - (start + 4) << "222" << std::endl;
        ret = std::min(ret, valcalc(start, 4) + mindiff(start + 4));
    }
    if(input.size() - (start + 5) > 2){
        std::cout << int(input.size()) - (start + 5) << "333" << std::endl;
        // 여기서 왜 -1이 나오지..? (일단 size_t가 unsigned라는 점 간과)
        ret = std::min(ret, valcalc(start, 5) + mindiff(start + 5));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(std::cin >> T; T > 0; --T){
        std::cin >> input;
        for(int i = 0; i < 10005; ++i)
            cache[i] = -1;
        std::cout << mindiff(0) << "\n";
    }
    return 0;
}
