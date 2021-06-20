// findset 할 때 루트로 거슬러 올라갈 때 거쳐진 모든 값을 루트의 값으로 바꾸면
// 효율이 더 

#include<iostream>
#include<algorithm>

int G, P, ans, set[100005];

int findSet(int num){
    if (set[num]==num)
        return num;
    int parent = findSet(set[num]);
    set[num] = parent;
    return parent;
}
void unionSet(int first, int second){
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}

int main() {
    int input, i;
    scanf("%d\n%d", &G, &P);
    for(i = 0; i <= G; ++i)
        set[i] = i;
    for(i = 0; i < P; ++i){
        scanf("%d", &input);
        int cur = findSet(input);
        if(cur == 0) break;
        unionSet(findSet(cur - 1), findSet(cur));
        ++ans;
    }
    for(; i < P - 1; ++i){
        scanf("%d", &input);
    }
    printf("%d", ans);
    return 0;
}
