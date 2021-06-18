// 일을 처리할 때 선행되는 일이 있다 -> 위상정렬
// 진입 차수가 0인 일부터 차근차근 해나가는 알고리즘

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int N, M, print_size, in_deg[32005];
std::vector<int> graph[32005];
std::priority_queue<int, std::vector<int>, std::greater<int>> null_in_deg;

int main() {
    int ia, ib;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &ia, &ib);
        if(ia == ib) continue;
        graph[ia].push_back(ib);
        ++in_deg[ib];
    }
    for(int i = 1; i <= N; ++i){
        if(!in_deg[i])
            null_in_deg.push(i);
    }
    while(!null_in_deg.empty()){
        int tmp = null_in_deg.top();
        null_in_deg.pop();
        printf("%d ", tmp);
        for(int i = 0; i < graph[tmp].size(); ++i){
            --in_deg[graph[tmp][i]];
            if(!in_deg[graph[tmp][i]])
                null_in_deg.push(graph[tmp][i]);
        }   
    }
    return 0;
}
