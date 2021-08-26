#include<iostream>
#include<cstdlib>
#include<cstring>

int INF = 10000000;
int N, M, d1, d2, doors[25], cache[25][25][25];

int DP(int one, int two, int idx){
    if(idx == M) return 0;

    int &ret = cache[one][two][idx];
    if(ret != -1) return ret;
    ret = INF;
    if(doors[idx] <= one)
        ret = std::min(ret, DP(doors[idx], two, idx + 1) + (one - doors[idx]));
    else if(one < doors[idx] && doors[idx] < two){
        ret = std::min(ret, DP(doors[idx], two, idx + 1) + (doors[idx] - one));
        ret = std::min(ret, DP(one, doors[idx], idx + 1) + (two - doors[idx]));
    }
    else 
        ret = std::min(ret, DP(one, doors[idx], idx + 1) + (doors[idx] - two));
    return ret;
}

int main(){
    scanf("%d\n%d %d\n%d", &N, &d1, &d2, &M);
    for(int i = 0; i < M; ++i)
        scanf("%d", &doors[i]);
    memset(cache, -1, sizeof(cache));
    printf("%d", DP(d1, d2, 0));
    return 0;
}
