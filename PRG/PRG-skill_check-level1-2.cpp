#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, int> &a, pair<double, int> &b){
    if(a.first == b.first) return a.second < b.second;
    else                   return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int stages_cleared[505] = {0,}, stages_not_cleared[505] = {0,};
    pair<double, int> fail_rate[505];
    // fail rate : notcl / cl;
    
    for(int i = 0; i < stages.size(); ++i){
        int player = stages[i];
        for(int u = 1; u <= player; ++u){
            stages_cleared[u] += 1;
        }
        stages_not_cleared[player] += 1;
    }
    for(int i = 0; i < N; ++i){
        if(stages_cleared[i + 1] == 0)
            fail_rate[i] = {-1, i + 1};
        else
            fail_rate[i] = {(double)stages_not_cleared[i + 1] / (double)stages_cleared[i + 1], i + 1};
    }
    std::sort(fail_rate, fail_rate + N, cmp);
    for(int i = 0; i < N; ++i){
        answer.push_back(fail_rate[i].second);
    }
    return answer;
}
