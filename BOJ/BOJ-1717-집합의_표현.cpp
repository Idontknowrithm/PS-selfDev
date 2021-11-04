#include<iostream>
#include<algorithm>

int N, M, set[1000005];

int find_set(int num){
    if (set[num]==num)
        return num;
    int parent = find_set(set[num]);
    set[num] = parent;
    return parent;
}
void union_set(int first, int second){
    int temp;
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i <= N; ++i)
        set[i] = i;

    for(int i = 0; i < M; ++i){
        int query, a, b;
        scanf("%d %d %d", &query, &a, &b);
        if(query)
            printf("%s\n", (find_set(a) == find_set(b)) ? "YES" : "NO");
        else 
            union_set(find_set(a), find_set(b));
    }
    return 0;
}
