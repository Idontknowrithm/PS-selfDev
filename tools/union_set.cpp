// 갱신 자체가 빠른 findset
int renew_find_set(int val){
    while(val != set[val])
        val = set[val];
    return val;
}
// 전처리로 쿼리가 많을 때 빠른 findset
int query_find_set(int num){
    if (uni_set[num]==num)
        return num;
    int parent = query_find_set(uni_set[num]);
    uni_set[num] = parent;
    return parent;
}
// 일반 합집합
void union_set(int first, int second){
    int temp;
    if(first > second)
        std::swap(first, second);
    else if(first == second) return;
    set[second] = first;
}
// 집합의 크기를 구할 때 합집합
void union_set_size(int first, int second){
    if(first == second) return;

    if(set_size[first] < set_size[second])
        std::swap(first, second);

    uni_set[second] = first;
    set_size[first] += set_size[second];
    set_size[second] = 0;
}
