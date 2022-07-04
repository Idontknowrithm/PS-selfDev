// 허무한 삽질때문에 못푼 건 아닌 것 같고 실력 문제인 듯하다. 먼저 
// 문제 접근을 사이클을 찾고, 그 사이클을 구성하는 양방향 간선이
// 있는지 보고 양방향 간선들을 주어진 대로 놓았을 때 사이클이 생기지 않으면
// 그대로 가고, 사이클이 생기면 가장 뒤에 주어진 양방향 간선을 뒤집고
// 나머지는 그대로 둔다. 예를 들면 한 사이클을 구성하는 양방향 간선이
// K개의 양방향 간선 중 0으로 시작하는 idx로 해서 2, 3, 7번 간선으로
// 구성되었다면, 주어진대로 놓았을 때 사이클이 생긴다면 7번 간선을 뒤집어
// 정답 K배열을 XX00XXX1로 두는 방식으로 생각했다. 여기에서 계속 세그폴트가
// 떠서 메모리를 너무 많이 사용해서 그런줄 알고 벡터를 사용하는 그래프에서 
// 배열을 사용하는 그래프로 바꿨는데도 세그폴트가 떴다. 일단 부분점수라도
// 받아보려고 양방향 간선이 무조건 결정되어있는 경우만 생각했는데도 WA도
// 안나오고 세그가 떴다. 다시 생각해보니 사이클이 생기는 예외상황이
// 있었는데 북두칠성처럼 단일 경로로 시작하다가 사이클이 생기는 경우
// 사이클을 이루는 시작 노드가 DFS를 시작할 때 결정한 시작노드가 아닐 수
// 있기 때문에 이 상황에서 DFS가 계속 도는 상황이 발생한다.
  
//   처음 DFS 알고리즘: 시작하는 노드를 저장하고, 순회를 하다가 그 시작하는
//                      노드를 만나게 되면 사이클이라 판단하고 종료
//   다시 생각한 DFS: visited를 여러 값으로 지정할 수 있게 int로 구성하고,
//                    DFS를 시작할 때마다 visited를 다른 값으로 시작한다.
//                    그렇게 해서 DFS를 돌면서 현재 사용되고있는 visited
//                    값을 가지는 노드를 만나면 사이클이라 판단하고 종료

// 이렇게 하니 노드를 5개 이하로 만들어본 예시 상황에는 잘 돌아가는데, 이제는
// 세그는 안뜨더니 TLE가 난다. 부분점수도 안주는 것을 보니까 또 예외가 있나본데
// 이번에 생각해본 예외상황은 한 간선이 두 사이클을 만들고있는 상황이다. 이때는
// 나의 알고리즘 상으로는 양방향 간선을 사전 순으로 결정할 수 없다. 따라서
// 나의 알고리즘으로 해결할 수 없다고 판단하고 다른 코드를 보기로 했다.


// 일단 안되는 코드 V
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#include<cmath>

const int MAX = 505;
int T, N, M, K, v_idx, both[MAX][MAX], ans[MAX << 2], visited[MAX];
bool flag = false;
std::vector<int> graph[MAX], cycle, tmp_cycle;
std::stack<int> stk;

void DFS(int cur, int prev){
    if(flag) return;

    stk.push(cur);
    visited[cur] = v_idx;
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];

        if(flag) return;
        if(next == prev) 
            continue;
        if(visited[next] == v_idx){
            while(!stk.empty() && stk.top() != next){
                cycle.push_back(stk.top());
                stk.pop();
            }
            cycle.push_back(next);
            flag = true;
            return;
        }
        DFS(next, cur);
    }
    if(!stk.empty())
        stk.pop();
}

int main() {
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    for(int z = 1; z <= T; ++z){
        for(int i = 0; i < MAX; ++i)
            graph[i].clear();

        while(stk.empty() == false)
            stk.pop();
        memset(both, 0, sizeof(both));
        memset(ans, 0, sizeof(ans));
        memset(visited, 0, sizeof(visited));

        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < M; ++i){
            int a, b;
            
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }
        for(int i = 0; i < K; ++i){
            int a, b;

            scanf("%d %d", &a, &b);
            both[a][b] = i + 1;
            both[b][a] = -(i + 1);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
            
        v_idx = 1;
        for(int i = 1; i <= N; ++i){
            if(!visited[i]){
                flag = false;
                cycle.clear();

                DFS(i, -1);
                ++v_idx;
                if(flag){
                    int edge, strai = 0, rev = 0;
                    
                    tmp_cycle.clear();
                    for(int i = 0; i < cycle.size(); ++i)
                        visited[cycle[i]] = 1;

                    for(int i = cycle.size() - 1; i > 0 ; --i){
                        edge = both[cycle[i]][cycle[i - 1]];

                        if(edge){
                            (edge > 0) ? (++strai) : (++rev);
                        }
                        tmp_cycle.push_back(std::abs(edge));
                    }
                    edge = both[cycle[0]][cycle[cycle.size() - 1]];
                    if(edge){
                        (edge > 0) ? (++strai) : (++rev);
                    }
                    tmp_cycle.push_back(std::abs(edge));

                    if(!rev){
                        std::sort(tmp_cycle.begin(), tmp_cycle.end());
                        ans[tmp_cycle[tmp_cycle.size() - 1]] = 1;
                    }
                }
            }
            
        }
        
        printf("Case #%d\n", z);
        for(int i = 1; i <= K; ++i)
            printf("%d", ans[i]);
        puts("");
    }
    return 0;
}
