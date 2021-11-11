#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#define pp std::pair<int, int>
#define ppp std::pair<double, std::pair<int, int>>
#define uno first
#define dos second.first
#define tres second.second

const int MAX = 1005;
int N, M, set[MAX], set_size[MAX];
double ans, graph[MAX][MAX];
pp coordinates[MAX];
std::vector<ppp> edges;

int find_set(int num){
    if (set[num]==num)
        return num;
    int parent = find_set(set[num]);
    set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    if(first == second) return;

    if(set_size[first] < set_size[second])
        std::swap(first, second);

    set[second] = first;
    set_size[first] += set_size[second];
    set_size[second] = 0;
}

int main() {
    for(int i = 0; i < MAX; ++i)
    for(int u = 0; u < MAX; ++u)
        graph[i][u] = -1;
    for(int i = 0; i < MAX; ++i){
        set[i] = i;
        set_size[i] = 1;
    }
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        coordinates[i] = {a, b};
    }

    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u){
        if(i >= u) continue;
        double x = (double)(coordinates[i].first - coordinates[u].first);
        double y = (double)(coordinates[i].second - coordinates[u].second);
        graph[i][u] = sqrt(x * x + y * y);
    }
    for(int i = 0; i < M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) std::swap(a, b);
        if(graph[a][b] >= 0){
            graph[a][b] = -1;
            union_set(find_set(a), find_set(b));
        }
    }
    for(int i = 1; i <= N; ++i)
    for(int u = 1; u <= N; ++u){
        if(i >= u) continue;
        if(graph[i][u] >= 0)
            edges.push_back({graph[i][u], {i, u}});
    }
    std::sort(edges.begin(), edges.end());
    if(set_size[1] == N){
        printf("%.2lf", ans);
        return 0;
    }
    for(int i = 0; i < edges.size(); ++i){
        int a = edges[i].dos, b = edges[i].tres;
        double val = edges[i].uno;
        if(find_set(a) != find_set(b)){
            union_set(find_set(a), find_set(b));
            ans += val;
        }
        if(set_size[a] == N){
            printf("%.2lf", ans);
            break;
        }
    }
    return 0;
}
