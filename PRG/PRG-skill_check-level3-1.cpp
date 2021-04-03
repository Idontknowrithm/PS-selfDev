#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long pac(int n){
    long long ret = 1;
    for(long long i = 1; i <= (long long)n; ++i) ret *= i;
    return ret;
}

vector<int> solution(int n, long long k) {
    vector<int> answer, tmp;

    for(int i = 1; i <= n; ++i)
        tmp.push_back(i);
    for(int i = 0; i < n - 1; ++i){
        long long div = (k - 1) / pac(n - i - 1);
        answer.push_back(tmp[div]);
        tmp.erase(tmp.begin() + (int)div);
        k = k - pac(n - i - 1) * div;
    }
    answer.push_back(tmp[0]);

    return answer;
}
