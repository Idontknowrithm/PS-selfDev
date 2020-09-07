// normal wrong

#include<iostream>
#include<string>
#include<queue>

typedef struct{
    int num;
    std::string str;
}data;

int N;
std::string inp;
bool dprime(std::string s){
    int num = std::stoi(s);
    if(num % 2 == 0 ||
       num % 3 == 0 ||
       num % 5 == 0 ||
       num % 7 == 0
    )
        return true;
    return false;
}
int find(){
    if (inp.size() == 1 && dprime(inp))
        return 1;
    else if(inp.size() == 1)
        return 0;

    std::string x = "";   x += inp[0];
    std::queue<data> bfs; int ans = 0;
    bfs.push({1, x});
    
    while(!bfs.empty()){
        std::string tmp = "", s = bfs.front().str;
        int n = bfs.front().num;
        bfs.pop();
        
        if(n == inp.size()){
            if(dprime(s))
                ++ans;
            continue;
        }
        if(n < inp.size()){
            tmp = s; tmp += inp[n];
            bfs.push({n + 1, tmp});

            char a = inp[n];
            tmp = std::to_string(std::stoi(s) + (a - '0'));
            bfs.push({n + 1, tmp});

            tmp = std::to_string(std::stoi(s) - (a - '0'));
            bfs.push({n + 1, tmp});
        }
    }

    return ans;
}

int main () {
    std::cin >> N;
    for(int z = 1; z <= N; ++z){
        std::cin >> inp;

        std::cout << "Case #" << z << ": " << find() << "\n";
    }
}
