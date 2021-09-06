#include<iostream>
#include<algorithm>
#include<cstring>

std::string a, b, c;
int cache[105][105][105];

int DP(int st, int nd, int rd){
    if(st < 0 || nd < 0 || rd < 0) return 0;
    int &ret = cache[st][nd][rd];
    if(ret != -1) return ret;
    ret = 0;
    if(a[st] == b[nd] && b[nd] == c[rd])
        ret = 1 + DP(st - 1, nd - 1, rd - 1);
    else{
        ret = std::max(ret, DP(st - 1, nd, rd));
        ret = std::max(ret, DP(st, nd - 1, rd));
        ret = std::max(ret, DP(st, nd, rd - 1));
        ret = std::max(ret, DP(st - 1, nd - 1, rd));
        ret = std::max(ret, DP(st, nd - 1, rd - 1));
        ret = std::max(ret, DP(st - 1, nd, rd - 1));
        ret = std::max(ret, DP(st - 1, nd - 1, rd - 1));
    }
    return ret;
}

int main() {
    std::cin >> a >> b >> c;
    memset(cache, -1, sizeof(cache));
    std::cout << DP(a.size() - 1, b.size() - 1, c.size() - 1);
    return 0;
}
