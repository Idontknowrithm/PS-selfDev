// cache를 -1로 초기화 하는게 조금 더 안전할 듯..
// cache에서 0 자체가 다시 쓰이는 경우도 있어서

#include<iostream>
#include<string>
#include<cstring>

int N, codejam, cache[505][30];
std::string input;
const std::string parsing = "welcome to code jam";

int exsearch(int start, int past_forward){ // (-1, 0) start
    if(start != -1 && past_forward == parsing.size() - 1 &&
       input[start] == parsing[parsing.size() - 1]){
        return 1;
    }
    int &ret = cache[start + 1][past_forward];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = start + 1; i < input.size(); ++i){
        if(start == -1)
            ret += exsearch(i, 0);
        else if(input[start] == parsing[past_forward] &&
                input[i] == parsing[past_forward + 1])
            ret += exsearch(i, past_forward + 1);
        ret %= 10000;
    }
    return ret;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    std::getline(std::cin, input);
    for(int z = 1; z <= N; ++z){
        std::getline(std::cin, input);
        codejam = 0;
        memset(cache, -1, sizeof(cache));
        codejam = exsearch(-1, 0);
        if(codejam / 1000 != 0)
            std::cout << "Case #" << z << ": " << codejam << "\n";
        else if(codejam / 100 != 0)
            std::cout << "Case #" << z << ": " << "0" << codejam << "\n";
        else if(codejam / 10 != 0)
            std::cout << "Case #" << z << ": " << "00" << codejam << "\n";
        else 
            std::cout << "Case #" << z << ": " << "000" << codejam << "\n";
    }
    return 0;
}
