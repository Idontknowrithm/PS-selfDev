#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int start, end, weight;
}edge;

int N, M, ans, selected, set[100005], visited[100005];
std::vector<int> mst_val;
std::vector<edge> edge_container;

bool cmp(const edge &a, const edge &b){
    return a.weight < b.weight;
}
void union_set(int a, int b){
    if(a > b) std::swap(a, b);
    set[b] = a;
}
int find_set(int a){
    while(set[a] != a)
        a = set[a];
    return a;
}
void MST(){
    for(int i = 1; i <= N; ++i)
        set[i] = i;
    std::sort(edge_container.begin(), edge_container.end(), cmp);
    for(int i = 0; i < edge_container.size(); ++i){
        if(selected == N - 1) break;
        edge tmp = edge_container[i];
        if(find_set(tmp.start) != find_set(tmp.end)){
            union_set(find_set(tmp.start), find_set(tmp.end));
            mst_val.push_back(tmp.weight);
            ++selected;
        }
    }
}

int main(){
    int a, b, w, max = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &a, &b, &w);
        edge_container.push_back({a, b, w});
    }
    MST();
    for(int i = 0; i < mst_val.size(); ++i){
        max = (max < mst_val[i]) ? mst_val[i] : max;
        ans += mst_val[i];
    }
    printf("%d", ans - max);
    return 0;
}
