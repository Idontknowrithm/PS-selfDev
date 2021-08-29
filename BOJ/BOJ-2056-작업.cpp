#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

const int MAX = 10005;
int N, delay[MAX], cache[MAX];
std::vector<int> topol[MAX];

int DP(int node){
    if(!topol[node].size()) return delay[node];
    int &ret = cache[node];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < topol[node].size(); ++i){
        ret = std::max(ret, DP(topol[node][i]) + delay[node]);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        int M;
        scanf("%d %d", &delay[i], &M);
        for(int u = 0; u < M; ++u){
            int tmp;
            scanf("%d", &tmp);
            topol[i].push_back(tmp);
        }
    }
    memset(cache, -1, sizeof(cache));
    int ans = 0;
    for(int i = 1; i <= N; ++i)
        if(cache[i] == -1)
            ans = std::max(ans, DP(i));
    printf("%d", ans);
    return 0;
}
