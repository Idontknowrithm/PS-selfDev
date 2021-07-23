#include<iostream>
#include<vector>

// calculate failure_func using partial matches which appear
// when they search themselves in N
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
// return all start positions where N(needle)s appear in H(hey stack)
std::vector<int> KMP(const std::string &H, const std::string &N){
    int n = H.size(), m = N.size();
    // failure_func: max len of str which can be both prefix and suffix of N[..i]
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
