// 상황에 따라 트리 업데이트 및 쿼리 수행을 탑다운으로 할 지, 바텀업으로 할 지
// 판단해봐야할 듯. 바텀업으로 접근하면 쉽게 풀 수 있었을 것을 탑다운으로 생각하다
// 0의 영향력을 너무 어렵게 받아들여 문제 풀이에 어려움이 있었다

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

typedef long long unit;

// 트리의 루트: 1, arr 시작: 0
// 트리의 크기: 2^k > N인 최소 k에 대해
//              2^k * 2 (N * 4 해도 됨)
const unit MOD = 1000000007;
unit N, M, K, h, tree_size;
std::vector<unit> arr, tree;


unit init(unit root_idx, unit start, unit end){
    if (start == end)
        return tree[root_idx] = arr[start];
 
    unit mid = (start + end) / 2, next = root_idx << 1;

    // 이 부분이 어떻게 됨에 따라서 쿼리 종류가 바뀌어짐
    tree[root_idx] = (init(next, start, mid) % MOD) * (init(next + 1, mid + 1, end) % MOD); 
    tree[root_idx] %= MOD;
    return tree[root_idx];
}
// arr_idx를 diff 만큼 값을 바꾸어준다. diff는 차이로, diff 자체로 바꾸는 게
// 아니라 diff 만큼 값을 더해주는 것이다. 따라서 기존 값과 바꿀 값의 차를
// diff 값으로 넣어줘야 한다
void update(unit root_idx, unit start, unit end, unit arr_idx, unit val){
    if(start > arr_idx || end < arr_idx)
        return;

    if(start == end){
        tree[root_idx] = val;
        return;
    }
    
    unit mid = (start + end) / 2, next = root_idx << 1;
    update(next, start, mid, arr_idx, val);
    update(next + 1, mid + 1, end, arr_idx, val);

    tree[root_idx] = (tree[next] * tree[next + 1]) % MOD;
}
unit times(unit root_idx, unit start, unit end, unit l, unit r){
    if(l > end || r < start)
        return 1;
    if(l <= start && r >= end)
        return tree[root_idx];
    unit mid = (start + end) / 2, next = root_idx << 1;
    return ((times(next, start, mid, l, r) % MOD) * 
           (times(next + 1, mid + 1, end, l, r) % MOD)) % MOD;
}

int main() {
    scanf("%lld %lld %lld", &N, &M, &K);

    h = (unit)std::ceil(log2(N));
    tree_size = (1 << (h + 1));
    tree.resize(tree_size, 1);

    for(int i = 0; i < N; ++i){
        unit input;
        scanf("%lld", &input);
        arr.push_back(input);
    }
    init(1, 0, N - 1);

    for(int i = 0; i < M + K; ++i){
        unit query, a, b;
        scanf("%lld %lld %lld", &query, &a, &b);
        if(query == 1){
            update(1, 0, N - 1, a - 1, b);
            arr[a - 1] = b;
        }
        else
            printf("%lld\n", times(1, 0, N - 1, a - 1, b - 1));
    }
    return 0;
}
