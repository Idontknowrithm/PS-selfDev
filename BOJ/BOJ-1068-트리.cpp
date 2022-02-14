// 알고리즘 자체의 어려움 보다는 이 문제에 존재하는 여러 예외 사항들이 WA를 유도헀다
// 처음 생각한 알고리즘은 전체 트리를 dfs로 돌아 리프 노드의 수를 구하고,
// 잘린 간선으로 생긴 루트 노드를 dfs 돌아 리프 노드의 수를 구해 전체 리프 노드의
// 수에서 빼는 방식으로 갔는데, 이는 일직선인 트리에서 중간에 잘렸을 때 예외를 낸다.
// 예를 들어 0, 1, 2, 3, 4가 일직선으로 있는데 2번 노드를 뺀다면 정답은 1이 되어야
// 하는데 나의 알고리즘으로 돌리면 전체 트리 리프노드 1 - 잘린 트리의 리프노드 1 = 0
// 이 되어버린다. 그래서 그래프 자체에서 없앨 노드와 그 부모 노드의 간선을 자른 후
// 루트 노드에서 dfs를 도는 알고리즘으로 재설계 했는데, 이것도 예외가 있는 것이
// 없앨 노드가 애초에 루트 노드이면 그 위의 간선이 없으므로, 이때는 예외 처리를 따로
// 해서 이때만 정답을 0으로 내게 해야한다

#include<iostream>
#include<vector>
#include<algorithm>

int N, start, ans, parent[55];
std::vector<int> graph[55];

void DFS(int node){
    int child = 0;
    for(int i = 0; i < graph[node].size(); ++i){
        ++child;
        DFS(graph[node][i]);
    }
    if(!child)
        ++ans;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int p;
        scanf("%d", &p);
        parent[i] = p;
        if(p != -1)
            graph[p].push_back(i);
        else 
            start = i;
    }
    int will_delete;
    scanf("%d", &will_delete);
    if(parent[will_delete] == -1){
        printf("0");
        return 0;
    }
    std::vector<int> tmp, &ref = graph[parent[will_delete]];
    for(int i = 0; i < ref.size(); ++i){
        int child = ref[i];
        if(child != will_delete)
            tmp.push_back(ref[i]);
    }
    ref = tmp;
    DFS(start);
    printf("%d", ans);

    return 0;
}
