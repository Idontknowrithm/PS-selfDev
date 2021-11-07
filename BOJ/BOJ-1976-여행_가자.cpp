#include<iostream>

int N, M, set[205];

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
    for(int i = 0; i < 205; ++i)
        set[i] = i;
    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u){
        int connect;
        scanf("%d", &connect);
        if(connect)
            union_set(find_set(i + 1), find_set(u + 1));
    }
    int input, group;
    for(int i = 0; i < M; ++i){
        if(!i){
            scanf("%d", &input);
            group = find_set(input);
        }
        else{
            scanf("%d", &input);
            if(group != find_set(input)){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
