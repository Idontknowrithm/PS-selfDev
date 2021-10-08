#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

const int MAX = 2005, INF = 50000005;
int T, n, m, t, s, g, h, fragrance, s_start[MAX], h_start[MAX], g_start[MAX];
std::vector<int> semi_dests, dests;
std::vector<pp> graph[MAX];

void dijk(int start, int *dist){
    std::priority_queue<pp, std::vector<pp>, std::greater<pp>> q;
    for(int i = 0; i < MAX; ++i)
        dist[i] = INF;
    q.push({0, start});
    dist[start] = 0;
    while(!q.empty()){
        int cur_d = q.top().first, cur_v = q.top().second;
        q.pop();
        if(dist[cur_v] < cur_d) continue;
        for(int i = 0; i < graph[cur_v].size(); ++i){
            int next_v = graph[cur_v][i].first;
            int next_d = graph[cur_v][i].second + cur_d;
            if(next_d < dist[next_v]){
                dist[next_v] = next_d;
                q.push({next_d, next_v});
            }
        }
    }
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d %d\n%d %d %d", &n, &m, &t, &s, &g, &h);
        for(int i = 0; i < m; ++i){
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            if(a == g && b == h) fragrance = d;
            if(a == h && b == g) fragrance = d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        for(int i = 0; i < t; ++i){
            int tmp;
            scanf("%d", &tmp);
            semi_dests.push_back(tmp);
        }
        dijk(s, s_start);
        dijk(h, h_start);
        dijk(g, g_start);
        for(int i = 0; i < semi_dests.size(); ++i){
            int d = semi_dests[i];
            int tmp = std::min(s_start[g] + fragrance + h_start[d],
                               s_start[h] + fragrance + g_start[d]);
            if(s_start[d] < INF && tmp < INF && s_start[d] == tmp)
                dests.push_back(d);
        }
        std::sort(dests.begin(), dests.end());
        for(int i = 0; i < dests.size(); ++i)
            printf("%d ", dests[i]);
        puts("");
        for(int i = 0; i < MAX; ++i)
            graph[i].clear();
        semi_dests.clear();
        dests.clear();
    }
    return 0;
}
