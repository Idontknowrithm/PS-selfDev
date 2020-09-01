#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

int N, dist[10005], visited[10005];
std::vector<std::pair<int, int>> tree[10005];
void deeper(int start){
    std::queue<std::pair<int, int>> bfs;

    bfs.push({start, 0});
    dist[start] = 0;
    visited[start] = 1;
    while(!bfs.empty()){
        int curN = bfs.front().first, curD = bfs.front().second;
        bfs.pop();

        for(int i = 0; i < tree[curN].size(); ++i){
            if(!visited[tree[curN][i].first]){
                visited[tree[curN][i].first] = 1;
                bfs.push({tree[curN][i].first, tree[curN][i].second + curD});
                dist[tree[curN][i].first] = tree[curN][i].second + curD;
            }
        }
    }
}

int main () {
    int inp1, inp2, inp3;
    scanf("%d", &N);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d %d", &inp1, &inp2, &inp3);
        tree[inp1].push_back({inp2, inp3});
        tree[inp2].push_back({inp1, inp3});
    }
    deeper(1);

    int max = -1, maxN;
    for(int i = 1; i <= N; ++i)
        if(max < dist[i]){
            max = dist[i];
            maxN = i;
        }
    for(int i = 0; i < 10005; ++i){
        dist[i] = 0;
        visited[i] = 0;
    }
    deeper(maxN);
    
    max = -1;
    for(int i = 1; i <= N; ++i)
        max = (max < dist[i]) ? dist[i] : max;
    
    printf("%d", max);

    return 0;
}
