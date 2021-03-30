#include <string>
#include <vector>

using namespace std;

typedef struct{
    int len;
    string name, contents;
}music;

string parser(int start, int end, string src){ // [start, end)
    string ret = "";
    for(int i = start; i < end; ++i)
        ret += src[i];
    return ret;
}
int lparser(string src){
    int h = stoi(src.substr(6, 2)) - stoi(src.substr(0, 2));
    int m = stoi(src.substr(9, 2)) - stoi(src.substr(3, 2));
    return h * 60 + m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    music list[105];
    int list_size = 0;
    for(int i = 0; i < musicinfos.size(); ++i){
        int ptr;
        list[i].len = lparser(musicinfos[i]);
        ptr = musicinfos[i].find(",", 12);
        list[i].name = parser(12, ptr, musicinfos[i]);
        list[i].contents = musicinfos[i].substr(ptr + 1);
        ++list_size;
    }
    for(int i = 0; i < list_size; ++i){
        string tmp = list[i].contents;
        list[i].contents = "";
        for(int u = 0; u < list[i].len / tmp.size(); ++u){
            list[i].contents += tmp;
        }
        list[i].contents += tmp.substr(0, list[i].len % tmp.size());
    }
    for(int i = 0; i < list_size; ++i){
        if(list[i].contents.find(m, 0) != string::npos) answer = list[i].name;
    }
    
    return answer;
}
