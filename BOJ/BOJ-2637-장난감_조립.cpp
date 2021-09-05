#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

int N, M, cache[105][105];
std::vector<pp> graph[105];
std::vector<int> basic;

int DP(int idx, int b){
    if(graph[idx].size() == 0) 
        return (idx == b) ? 1 : 0;
    int &ret = cache[idx][b];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < graph[idx].size(); ++i)
        ret += DP(graph[idx][i].first, b) * graph[idx][i].second;
    
    return ret;
}

int main() {
    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < M; ++i){
        int n1, n2, q;
        scanf("%d %d %d", &n1, &n2, &q);
        graph[n1].push_back({n2, q});
    }
    for(int i = 1; i < N; ++i)
        if(graph[i].size() == 0)
            basic.push_back(i);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < basic.size(); ++i)
        printf("%d %d\n", basic[i], DP(N, basic[i]));

    return 0;
}
