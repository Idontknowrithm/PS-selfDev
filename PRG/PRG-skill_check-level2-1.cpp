#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numparser(int start, int end, string src){ //[start, end)
    string tmp = "";
    for(int i = start; i < end; ++i) tmp += src[i];
    return tmp;
}

string solution(string s) {
    string answer = "";
    vector<int> arr;
    int prev_ptr =0, ptr = s.find(" ", 0);
    while(ptr != string::npos){
        string num = numparser(prev_ptr, ptr, s);
        arr.push_back(stoi(num));
        prev_ptr = ptr + 1;
        ptr = s.find(" ", prev_ptr);
    }
    string num = numparser(prev_ptr, s.size(), s);
    arr.push_back(stoi(num));
    int min = 2147483647, max = -2147483648;
    for(int i = 0; i < arr.size(); ++i){
        min = (min > arr[i]) ? arr[i] : min;
        max = (max < arr[i]) ? arr[i] : max;
    }
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}
