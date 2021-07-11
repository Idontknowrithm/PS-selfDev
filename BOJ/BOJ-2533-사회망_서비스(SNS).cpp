// 그래프를 트리화 하는 문제였는데 그래프 자체로 visited 배열 써서 푸니까 틀림
// 그래프를 단방향 그래프화(트리화) 하니까 풀림..
// 트리 형태로 풀어야 하는 문제에서 DFS 사용할 때는 스택이나 재귀 사용 시 중간에서 꼬일 수 있으니
// 단방향 그래프로 변형한 뒤 풀어야 할 듯

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

const int MAX = 1000005, INF = 1000000000;
int N, ans, visited[MAX], cache[MAX][5];
std::vector<int> graph[MAX], tree[MAX];

void one_way_graphing(int node){
    ++visited[node];
    for(int i = 0; i < graph[node].size(); ++i){
        int next = graph[node][i];
        if(!visited[next]){
            tree[node].push_back(next);
            one_way_graphing(next);
        }
    }
}
int num_of_early(int cur_node, int early_bool){
    if(tree[cur_node].size() == 0)
        return early_bool;
    
    int &ret = cache[cur_node][early_bool];
    if(ret != -1) return ret;
    ret = INF;

    int tmp = early_bool;
    if(early_bool){
        for(int i = 0; i < tree[cur_node].size(); ++i){
            tmp += std::min(num_of_early(tree[cur_node][i], 1),
                            num_of_early(tree[cur_node][i], 0));
        }
    }
    else{
        for(int i = 0; i < tree[cur_node].size(); ++i){
            tmp += num_of_early(tree[cur_node][i], 1);
        }
    }
    ret = std::min(ret, tmp);
    return ret;
}

int main() {
    int start, end;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d", &start, &end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    one_way_graphing(1);
    memset(visited, 0, sizeof(visited));
    memset(cache, -1, sizeof(cache));
    ++visited[1];
    ans = num_of_early(1, 0);
    memset(visited, 0, sizeof(visited));
    memset(cache, -1, sizeof(cache));
    ++visited[1];
    ans = std::min(ans, num_of_early(1, 1));
    printf("%d", ans);
    return 0;    
}
