// 함수화된 세그트리(구간합 쿼리)

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long unit;

// 트리의 루트: 1, arr 시작: 0
// 트리의 크기: 2^k > N인 최소 k에 대해
//              2^k * 2 (N * 4 해도 됨)
unit N, h, tree_size;
std::vector<unit> arr, tree;


unit init(unit root_idx, unit start, unit end){
    if (start == end)
        return tree[root_idx] = arr[start];
 
    unit mid = (start + end) / 2, next = root_idx << 1;

    // 이 부분이 어떻게 됨에 따라서 쿼리 종류가 바뀌어짐
    return tree[root_idx] = init(next, start, mid) + init(next + 1, mid + 1, end); 
}
// arr_idx를 diff 만큼 값을 바꾸어준다. diff는 차이로, diff 자체로 바꾸는 게
// 아니라 diff 만큼 값을 더해주는 것이다. 따라서 기존 값과 바꿀 값의 차를
// diff 값으로 넣어줘야 한다
void update(unit root_idx, unit start, unit end, unit arr_idx, unit diff){
    if(start > arr_idx || end < arr_idx)
        return;
    tree[root_idx] += diff;

    if(start != end){
        unit mid = (start + end) / 2, next = root_idx << 1;
        update(next, start, mid, arr_idx, diff);
        update(next + 1, mid + 1, end, arr_idx, diff);
    }
}
unit sum(unit root_idx, unit start, unit end, unit l, unit r){
    if(l > end || r < start)
        return 0;
    if(l <= start && r >= end)
        return tree[root_idx];
    unit mid = (start + end) / 2, next = root_idx << 1;
    return sum(next, start, mid, l, r) + 
           sum(next + 1, mid + 1, end, l, r);
}

int main() {
    scanf("%lld", &N);

    h = (unit)std::ceil(log2(N));
    tree_size = (1 << (h + 1));
    tree.resize(tree_size, 0);
}
