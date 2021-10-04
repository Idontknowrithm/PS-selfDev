#include<iostream>
#include<vector>
#include<cstring>

const int MAX = 100005;
int N, R, Q, cache[MAX];
std::vector<int> tree[MAX];

int DP(int root, int prev){
    int &ret = cache[root];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = 0; i < tree[root].size(); ++i)
        if(tree[root][i] != prev)
            ret += DP(tree[root][i], root);
    
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &R, &Q);
    for(int i = 0; i < N - 1; ++i){
        int U, V;
        scanf("%d %d", &U, &V);
        tree[U].push_back(V);
        tree[V].push_back(U);
    }
    memset(cache, -1, sizeof(cache));
    DP(R, -1);
    for(int i = 0; i < Q; ++i){
        int query;
        scanf("%d", &query);
        printf("%d\n", cache[query]);
    }
    return 0;
}
