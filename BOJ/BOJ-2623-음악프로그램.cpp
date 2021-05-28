#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#define pp std::pair<int, int>

int N, M, prev_node[1005], input[1005];
std::vector<int> graph[1005];
std::set<pp> del_overlap;

void traversal(){
    std::queue<int> bfs;
    for(int i = 1; i <= N; ++i)
        if(!prev_node[i]){
            bfs.push(i);
        }
    while(!bfs.empty()){
        int tmp = bfs.front();
        bfs.pop();
        printf("%d\n", tmp);
        for(int i = 0; i < graph[tmp].size(); ++i){
            if(prev_node[graph[tmp][i]] == 1){
                bfs.push(graph[tmp][i]);
            }
            --prev_node[graph[tmp][i]];
        }
    }
}
bool cycle(){ // cycle을 dfs로..
    for(int i = 1; i <= N; ++i){
        std::queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int tmp = bfs.front();
            bfs.pop();
            for(int u = 0; u < graph[tmp].size(); ++u){
                if(graph[tmp][u] == i){
                    return true;
                }
                bfs.push(graph[tmp][u]);
            }
        }
    }
    return false;
}

int main() {
    int iN, ia, ib;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d", &iN);
        for(int u = 0; u < iN; ++u)
            scanf("%d", &input[u]);
        for(int u = 0; u < iN - 1; ++u){
            pp tmp = {input[u], input[u + 1]};
            del_overlap.insert(tmp);
        }
    }
    std::set<pp>::iterator it;
    for(it = del_overlap.begin(); it != del_overlap.end(); ++it){
        pp tmp = *it;
        graph[tmp.first].push_back(tmp.second);
        ++prev_node[tmp.second];
    }
    if(cycle()){
        printf("0");
    }
    else{
        traversal();
    }
    return 0;
}
