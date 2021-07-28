#include<iostream>
#include<vector>
#include<algorithm>
#define pp std::pair<int, int>

int N, M, visited[40005];
std::vector<pp> graph[40005], tree;

void treeing(int start, int val_sum){
    tree.push_back({start, val_sum});
    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); ++i){
        if(!visited[graph[start][i].first]){
            treeing(graph[start][i].first, val_sum + graph[start][i].second);
            tree.push_back({start, val_sum});
        }
    }   
}

int main() {
    int a, b, val;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d %d", &a, &b, &val);
        graph[a].push_back({b, val});
        graph[b].push_back({a, val});
    }
    treeing(1, 0);
    for(int i = 0; i < tree.size(); ++i){
        printf("%d %d\n", tree[i].first, tree[i].second);
    }
    return 0;
}
