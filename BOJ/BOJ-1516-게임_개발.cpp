#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

int N, duration[505], cache[505];
std::vector<int> graph[505];

int DP(int idx){
    int &ret = cache[idx];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < graph[idx].size(); ++i)
        ret = std::max(ret, DP(graph[idx][i]));
    ret += duration[idx];
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &duration[i]);
        int tmp;
        scanf("%d", &tmp);
        while(tmp != -1){
            graph[i].push_back(tmp);
            scanf("%d", &tmp);
        }
            
    }
    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= N; ++i)
        if(cache[i] == -1)
            DP(i);
    for(int i = 1; i <= N; ++i)
        printf("%d\n", cache[i]);
    return 0;
}
