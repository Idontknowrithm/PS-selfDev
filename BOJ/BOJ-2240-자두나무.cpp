#include<iostream>
#include<algorithm>
#include<cstring>

int T, W, plum[1005], cache[1005][35][2];

int DP(int sec, int move, int cur){
    if(sec == T) return 0;

    int &ret = cache[sec][move][cur];
    if(ret != -1) return ret;

    if(cur == plum[sec])
        ret = std::max(ret, DP(sec + 1, move, cur) + 1);
    else 
        ret = std::max(ret, DP(sec + 1, move, cur));
    
    if(move){
        cur = (cur == 1) ? 2 : 1;
        if(cur == plum[sec])
            ret = std::max(ret, DP(sec + 1, move - 1, cur) + 1);
        else 
            ret = std::max(ret, DP(sec + 1, move - 1, cur));        
    }
    return ret;
}

int main() {
    scanf("%d %d", &T, &W);
    for(int i = 0; i < T; ++i)
        scanf("%d", &plum[i]);
    
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(0, W, 1));
    return 0;
}
