#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long

typedef struct{
    ll x, y, z; int idx;
}coordinate;
typedef struct{
    int a, b;
    ll val;
}edge;

ll ans;
int N, connected, set[100005];
std::vector<edge> edges;
std::vector<coordinate> Xsort, Ysort, Zsort;

bool cmpX(const coordinate a, const coordinate b){
    return a.x < b.x;
}
bool cmpY(const coordinate a, const coordinate b){
    return a.y < b.y;
}
bool cmpZ(const coordinate a, const coordinate b){
    return a.z < b.z;
}
bool cmp_edge(const edge a, const edge b){
    return a.val < b.val;
}
int find_set(int val){
    while(val != set[val])
        val = set[val];
    return val;
}
void union_set(int first, int second){
    int temp;
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main() {
    ll X, Y, Z;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        set[i] = i;
        scanf("%lld %lld %lld", &X, &Y, &Z);
        Xsort.push_back({X, Y, Z, i});
        Ysort.push_back({X, Y, Z, i});
        Zsort.push_back({X, Y, Z, i});
    }
    std::sort(Xsort.begin(), Xsort.end(), cmpX);
    std::sort(Ysort.begin(), Ysort.end(), cmpY);
    std::sort(Zsort.begin(), Zsort.end(), cmpZ);

    for(int i = 0; i < N - 1; ++i){
        if(Xsort[i].idx < Xsort[i + 1].idx)
            edges.push_back({Xsort[i].idx, Xsort[i + 1].idx, std::abs(Xsort[i].x - Xsort[i + 1].x)});
        else
            edges.push_back({Xsort[i + 1].idx, Xsort[i].idx, std::abs(Xsort[i].x - Xsort[i + 1].x)});
        if(Ysort[i].idx < Ysort[i + 1].idx)
            edges.push_back({Ysort[i].idx, Ysort[i + 1].idx, std::abs(Ysort[i].y - Ysort[i + 1].y)});
        else
            edges.push_back({Ysort[i + 1].idx, Ysort[i].idx, std::abs(Ysort[i].y - Ysort[i + 1].y)});
        if(Zsort[i].idx < Zsort[i + 1].idx)
            edges.push_back({Zsort[i].idx, Zsort[i + 1].idx, std::abs(Zsort[i].z - Zsort[i + 1].z)});
        else 
            edges.push_back({Zsort[i + 1].idx, Zsort[i].idx, std::abs(Zsort[i].z - Zsort[i + 1].z)});
    }
    std::sort(edges.begin(), edges.end(), cmp_edge);
    
    for(int i = 0; i < edges.size() && connected < N - 1; ++i){
        if(find_set(edges[i].a) != find_set(edges[i].b)){
            union_set(find_set(edges[i].a), find_set(edges[i].b));
            ans += edges[i].val;
            ++connected;
        }
    }
    printf("%lld", ans);
    return 0;
}
