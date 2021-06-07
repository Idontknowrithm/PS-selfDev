#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define pp std::pair<double, double>

typedef struct{
    int start, last;
    double weight;
}edge;

int N, selected, set[105];
pp input[105];
std::vector<edge> edge_vec;
double ans;

bool cmp(const edge a, const edge b){
    return a.weight < b.weight;
}
int findSet(int val){
    while(val != set[val])
        val = set[val];
    return val;
}
void unionSet(int first, int second){
    int temp;
    if(first > second){
        temp = first; first = second; second = temp;
    }
    else if(first == second) return;
    set[second] = first;
}

int main() {
    double ia, ib;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf", &ia, &ib);
        input[i] = {ia, ib};
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        if(i == u) continue;
        else{
            double tmp = (input[i].first - input[u].first) * (input[i].first - input[u].first);
            tmp += (input[i].second - input[u].second) * (input[i].second - input[u].second);
            edge_vec.push_back({i, u, sqrt(tmp)});
        }
    std::sort(edge_vec.begin(), edge_vec.end(), cmp);
    for(int i = 0; i < 105; ++i)
        set[i] = i;
    for(int i = 0; i < edge_vec.size(); ++i){
        if(findSet(edge_vec[i].start) != findSet(edge_vec[i].last)){
            unionSet(findSet(edge_vec[i].start), findSet(edge_vec[i].last));
            ans += edge_vec[i].weight;
            ++selected;
        }
        if(selected == N - 1) break;
    }
    printf("%.2lf", ans);
    return 0;
}
