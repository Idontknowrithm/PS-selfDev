// 1. 숫자만큼 왼쪽으로 간 사람과 친구
// 2. A와 B가 친구고 B와 C가 친구면 A와 C도 친구다
// -> 그룹 형성
// 이때 형성된 그룹의 수는?
// 그룹 형성이라는 점에서 union find 생각
// 그냥 알고리즘 단순 적용

#include<iostream>
#include<cstring>

const int MAX = 100005;
int T, N, people, set[MAX], sieve[MAX];

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
    scanf("%d", &T);
    for(int z = 1; z <= T; ++z){
        memset(sieve, -1, sizeof(sieve));
        for(int i = 0; i < MAX; ++i)
            set[i] = i;
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d", &people);
            if(i + people < N){
                union_set(find_set(i), find_set(i + people));
            }
        }
            
        for(int i = 0; i < N; ++i)
            sieve[find_set(i)] = 1;
        
        int ans = 0;

        for(int i = 0; i < N; ++i)
            ans += (sieve[i] == 1) ? 1 : 0;
        
        printf("Case #%d\n%d\n", z, ans);
    }
    return 0;
}
