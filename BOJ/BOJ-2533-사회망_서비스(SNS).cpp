#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

const int MAX = 1000005, INF = 1000000000;
int N, ans, visited[MAX], cache[MAX][5];
std::vector<int> graph[MAX];

int num_of_early(int cur_node, int early_bool){
    int all_visited = 0;
    for(int i = 0; i < graph[cur_node].size(); ++i)
        if(visited[graph[cur_node][i]]) ++all_visited;
    if(all_visited == graph[cur_node].size()) 
        return early_bool;
    

    int &ret = cache[cur_node][early_bool];
    if(ret) return ret;
    ret = INF;

    ++visited[cur_node];
    int tmp = early_bool;
    if(early_bool){
        for(int i = 0; i < graph[cur_node].size(); ++i){
            if(!visited[graph[cur_node][i]]){
                ++visited[graph[cur_node][i]];
                tmp += std::min(num_of_early(graph[cur_node][i], 1),
                                num_of_early(graph[cur_node][i], 0));
            }
        }
    }
    else{
        for(int i = 0; i < graph[cur_node].size(); ++i){
            if(!visited[graph[cur_node][i]]){
                ++visited[graph[cur_node][i]];
                tmp += num_of_early(graph[cur_node][i], 1);
            }
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
    ans = num_of_early(1, 0);
    memset(visited, 0, sizeof(visited));
    memset(cache, 0, sizeof(cache));
    ans = std::min(ans, num_of_early(1, 1));
    printf("%d", ans);
    return 0;    
}
