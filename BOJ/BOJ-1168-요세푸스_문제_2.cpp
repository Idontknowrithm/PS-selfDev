// 세그트리 응용 - 구간합 구하는 세그를 원래의 용도와 다르게 응용한다
// 문제에서는 수열이 있는데, 규칙에 맞게 수열에 있는 임의의 수를 제거하고, 그
// 제거한 수열에서 다시 규칙에 맞게 수열에 있는 임의의 수를 제거하는 것을 반복
// 한다. 이때 문제의 관건은 수열 중 임의의(수열 중간의 무작위의) 수를 제거한 
// 다음 수열을 정리하여 두는 것이다. 예를 들어
// 1 2 3 4 5 6       이 있을 때, 4를 뺀다면 일반 배열 같은 경우에는
// 1 2 X 4 5 6       이렇게 X로 사라진 수에 대해서 쓰레기가 남게 된다
//                   다시 말해 4, 5, 6의 인덱스는 그대로이게 된다

// 하지만 이 문제에서 원하는 것은 다음과 같다
// 1 2 3 4 5 6       여기서 4를 제거했을 때,
// 1 2 3 5 6         이렇게 된다면 이 수열에서 쉽게 모듈로 써서 다음 숫자를 제거할 수 있다

// 위와 같은 구현을 세그를 써서 어떻게 했냐면, 세그의 리프노드(arr에 해당)의 값을 모두 1로
// 만들어준다. 7개의 원소를 예로 들자면 다음과 같다
// 7
// 4       3
// 2   2   2   1
// 1 1 1 1 1 1 0 0     (0은 없는 수)

// 여기에서 규칙대로 원소를 없애면서, 없앴다는 표시를 -1로 한다

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long unit;

// 트리의 루트: 1, arr 시작: 0
// 트리의 크기: 2^k > N인 최소 k에 대해
//              2^k * 2 (N * 4 해도 됨)
unit N, K, h, idx = 0, tree_size;
std::vector<unit> arr, tree;


unit init(unit root_idx, unit start, unit end){
    if (start == end)
        return tree[root_idx] = arr[start];
 
    unit mid = (start + end) / 2, next = root_idx << 1;

    // 이 부분이 어떻게 됨에 따라서 쿼리 종류가 바뀌어짐
    return tree[root_idx] = init(next, start, mid) + init(next + 1, mid + 1, end); 
}
unit idx_finder(unit root_idx, unit start, unit end, unit arr_idx){
    unit mid = (start + end) / 2;

    tree[root_idx] -= 1;
    if(start == end) return start + 1;

    if(tree[root_idx * 2] > arr_idx)
        return idx_finder(root_idx * 2, start, mid, arr_idx);
    else 
        return idx_finder(root_idx * 2 + 1, mid + 1, end, arr_idx - tree[root_idx * 2]);
    
}

int main() {
    scanf("%lld %lld", &N, &K);

    h = (unit)std::ceil(log2(N));
    tree_size = (1 << (h + 1));
    tree.resize(tree_size, 0);

    for(int i = 0; i < N; ++i)
        arr.push_back(1);
    
    init(1, 0, N - 1);

    printf("<");
    idx = K - 1;
    printf("%lld", idx_finder(1, 0, N - 1, idx));
    while(tree[1]){
        idx = (idx + K - 1) % tree[1];
        printf(", %lld", idx_finder(1, 0, N - 1, idx));
    }
    printf(">");

    return 0;
}
