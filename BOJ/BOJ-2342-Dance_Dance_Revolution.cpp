#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>
#define itpr interpreter

const int INF = 400005;
int N, cache[100005][40];
std::vector<int> instruct;

int itpr(pp i){
    return i.first * 10 + i.second;
}

int DP(pp status, int inst){
    if(inst == N) return 0;
    pp tmp;
    int &ret = cache[itpr(status)][inst];
    if(ret) return ret;

    ret = INF;
    if(status.first < instruct[inst])
        tmp = {status.first, instruct[inst]};
    else 
        tmp = {instruct[inst], status.first};
}

int main() {
    int input = -1;
    scanf("%d", &input);
    while(input){
        instruct.push_back(input);
        scanf("%d", &input);
    }
    N = instruct.size();
    printf("%d", DP({0, 0}, 0));
    return 0;
}
