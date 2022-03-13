#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
typedef int unit;

// 트리의 루트: 1, arr 시작: 0
// 트리의 크기: 2^k > N인 최소 k에 대해
//              2^k * 2 (N * 4 해도 됨)
unit T, N, K, h, tree_size;
std::vector<unit> arr, tree, tree_sum, tree_origin;


unit init_rmq(unit root_idx, unit start, unit end){
    if (start == end)
        return tree[root_idx] = arr[start];
 
    unit mid = (start + end) / 2, next = root_idx << 1;

    return tree[root_idx] = std::max(init_rmq(next, start, mid), 
                                     init_rmq(next + 1, mid + 1, end));
}
unit update_rmq(unit root_idx, unit start, unit end, unit arr_idx, unit val){
    if(start > arr_idx || end < arr_idx)
        return tree[root_idx];
    if(start == end){
        tree[root_idx] = val;
        arr[arr_idx] = val;
        return val;
    }
    if(start != end){
        unit mid = (start + end) / 2, next = root_idx << 1;

        tree[root_idx] = std::max(update_rmq(next, start, mid, arr_idx, val),
                                  update_rmq(next + 1, mid + 1, end, arr_idx, val));
    }
}
unit query_rmq(unit root_idx, unit start, unit end, unit l, unit r){
    if(l > end || r < start)
        return -1;
    if(l <= start && r >= end)
        return tree[root_idx];
    unit mid = (start + end) / 2, next = root_idx << 1;

    return std::max(query_rmq(next, start, mid, l, r),
                    query_rmq(next + 1, mid + 1, end, l, r));
}
unit init_sum(unit root_idx, unit start, unit end, std::vector<unit> &t){
    if (start == end)
        return t[root_idx] = arr[start];
 
    unit mid = (start + end) / 2, next = root_idx << 1;

    return t[root_idx] = init_sum(next, start, mid, t) + init_sum(next + 1, mid + 1, end, t); 
}
void update_sum(unit root_idx, unit start, unit end, unit arr_idx, unit diff){
    if(start > arr_idx || end < arr_idx)
        return;
    tree_sum[root_idx] += diff;

    if(start != end){
        unit mid = (start + end) / 2, next = root_idx << 1;
        update_sum(next, start, mid, arr_idx, diff);
        update_sum(next + 1, mid + 1, end, arr_idx, diff);
    }
}
unit sum(unit root_idx, unit start, unit end, unit l, unit r, std::vector<unit> &t){
    if(l > end || r < start)
        return 0;
    if(l <= start && r >= end)
        return t[root_idx];
    unit mid = (start + end) / 2, next = root_idx << 1;
    
    return sum(next, start, mid, l, r, t) + 
           sum(next + 1, mid + 1, end, l, r, t);
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d %d", &N, &K);

        h = (unit)std::ceil(log2(N));
        tree_size = (1 << (h + 1));
        arr.clear();
        tree.clear();
        tree_sum.clear();
        tree_origin.clear();
        tree.resize(tree_size, 0);
        tree_sum.resize(tree_size, 0);
        tree_origin.resize(tree_size, 0);

        for(int i = 0; i < N; ++i)
            arr.push_back(i);
        
        init_rmq(1, 0, N - 1);
        init_sum(1, 0, N - 1, tree_sum);
        init_sum(1, 0, N - 1, tree_origin);

        for(int i = 0; i < K; ++i){
            int q, a, b;
             
            scanf("%d %d %d", &q, &a, &b);
            if(q){
                int changed = sum(1, 0, N - 1, a, b, tree_sum);
                int origin = sum(1, 0, N - 1, a, b, tree_origin);
                int max = query_rmq(1, 0, N - 1, a, b);

                if(changed != origin)
                    puts("NO");
                else if(max > b)
                    puts("NO");
                else 
                    puts("YES");

                // printf("max : %d\n", max);
                // printf("change: %d\norigin: %d\n", changed, origin);
            }
            else{
                int val1 = arr[a], val2 = arr[b];

                update_rmq(1, 0, N - 1, a, val2);
                update_rmq(1, 0, N - 1, b, val1);
                update_sum(1, 0, N - 1, a, val2 - val1);
                update_sum(1, 0, N - 1, b, val1 - val2);
                // printf("updated: ");
                // for(int i = 0; i < N; ++i)
                //     printf("%d ", arr[i]);
                // puts("");
            }
        }
    }
    return 0;
}
