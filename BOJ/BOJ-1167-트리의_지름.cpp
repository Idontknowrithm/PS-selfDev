#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, int>> tree[100005];
int V, sVtx, inVtx, inEdge, vtxLen[100005], visited[100005];

void propagation(int start){

    std::queue<int> bfs;
    bfs.push(start);
    visited[start] = 1;

    while(!bfs.empty()){
        int cur = bfs.front();
        bfs.pop();
        for(int i = 0; i < tree[cur].size(); ++i){
            if(!visited[tree[cur][i].first]){
                vtxLen[tree[cur][i].first] += vtxLen[cur] + tree[cur][i].second;
                bfs.push(tree[cur][i].first);
                visited[tree[cur][i].first] = 1;
            }
        }
    }
}

int main() {
    int max = 0, maxi;
    scanf("%d", &V);
    for(int i = 0; i < V; ++i){
        scanf("%d", &sVtx);
        while(1){
            scanf("%d", &inVtx);
            if(inVtx == -1) break;
            scanf("%d", &inEdge);
            tree[sVtx].push_back({inVtx, inEdge});
        }
    }
    
    propagation(1);
    for(int i = 1; i <= V; ++i){
        if(max < vtxLen[i]){
            max = vtxLen[i];
            maxi = i;
        }
    }
    max = 0;
    for(int i = 0; i < 100005; ++i){
        vtxLen[i] = 0;
        visited[i] = 0;
    }
    propagation(maxi);
    
    for(int i = 1; i <= V; ++i)
        max = (max < vtxLen[i]) ? vtxLen[i] : max;
    
    printf("%d", max);

    return 0;
}
