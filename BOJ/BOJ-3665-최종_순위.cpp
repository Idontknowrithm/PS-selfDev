// 확실한 순위를 고를 수 없는 경우에 ?를 출력하라 했는데, 실제로는 그런
// 경우가 없다고 한다. 이 부분을 구현하면서 많은 시행착오들이 있었는데(사이클 구분)
// 이건 당할 수밖에 없는 함정인 것 같다. 이런 문제 자체의 함정 같은 경우는
// 가능하면 걸러내보고 증명을 잘 못하겠다면 포기하는 것도 괜찮을 것 같다. 혹은
// 그것을 구현하는 데 불가능한 시간이나 메모리 제한이 있다면 의심을 해보는 것도
// 하나의 방법일 수 있겠다

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

const int MAX = 505;
int T, N, M, is_visited, graph[MAX][MAX], rank[MAX], topological[MAX];
bool cycle;

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(graph, 0, sizeof(graph));
        memset(topological, 0, sizeof(topological));
        
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &rank[i]);
        for(int i = 0; i < N - 1; ++i)
        for(int u = i + 1; u < N; ++u){
            graph[rank[i]][rank[u]] = 1;
            ++topological[rank[u]];
        }            
        
        scanf("%d", &M);
        for(int i = 0; i < M; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            if(graph[a][b]){
                graph[a][b] = 0;
                graph[b][a] = 1;
                --topological[b];
                ++topological[a];
            }
            else{
                graph[a][b] = 1;
                graph[b][a] = 0;
                --topological[a];
                ++topological[b];
            }
        }
        std::vector<int> ans;
        std::queue<int> que;
        bool question = false;
        for(int i = 1; i <= N; ++i)
            if(!topological[i])
                que.push(i);
        while(!que.empty()){
            int cur = que.front();
            ans.push_back(cur);
            que.pop();
            for(int i = 1; i <= N; ++i){
                if(graph[cur][i]){
                    --topological[i];
                    if(!topological[i])
                        que.push(i);
                }
            }
        }
        if(ans.size() == N){
            for(int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            puts("");
        }
        else{
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
