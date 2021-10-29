#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

const int INF = 2147483647;
int cache[105][2][25];
std::vector<int> roll, bridge[2];

int interpreter(char a){
    if(a == 'R') return 1;
    if(a == 'I') return 2;
    if(a == 'N') return 3;
    if(a == 'G') return 4;
    if(a == 'S') return 5;
}

int DP(int C, int R, int idx){
    std::cout << C << " " << R << " " << idx << "\n";
    if(idx == roll.size() - 1) 
        return 1;

    int &ret = cache[C][R][idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = C + 1; i < bridge[0].size(); ++i){
        if(bridge[0][i] == roll[idx + 1])
            ret += DP(i, 0, idx + 1);
        if(bridge[1][i] == roll[idx + 1])
            ret += DP(i, 1, idx + 1);
    }
    return ret;
}

int main() {
    std::string input;
    std::cin >> input;
    for(int i = 0; i < input.size(); ++i)
        roll.push_back(interpreter(input[i]));
    std::cin >> input;
    for(int i = 0; i < input.size(); ++i)
        bridge[0].push_back(interpreter(input[i]));
    std::cin >> input;
    for(int i = 0; i < input.size(); ++i)
        bridge[1].push_back(interpreter(input[i]));
    
    memset(cache, -1, sizeof(cache));
    int ans = -1;
    for(int i = 0; i < bridge[0].size(); ++i){
        if(bridge[0][i] == roll[0])
            ans = std::max(ans, DP(i, 0, 0));
        if(bridge[1][i] == roll[0])
            ans = std::max(ans, DP(i, 1, 0));
    }
    std::cout << ans;
    return 0;
}
