// numeric_limits 를 사용하려면 limits 헤더를 포함 시켜야 

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#define ll long long

typedef int unit;

const unit unit_max = std::numeric_limits<unit>::max();

int N, M;
std::vector<int> arr;

class segment_tree{
    unit N;
    std::vector<unit> seq;
    public:
        segment_tree(const std::vector<unit> &arr){
            N = arr.size() - 1;
            seq.resize(N * 4);
            base();
            init(arr, 1, N, 1);
        }
        void base(){
            for(int i = 0; i < N * 4; ++i)
                seq[i] = unit_max;
        }
        unit init(const std::vector<unit> &arr, unit left, unit right, unit root){
            if(left == right){
              seq[root] = arr[left];
              return seq[root];
            }
            unit mid = (left + right) / 2;
            unit left_min = init(arr, left, mid, root * 2);
            unit right_min = init(arr, mid + 1, right, root * 2 + 1);
            seq[root] = std::min(left_min, right_min);
            return seq[root];
        }
        unit query(unit left, unit right, unit root, unit this_left, unit this_right){
            if(right < this_left || this_right < left)
                return unit_max;
            if(left <= this_left && this_right <= right)
                return seq[root];
            
            unit mid = (this_left + this_right) / 2;
            return std::min(query(left, right, root * 2, this_left, mid),
                            query(left, right, root * 2 + 1, mid + 1, this_right));
        }
};

int main() {
    int input, a, b;
    scanf("%d %d", &N, &M);
    arr.push_back(1000000500);
    for(int i = 0; i < N; ++i){
    scanf("%d", &input);
    arr.push_back(input);
    }

    segment_tree segtree(arr);
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &a, &b);
        printf("%d\n", segtree.query(a, b, 1, 1, N));
    }
    return 0;
}
