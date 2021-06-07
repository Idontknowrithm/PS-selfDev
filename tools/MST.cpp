#include<iostream>
#include<algorithm>
#include<vector>

typedef struct{
    int start, last;
    long long weight;
}edge;

const int vertex_max = 10005;
int N, M, selected, set[vertex_max];
std::vector<edge> edge_vec;

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
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main(){
    int s, l, w;
    long long answer = 0;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; ++i)
        set[i + 1] = i + 1;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %lld", &s, &l, &w);
        edge_vec.push_back({s, l, w});
    }
    
    std::sort(edge_vec.begin(), edge_vec.end(), cmp);

    for(int i = 0; i < M; ++i){
        if(findSet(edge_vec[i].start) != findSet(edge_vec[i].last)){
            unionSet(findSet(edge_vec[i].start), findSet(edge_vec[i].last));
            answer += edge_vec[i].weight;
            ++selected;
        }
        if(selected == N - 1) break;
    }
    printf("%lld", answer);
    return 0;
}
