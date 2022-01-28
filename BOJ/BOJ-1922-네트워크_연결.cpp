#include<iostream>
#include<algorithm>
#include<vector>
#define pp std::pair<int, int>
#define ppp std::pair<int, pp>

int N, M, ans, set[1005];
std::vector<ppp> edges;

int find_set(int num){
    if (set[num]==num)
        return num;
    int parent = find_set(set[num]);
    set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    first = find_set(first);
    second = find_set(second);
    int temp;
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main() {
    for(int i = 0; i < 1005; ++i)
        set[i] = i;
    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({c, {a, b}});
    }
    std::sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); ++i){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find_set(a) != find_set(b)){
            ans += edges[i].first;
            union_set(a, b);
        }
    }
    printf("%d", ans);
    return 0;
}
