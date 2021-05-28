#include<iostream>
#include<vector>
#include<queue>

int N, M, prev_node[32005];
std::vector<int> graph[32005];

void traversal(){
    std::queue<int> bfs;
    for(int i = 1; i <= N; ++i)
        if(!prev_node[i]){
            bfs.push(i);
        }
    while(!bfs.empty()){
        int tmp = bfs.front();
        bfs.pop();
        printf("%d ", tmp);
        for(int i = 0; i < graph[tmp].size(); ++i){
            if(prev_node[graph[tmp][i]] == 1){
                bfs.push(graph[tmp][i]);
            }
            --prev_node[graph[tmp][i]];
        }
    }
}

int main() {
    int ia, ib;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &ia, &ib);
        graph[ia].push_back(ib);
        ++prev_node[ib];
    }
    traversal();
    return 0;
}
