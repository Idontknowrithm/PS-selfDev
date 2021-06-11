// union find 자료구조 사용 시 집합에 접근할 때 i 말고 find_set(i)로 접근을 해야한다

#include<iostream>
#include<vector>
#include<algorithm>

int N, M, ans, set[500005];

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
    int ia, ib;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        set[i] = i;
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &ia, &ib);
        if(ans){
            continue;
        }
        else if(find_set(ia) == find_set(ib)){
            ans = i + 1;
        }
        else{
            union_set(find_set(ia), find_set(ib)); // 여기...
        }
    }
    printf("%d", ans);
    return 0;
}
