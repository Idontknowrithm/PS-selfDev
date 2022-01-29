아이디어를 생각해내는 것 자체가 나에겐 상당히 어려웠다. 먼저 두 번의 DFS로 2SAT을
찾아낸 다음, 어떻게 2SAT의 해를 찾을 것이냐, 여기서 첫 번째 문제가 발생했다
블로그를 검색해본 뒤 해를 찾는 알고리즘은 위상정렬이라는 것을 알고 2SAT을 찾기 위해 만든
그래프 자체에서(하나의 정점이 하나의 수(ex. 3, -2, 5 등)로 이루어진 그래프) 위상 정렬을
실행한 뒤 간선이 꽂히는 개수(in_degree라 하자)의 오름차순으로 false를 매겨주는 방식으로 
갔다. 여기서 false로 매겨주는 이유는 이 그래프의 간선의 의미는, 예를 들어 3 -> -2이면 
3이 참이면 2는 거짓이라는 명제를 나타내는데, 이때 3을 거짓이라고 해버리면 이 명제는 쉽게 
참으로 바뀐다. 따라서 in_degree가 낮은 정점 순으로 그 정점을 반대해버리면 2SAT의 해를 구할 수
있다고 생각했는데 이는 다음과 같은 이유로 오산이다
다음과 같은 그래프를 생각해보자
1 -> 2
2 -> 3
3 -> 1
1 -> 4
4 -> 5
5 -> 6
6 -> 4
다음과 같은 그래프는 2SAT의 해가 존재한다. 그러나 처음부터 in_degree가 0인 정점이 없어
위상 정렬을 수행할 수 없게 된다. 따라서 그래프 자체에서의 위상정렬이 아니라 SCC로 묶여진
그래프에서 위상 정렬을 수행해야 된다. 그러나 여기서도 문제가 될 만한 것이 이때의 위상 정렬의
알고리즘이 큐를 사용하는 기존의 알고리즘과 약간 다르다는 점이다. 먼저 SCC를 매길 때, SCC가
매겨지는 순서를 알 수 있게 scc_idx를 설정한다. 정확한 이유는 모르겠지만 scc 그룹을 매길 때
in_degree가 적은 순서대로 그룹이 매겨진다. 이후 scc_idx와 정점 idx를 pair로 묶어 벡터로
만들고, 이를 scc_idx 순으로 정렬시켜 순서대로 각 정점에 대한 참 거짓을 매기면 원래 의도대로
scc 그룹 기준으로 위상 정렬 후 2SAT의 해가 매겨지게 된다

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 20005;
int T, V, E, scc_num, scc_groups[MAX], in_vertex[MAX], bool_ans[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX];

void conntector(int a, int b){
    a = (a < 0) ? 20001 + a : a;
    b = (b < 0) ? 20001 + b : b;
    graph[a].push_back(b);
    ++in_vertex[b];
    r_graph[b].push_back(a);
}
void dfs(int cur){
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

        int scc_idx = ++scc_num;
        for(int i = 0; i < mini_ans.size(); ++i){
            scc_groups[mini_ans[i]] = scc_idx;
        }
    }
}
void topol_sort(){
    std::vector<pp> arr;
    for(int i = 1; i <= V; ++i){
        arr.push_back({scc_groups[i], i});
        arr.push_back({scc_groups[20001 - i], 20001 - i});
    }
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ++i){
        int scc = arr[i].first, idx = arr[i].second;
        int abs_idx = (idx > 10000) ? 20001 - idx : idx;
        if(bool_ans[abs_idx] == -1)
            bool_ans[abs_idx] = (idx > 10000) ? 1 : 0;
    }
}

int main() {
    memset(bool_ans, -1, sizeof(bool_ans));
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        conntector(-a, b);
        conntector(-b, a);
    }
    for(int i = 1; i <= V; ++i){
        if(!visited[i])
            dfs(i);
        if(!visited[20001 - i])
            dfs(20001 - i);
    }
            
    memset(visited, false, sizeof(visited));
    SCC();
    for(int i = 1; i <= V; ++i){
        if(scc_groups[i] == scc_groups[20001 - i]){
            printf("0");
            return 0;
        }
    }
    printf("1\n");
    topol_sort();
    for(int i = 1; i <= V; ++i)
        printf("%d ", bool_ans[i]);
    return 0;
}
