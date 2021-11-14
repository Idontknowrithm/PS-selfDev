// 모든 일반 마을이 우수마을과 인접해있어야한다는 조건이 있었는데, 이 조건을
// 맞추려고 무리한 조건문을 끼우다가 오류를 만들어냄
// 생각해보면 -> 우수마을과 인접해있지않은 일반 마을이 있다: 그 일반 마을을
// 우수 마을로 만들어도 우수 마을끼리 접할 리가 없다, 즉 우수 마을과 인접해있지않은
// 일반 마을은 우수 마을로 만드는 것이 무조건 이득이다

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
