처음 생각했던 방법은 받은 수들을 정렬하고, 초점을 바늘로 맞추는 것이 
아니라 바늘 사이의 간격으로 맞춰 문제를 해결하고자 했었음
이렇게 했을 때 두 시계에 대해서 비슷한 형태의 데이터가 나오게 되었고, 그럼 무엇이
KMP 사용 포인트인지 알기가 어려웠음
블로그에 해답을 얻은 결과, 두 문자열을 만들고, 36만개의 0으로 문자열을 채움
그 다음 입력받은 바늘 위치를 문자열에서 1로 채움
그리고 하나의 시계에 대해서 문자열을 += 해줌 -> 이것이 탐색 될 문자열
다른 하나의 시계를 두 배가 된 시계에서 찾음
시계 문자열을 두 배 해준 이유는 시계는 환형 데이터기 때문에 359999 이후에는 0이 됨
이 점을 해결하기 위해 문자열을 두 배 해준 후, 다른 문자열을 두 배가 된 문자열에서 
탐색해보는 

#include<iostream>
#include<algorithm>
#include<vector>

const int CLK = 360000;
int N;
std::string clock1 = "", clock2 = "";

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

int main() {
    int input;
    std::vector<int> ans;

    for(int i = 0; i < CLK; ++i){
        clock1 += '0';
        clock2 += '0';
    }
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        clock1[input] = '1';
    }
    for(int i = 0; i < N; ++i){
        std::cin >> input;
        clock2[input] = '1';
    }
    clock1 += clock1;
    
    ans = KMP(clock1, clock2);
    if(ans.size() == 0)
        std::cout << "impossible";
    else 
        std::cout << "possible";

    return 0;
}
