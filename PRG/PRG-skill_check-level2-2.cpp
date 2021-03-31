#include <string>
#include <vector>

using namespace std;

int intlen(int a){
    int tmp = 0; ++a;
    if(a == 1) return 0;
    while(a != 0){
        a /= 10;
        ++tmp;
    }
    return tmp;
}

int solution(string s) {
    int answer = 1000000;
    if(s.size() == 1) return 1;
    for(int i = 1; i <= s.size() / 2; ++i){
        string tmp;
        int ptr = 0, again = 0, zipped_size = 0;
        tmp = s.substr(ptr, i);
        while(ptr < s.size()){
            ptr += i;
            if(ptr + i >= s.size()){
                if(tmp == s.substr(ptr)){
                    again++;
                    zipped_size += intlen(again) + tmp.size();
                }
                else{
                    zipped_size += intlen(again) + tmp.size();
                    zipped_size += s.substr(ptr).size();
                }
                break;
            }
            else{
                if(tmp == s.substr(ptr, i)){
                    again++;
                }
                else{
                    zipped_size += intlen(again) + tmp.size();
                    again = 0;
                    tmp = s.substr(ptr, i);
                }    
            }
        }
        answer = (answer > zipped_size) ? zipped_size : answer;
    }
    return answer;
}
