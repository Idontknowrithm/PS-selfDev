#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

const int MAX = 10005;
int T, N, pair[2], parent[MAX];
bool end;
std::vector<int> route1, route2, tmp;
std::vector<int> graph[MAX];

void DFS(int cur, int target){
    if(end) return;
    if(cur == pair[target]){
        if(!target)
            route1 = tmp;
        else 
            route2 = tmp;
        end = true;
        return;
    }
    for(int i = 0; i < graph[cur].size(); ++i){
        int next = graph[cur][i];
        tmp.push_back(next);
        DFS(next, target);
        tmp.erase(tmp.end() - 1);
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        memset(parent, 0, sizeof(parent));
        route1.clear();
        route2.clear();
        tmp.clear();
        for(int i = 0; i < MAX; ++i)
            graph[i].clear();
        scanf("%d", &N);
        for(int i = 0; i < N - 1; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            ++parent[b];
        }
        scanf("%d %d", &pair[0], &pair[1]);
        end = false;
        for(int i = 1; i <= N; ++i)
            if(!parent[i]){
                tmp.push_back(i);
                DFS(i, 0);
            }
        tmp.clear();
        end = false;
        for(int i = 1; i <= N; ++i)
            if(!parent[i]){
                tmp.push_back(i);
                DFS(i, 1);
            }
        int lca = -1;
        for(int i = 0;; ++i){
            if(i >= route1.size() || i >= route2.size())
                break;
            if(route1[i] == route2[i])
                lca = route1[i];
            else 
                break;
        }
        printf("%d\n", lca);
    }
    return 0;
}
