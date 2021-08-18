// 단절점: 그 정점을 없애면 그래프 그룹의 수가 늘어나는 정점
// 단절점을 찾는 방법: dfs를 돌아 dfs tree를 만든 뒤에, 
//  1. tree의 루트라면 자식 노드가 2개 이상이면 단절점
//  2. 루트가 아닐 때 자신의 번호보다 작은 번호로 올라갈 수 있으면 단절점

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

const int MAX = 10005;
// cutV: 단절점 여부를 담는 배열. idx는 정점 고유번호 기준
bool cutV[MAX];
// order: dfs tree 상의 정점 번호(dfs 번호)를 담는 배열
int V, E, ans, order_ptr, order[MAX], visited[MAX];
std::vector<int> graph[MAX];

// 루트 여부가 is_root에 담긴 고유번호가 cur인 정점에서 출발하여
// dfs tree 상에서 갈 수 있는 가장 작은 dfs 번호를 반환
int find_cutV(int cur, bool is_root){
    visited[cur] = 1;
    // child: cur가 루트일 때는 단절점 여부를 자식 노드의 수로 파악
    // ret = order[cur]: 만약 연결되어있는 자식노드가 없으면
    //   갈 수 있는 가장 작은 dfs 번호는 자신이므로 미리 ret에 저장
    int child = 0, ret = order[cur] = order_ptr++;
    // 모든 자식 노드에 대해
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        // 탐색 대상인 자식 노드를 처음 방문했을때(order 배열이
        // update 되지 않았을 때
        if(order[next] == -1){
            // 자식이 있다는 소리
            ++child;
            // 자식 노드에서 갈 수 있는 가장 작은 dfs 번호를 저장
            int order_max = find_cutV(next, false);
            // 갈 수 있는 자식이 dfs 번호 상 더 작다면
            // cur 노드는 단절점이므로 이를 반영
            if(!is_root && order_max >= order[cur])
                cutV[cur] = true;
            
            // 반환 값이 가장 작은 dfs 번호이므로 이를 반영
            ret = std::min(ret, order_max);
        }
        else{
            // 탐색 대상인 자식 노드가 이미 update 되어있다면
            // dfs 탐색할 필요가 없고, 가장 작은 dfs 번호만 
            // 반환하면 되므로 이를 반영
            ret = std::min(ret, order[next]);
        }
    }
    // 루트 노드에서 자식 노드가 2개 이상이면 단절점
    if(is_root && child >= 2)
        cutV[cur] = true;
    return ret;
}

int main() {
    memset(order, -1, sizeof(order));
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= V; ++i)
        // 연결 그래프가 아닌 그래프에 대한 정점을 탐색할 때 필요
        // ex) 그래프가 A그룹과 B그룹으로 나뉘어 있을 때 find_cutV
        //     한 번이면 A 또는 B 그룹만 탐색 되므로 visited를 이용해서
        //     모든 그룹이 탐색되도록 
        if(!visited[i])
            find_cutV(i, true);
    for(int i = 1; i <= V; ++i)
        ans += (cutV[i]) ? 1 : 0;
    printf("%d\n", ans);
    for(int i = 1; i <= V; ++i)
        if(cutV[i])
            printf("%d ", i);
    return 0;
}
