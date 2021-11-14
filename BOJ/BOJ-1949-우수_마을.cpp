#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

const int MAX = 10005;
int N, citizens[MAX], cache[MAX][2];
bool visited[MAX];
std::vector<int> tree[MAX];

int DP(int node, int cur_incl){
    int &ret = cache[node][cur_incl];
    if(ret != -1) return ret;

    ret = citizens[node] * cur_incl;
    for(int i = 0; i < tree[node].size(); ++i){
        int next = tree[node][i];
        if(!visited[next]){
            visited[next] = true;
            if(cur_incl)
                ret += DP(next, 0);
            else 
                ret += std::max(DP(next, 1), DP(next, 0));
            visited[next] = false;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &citizens[i]);
    
    for(int i = 0; i < N - 1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(cache, -1, sizeof(cache));
    visited[1] = true;
    printf("%d", std::max(DP(1, 1), DP(1, 0)));

    return 0;
}
