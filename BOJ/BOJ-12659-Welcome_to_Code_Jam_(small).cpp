#include<iostream>
#include<string>

int N, codejam;
std::string input;
const std::string parsing = "welcome to code jam";

void exsearch(int start, int past_forward){ // (-1, 0) start
    if(start != -1 && past_forward == parsing.size() - 1 &&
       input[start] == parsing[parsing.size() - 1]){
        ++codejam;
        return;
    }
    for(int i = start + 1; i < input.size(); ++i){
        if(start == -1)
            exsearch(i, 0);
        else if(input[start] == parsing[past_forward] &&
                input[i] == parsing[past_forward + 1])
            exsearch(i, past_forward + 1);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    std::getline(std::cin, input);
    for(int z = 1; z <= N; ++z){
        std::getline(std::cin, input);
        codejam = 0;
        exsearch(-1, 0);
        codejam %= 10000;
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
