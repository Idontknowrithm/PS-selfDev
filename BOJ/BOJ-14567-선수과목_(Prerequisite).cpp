#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define pp std::pair<int, int>

int N, M, in_degree[1005], ans[1005];
std::vector<int> graph[1005];
std::queue<pp> que;

int main() {
    memset(ans, -1, sizeof(ans));
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        ++in_degree[b];
    }
    for(int i = 1; i <= N; ++i)
        if(!in_degree[i])
            que.push({i, 0});
    while(!que.empty()){
        int idx = que.front().first, in_d = que.front().second;
        que.pop();
        ans[idx] = std::max(ans[idx], in_d);
        for(int i = 0; i < graph[idx].size(); ++i){
            int next = graph[idx][i];
            if(--in_degree[next] == 0){
                que.push({next, in_d + 1});
            }
        }
    }
    for(int i = 1; i <= N; ++i)
        printf("%d ", ans[i] + 1);
    
    return 0;
}
