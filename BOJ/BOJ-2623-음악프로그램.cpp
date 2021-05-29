// 사이클은 dfs로 찾자
// 간단한 예제 손으로 풀어보면서 코너 케이스 체크하기

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cstring>
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
bool cycle(){
    int visited[1005], in_stack[1005];
    for(int s = 1; s <= N; ++s){
        memset(visited, 0, sizeof(visited));
        memset(in_stack, 0, sizeof(in_stack));
        std::stack<int> dfs;
        dfs.push(s);
        visited[s] = 1;
        in_stack[s] = 1;
        while(!dfs.empty()){
            int tmp = dfs.top();
            bool next_exist = false;
            for(int i = 0; i < graph[tmp].size(); ++i){
                if(in_stack[graph[tmp][i]]) return true;
                if(!visited[graph[tmp][i]]){
                    dfs.push(graph[tmp][i]);
                    visited[graph[tmp][i]] = 1;
                    in_stack[graph[tmp][i]] = 1;
                    next_exist = true;
                    break;
                }
            }
            if(!next_exist){
                in_stack[tmp] = 0;
                dfs.pop();
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
    if(cycle())
        printf("0");
    else
        traversal();
    return 0;
}
