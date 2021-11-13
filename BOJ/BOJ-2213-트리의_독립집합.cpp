// 해를 구하는 DP -> DP로 cache를 갱신해놓은 뒤에 DFS로
//                 cache에 갱신된 답을 따라 최적해를 구함

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

const int MAX = 10005;
int N, weights[MAX], cache[MAX][2];
bool visited[MAX], selected_nodes[MAX];
std::vector<int> tree[MAX];

int DP(int node, int included){
    int &ret = cache[node][included];
    if(ret != -1) return ret;

    ret = weights[node] * included;
    for(int i = 0; i < tree[node].size(); ++i){
        int next = tree[node][i];
        if(!visited[next]){
            visited[next] = true;
            if(included)
                ret += DP(next, 0);
            else{
                ret += std::max(DP(next, 0), DP(next, 1));
            }
            visited[next] = false;
        }
    }
    return ret;
}
void tracker(int start, int incl){
    if(incl) selected_nodes[start] = true;
    for(int i = 0; i < tree[start].size(); ++i){
        int next = tree[start][i];
        if(!visited[next]){
            visited[next] = true;
            if(incl)
                tracker(next, 0);
            else if(cache[next][0] < cache[next][1])
                tracker(next, 1);
            else 
                tracker(next, 0);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &weights[i]);
    for(int i = 0; i < N - 1; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(cache, -1, sizeof(cache));
    visited[1] = true;
    printf("%d\n", std::max(DP(1, 0), DP(1, 1)));
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    if(cache[1][0] < cache[1][1])
        tracker(1, 1);
    else 
        tracker(1, 0);
    for(int i = 1; i <= N; ++i)
        if(selected_nodes[i])
            printf("%d ", i);
    return 0;
}
