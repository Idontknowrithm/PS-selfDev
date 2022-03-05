#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int MAX = 10005, hMAX = 5000;
int T, K, N, scc_num, scc_groups[MAX], in_vertex[MAX], bool_ans[MAX];
bool visited[MAX];
std::stack<int> stk;
std::vector<int> mini_ans, graph[MAX], r_graph[MAX];

void conntector(int a, int b){
    a = (a < 0) ? MAX - 4 + a : a;
    b = (b < 0) ? MAX - 4 + b : b;
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
    for(int i = 1; i <= K; ++i){
        arr.push_back({scc_groups[i], i});
        arr.push_back({scc_groups[MAX - 4 - i], MAX - 4 - i});
    }
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ++i){
        int scc = arr[i].first, idx = arr[i].second;
        int abs_idx = (idx > hMAX) ? MAX - 4 - idx : idx;
        if(bool_ans[abs_idx] == -1)
            bool_ans[abs_idx] = (idx > hMAX) ? 1 : 0;
    }
}
int tf(char c){
    return (c == 'R') ? 1 : -1;
}

int main() {
    memset(bool_ans, -1, sizeof(bool_ans));
    scanf("%d %d\n", &K, &N);
    for(int i = 0; i < N; ++i){
        int n[3];
        char c[3];

        scanf("%d %c %d %c %d %c", &n[0], &c[0], &n[1], &c[1], &n[2], &c[2]);
        getchar();

        n[0] *= tf(c[0]);
        n[1] *= tf(c[1]);
        n[2] *= tf(c[2]);

        conntector(-n[0], n[1]);
        conntector(-n[0], n[2]);
        conntector(-n[1], n[0]);
        conntector(-n[1], n[2]);
        conntector(-n[2], n[0]);
        conntector(-n[2], n[1]);
    }
    for(int i = 1; i <= K; ++i){
        if(!visited[i])
            dfs(i);
        if(!visited[MAX - 4 - i])
            dfs(MAX - 4 - i);
    }
            
    memset(visited, false, sizeof(visited));
    SCC();
    for(int i = 1; i <= K; ++i){
        if(scc_groups[i] == scc_groups[MAX - 4 - i]){
            printf("-1");
            return 0;
        }
    }
    topol_sort();
    for(int i = 1; i <= K; ++i)
        printf("%c", (bool_ans[i]) ? 'R' : 'B');

    return 0;
}
