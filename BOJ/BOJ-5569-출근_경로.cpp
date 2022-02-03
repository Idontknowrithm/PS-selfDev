#include<iostream>
#include<cstring>

const int MOD = 100000;
int W, H, cache[105][105][2][2];

int DP(int r, int c, int dir, int change){
    if(r == W || c == H) 
        return 0;
    if(r == W - 1 && c == H - 1)
        return 1;
    
    int &ret = cache[r][c][dir][change];
    if(ret != -1) return ret;

    ret = 0;
    if(dir == 1){
        if(change != 1)
            ret += DP(r, c + 1, 2, 1);
        ret += DP(r + 1, c, 1, 0);
        ret %= MOD;
    }
    else{
        if(change != 1)
            ret += DP(r + 1, c, 1, 1);
        ret += DP(r, c + 1, 2, 0);
        ret %= MOD;
    }
    return ret % MOD;
}

int main() {
    memset(cache, -1, sizeof(cache));

    scanf("%d %d", &W, &H);
    printf("%d", (DP(1, 0, 1, 0) + DP(0, 1, 2, 0)) % MOD);
    return 0;
}
