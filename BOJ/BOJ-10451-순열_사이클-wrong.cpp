//normal wrong

#include<iostream>
#include<vector>
#include<stack>

int N, ans, graph[1001][1001], visited[1001];

void cycle(int start){
    bool find_cycle = false;
    std::stack<int> dfs;

    dfs.push(start);
    while(!dfs.empty() && !find_cycle){
        for(int i = 1; i <= N; ++i){
            if(i == start && graph[dfs.top()][i]){
                ++ans;
                visited[i] = 1;
                find_cycle = true;
                break;
            }
            else if(!visited[i] && graph[dfs.top()][i]){
                dfs.push(i);
                visited[i] = 1;
                break;
            }
            else if(i == N){
                dfs.pop();
                break;
            }
        }
    }
}

int main () {
    int T, inp;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
        for(int u = 1; u <= N; ++u)
            graph[i][u] = 0;
        for(int i = 1; i <= N; ++i)
            visited[i] = 0;
        
        for(int i = 0; i < N; ++i){
            scanf("%d", &inp);
            graph[i + 1][inp] = 1;
        }
        ans = 0;
        for(int i = 0; i < N; ++i) // critical
            cycle(i);

        printf("%d\n", ans);
    }
    return 0;
}
