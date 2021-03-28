#include<iostream>

int N;
bool possible;
std::string input;

int parser_100_1_(int start){
    int i, zero = 0, one = 0;
    for(i = start + 1; i < input.size() && input[i] == '0'; ++i) ++zero;
    if(i == input.size() || zero < 2) return -1; // impossible
    for(; i < input.size() && input[i] == '1'; ++i) ++one;
    if(i == input.size()) return -2; // possible
    return i - 1;
}

void exsearch(int start){
    if(start == input.size()){possible = true; return;}
    int parser_ret;
    if(input[start] == '0'){
        if(start + 1 < input.size() && input[start + 1] == '1')
            exsearch(start + 2);
        else if(start + 1 < input.size())
            return;
    }
    else if(input[start] == '1'){
        parser_ret = parser_100_1_(start);
        if(parser_ret == -1) return;
        else if(parser_ret == -2){possible = true; return;}

        if(input[parser_ret - 1] == '1')
            exsearch(parser_ret);
        exsearch(parser_ret + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        possible = false;
        exsearch(0);
        std::cout << ((possible) ? "YES" : "NO") << "\n";
    }
    return 0;
}
