// scc 알고리즘 써야하는 것까지 무난한데, 상근이를 무조건 올려야 한다는
// 조건, 즉 1이 무조건 참이 되는 조건이 이 문제를 까다롭게 만든 것 같다.
  
// 심사위원이 두 표를 던지는데 하나 이상은 참이 되어야하고, 모든 심사위원에
// 대해서 이 규칙이 적용되니가 2-SAT인 것까지는 왔다. 여기서 1을 무조건 참으로 
// 만들어줘야 하는데, 이것을 만족시키기 위해 그래프 자체에 -1 -> 1 간선을
// 추가했다. -1이 참이면 1도 참. 간선 내용만 보면 말이 안되지만 이것을 명제로
// 생각하고 -1을 거짓으로 취급하면 명제 자체가 참이 된다는 점을 사용하면 문제가
// 없다. 그런데 -1을 어떻게 거짓으로 취급할 것인가? 이는 scc가 그룹 묶여지는
// 원리를 사용하면 된다. 코사라주로 scc를 묶으면 in_degree가 적은 것이 먼저 묶여지게
// 된다. 11281 2-SAT-4 문제를 참고하면 2-SAT의 정해를 구하려면 in_degree가 
// 작은 순으로 그 노드에 대해서 거짓을 매겨주면서 그래프를 모두 돌면 된다고 했는데,
// 이렇게 되면 1보다 -1을 먼저 방문하도록 만들어주면 -1을 거짓으로 두면서 1을 참으로
// 두게되는 결과를 가져오게 된다. 따라서 이 문제를 해결하려면
//   1. 정점 i와 정점 -i가 다른 scc 그룹에 속하기
//   2. -1의 그룹 idx 보다 1의 그룹 idx가 높기
// 를 충족시키면 된다. 논외로 이 문제는 2번을 무시해도 정답 처리를 받는다

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 2005, neg_cvt = 2001;
int N, M, scc_idx = 1, scc_groups[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX];

void conntector(int a, int b){
    a = (a < 0) ? neg_cvt + a : a;
    b = (b < 0) ? neg_cvt + b : b;
    graph[a].push_back(b);
    r_graph[b].push_back(a);
}
void dfs(int cur){
    printf("stk: %d\n", (cur > 1000) ? -neg_cvt + cur : cur);
    visited[cur] = true;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        if(!visited[next])
            dfs(next);
    }
    stk.push(cur);
    
}
void r_dfs(int cur){
    mini_ans.push_back(cur);
    visited[cur] = true;
    for(int i = 0; i < r_graph[cur].size(); ++i){
        int next = r_graph[cur][i];
        if(!visited[next])
            r_dfs(next);
    }
}
void SCC(){
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        if(visited[cur]) continue;

        mini_ans.clear();
        r_dfs(cur);
        
        for(int i = 0; i < mini_ans.size(); ++i)
            scc_groups[mini_ans[i]] = scc_idx;
        ++scc_idx;
    }
}

int main() {
    while(scanf("%d %d", &N, &M) != EOF){
        mini_ans.clear();
        for(int i = 0; i < MAX; ++i){
            graph[i].clear();
            r_graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
        memset(scc_groups, 0, sizeof(scc_groups));
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            conntector(-a, b);
            conntector(-b, a);
        }
        graph[neg_cvt - 1].push_back(1);
        r_graph[1].push_back(neg_cvt - 1);
        for(int i = 1; i <= N; ++i){
            if(!visited[i])
                dfs(i);
            if(!visited[neg_cvt - i])
                dfs(neg_cvt - i);
        }
        memset(visited, false, sizeof(visited));
        SCC();
        bool ans = true;
        for(int i = 1; i <= N; ++i){
            if(scc_groups[i] == scc_groups[neg_cvt - i]){
                ans = false;
                break;
            }
        }
        printf("%s", (ans) ? "yes\n" : "no\n");
        for(int i = 1; i <= N; ++i)
            printf("%d ", scc_groups[i]);
        puts("");
        for(int i = 1; i <= N; ++i)
            printf("%d ", scc_groups[neg_cvt - i]);
        puts("");
    }
    return 0;
}
