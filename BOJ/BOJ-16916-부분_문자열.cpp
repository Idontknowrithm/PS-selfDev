#include<iostream>
#include<vector>

std::vector<int> get_failure(const std::string &N){
    int m = N.size();
    std::vector<int> failure_func(m, 0);

    int begin = 1, matched = 0;

    while(begin + matched < m){
        if(N[begin + matched] == N[matched]){
            ++matched;
            failure_func[begin + matched - 1] = matched;
        }
        else{
            if(!matched)
                ++begin;
            else{
                begin += matched - failure_func[matched - 1];
                matched = failure_func[matched - 1];
            }
        }
    }
    return failure_func;
}
std::vector<int> KMP(const std::string &H, const std::string &N){
    int n = H.size(), m = N.size();
    std::vector<int> ret, failure_func = get_failure(N);

    int begin = 0, matched = 0;
    while(begin <= n - m){
        if(matched < m && H[begin + matched] == N[matched]){
            ++matched;
            if(matched == m) ret.push_back(begin);
        }
        else{
            if(matched == 0)
                ++begin;
            else{
                begin += matched - failure_func[matched - 1];
                matched = failure_func[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    std::string input_H, input_N;
    std::vector<int> pi, ans;
    std::cin >> input_H >> input_N;
    pi = get_failure(input_H);
    ans = KMP(input_H, input_N);
    if(ans.size() > 0)
        std::cout << "1";
    else 
        std::cout << "0";
    
    return 0;
}
