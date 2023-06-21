#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
#define pp std::pair<ll, ll>

// 트리의 루트: 1, arr 시작: 0
// 트리의 크기: 2^k > N인 최소 k에 대해
//              2^k * 2 (N * 4 해도 됨)
const ll MAX = 100005, INF = 2500000000;
ll N, h, tree_size, tmp;
std::vector<pp> arr, tree; // val, idx

pp init(ll root_idx, ll start, ll end){
    if (start == end)
        return tree[root_idx] = arr[start];
 
    ll mid = (start + end) / 2, next = root_idx << 1;

    return tree[root_idx] = std::min(init(next, start, mid), init(next + 1, mid + 1, end)); 
}
pp query(ll root_idx, ll start, ll end, ll l, ll r){
    if(l > end || r < start)
        return {INF, INF};
    if(l <= start && r >= end)
        return tree[root_idx];
    ll mid = (start + end) / 2, next = root_idx << 1;
    return std::min(query(next, start, mid, l, r), query(next + 1, mid + 1, end, l, r));
}

ll dnq(pp div, ll left, ll right){
    if(left > right)
        return 0;
    else if(left == right)
        return arr[left].first;

    pp new_div;
    ll ret = div.first * (right - left + 1);
    
    new_div = query(1, 0, N - 1, left, div.second - 1);
    ret = std::max(ret, dnq(new_div, left, div.second - 1));
    new_div = query(1, 0, N - 1, div.second + 1, right);
    ret = std::max(ret, dnq(new_div, div.second + 1, right));

    return ret;
}

int main() {
    scanf("%lld", &N);

    h = (ll)std::ceil(log2(N));
    tree_size = (1 << (h + 1));
    tree.resize(tree_size, {-1, -1});

    for(ll i = 0; i < N; ++i){
        ll input;
        scanf("%lld", &input);
        arr.push_back({input, i});
    }
    init(1, 0, N - 1);

    pp div = query(1, 0, N - 1, 0, N - 1);

    printf("%lld\n", dnq(div, 0, N - 1));

    return 0;
}
