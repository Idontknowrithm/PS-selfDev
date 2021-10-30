// 변수 설정은 순서 등 헷갈리지 않게 하자

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

const int INF = 2147483647;
int cache[2][105][25];
std::string roll, bridge[2];

int DP(int R, int C, int idx){
    if(idx == roll.size() - 1) 
        return 1;

    int &ret = cache[R][C][idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = C + 1; i < bridge[0].size(); ++i){
        if(R == 1 && bridge[0][i] == roll[idx + 1])
            ret += DP(0, i, idx + 1);
        if(R == 0 && bridge[1][i] == roll[idx + 1])
            ret += DP(1, i, idx + 1);
    }
    return ret;
}

int main() {
    std::cin >> roll >> bridge[0] >> bridge[1];
    
    memset(cache, -1, sizeof(cache));
    int ans = 0;
    for(int i = 0; i < bridge[0].size(); ++i){
        if(bridge[0][i] == roll[0])
            ans += DP(0, i, 0);
        if(bridge[1][i] == roll[0])
            ans += DP(1, i, 0);
    }
    std::cout << ans;
    return 0;
}
