#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> sorted;
    for(int i = 0; i < strings.size(); ++i){
        sorted.push_back({strings[i][n], strings[i]});
    }
    sort(sorted.begin(), sorted.end());
    
    for(int i = 0; i < sorted.size(); ++i){
        answer.push_back(sorted[i].second);
    }
    return answer;
}
